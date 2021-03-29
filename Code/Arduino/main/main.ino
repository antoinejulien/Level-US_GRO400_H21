/************************************
File: OpenCR program for self leveling platform. 
Authors: Level-US team
GitHub: https://github.com/antoinejulien/Level-US_GRO400_H21
Creation date: 15-03-2021
Description: This program sends values from the
IMUs to the raspberry Pi through serial communication
and receives the desired operation mode and the motors
desired angles.
Requirements: This code requires the OpenCR librairies.
************************************/

/*------------------------------ Librairies ---------------------------------*/
#include <DynamixelWorkbench.h>
#include <IMU.h>
#include <math.h>
#include <SerialCommunication.h>

/*--------------------------- Global variables ------------------------------*/
#if defined(__OPENCM904__)
  #define DEVICE_NAME "3"
#elif defined(__OPENCR__)
  #define DEVICE_NAME ""
#endif

SerialCommunication serial;

/* Motors variables */
#define MOTORS_BAUDRATE  57600
#define DXL_ID_1    215
#define DXL_ID_2    209
#define DXL_ID_3    202
DynamixelWorkbench dxl_wb;

int initialMotorsPos = 0;
int motorSpeed = 50;
uint8_t motorsID[2];

/* OpenCR IMU variables */
cIMU IMU;
static uint32_t tTime[3];
static uint32_t imu_time = 0;
float IMUangles[2];

/*-------------------------- Function headers -------------------------------*/
/****** Function headers ******/
void moveMotors(float motor1_angle, float motor2_angle, float motor3_angle);
void updateOpenCR_IMU_Angles(float angles[2]);

/*-------------------------------- Setup ------------------------------------*/
void setup() 
{
  Serial.setTimeout(50);
  Serial.begin(115200);
  IMU.begin();

  const char *log;
  bool result = false;
  uint16_t model_number = 0;
  float Angle;

  //DXL motors initialization
  motorsID[0] = DXL_ID_1;
  motorsID[1] = DXL_ID_2;
  motorsID[2] = DXL_ID_3;

  result = dxl_wb.init(DEVICE_NAME, MOTORS_BAUDRATE, &log);

  for(int i = 0; i < 2; i++)
  {
    dxl_wb.ping(motorsID[i], &model_number, &log);
  }
  
  for(int i = 0; i < 2; i++)
  {
    result = dxl_wb.jointMode(motorsID[i], motorSpeed, 0, &log);
    
    if (result == false)
    {
      //Failed to change to joint mode
    }
    else
    {
      //Succeed to change to joint mode
      //Setting motors to initial position 
      Angle = initialMotorsPos*2*PI/360;
      moveMotors(Angle, Angle, Angle);
    }
  }

  //Delay to let the motors move to the initial position
  delay(2000);

  //OpenCR IMU calibration
  IMU.SEN.acc_cali_start();
  while( IMU.SEN.acc_cali_get_done() == false )
  {
    IMU.update();
  }

  //WARNING: There is a small delay before the IMU calibrates 
  //accordingly. First few values might be wrong.
  updateOpenCR_IMU_Angles(IMUangles);
}

/*--------------------------------- Loop ------------------------------------*/
void loop() 
{   
  int commands[3];
  
  updateOpenCR_IMU_Angles(IMUangles);
  
  if (Serial.available() > 0) 
  { 
    serial.serialDecoder(commands);
    //moveMotors(commands[0], commands[1], commands[2]);

    //Update IMU angles before sending the values
    updateOpenCR_IMU_Angles(IMUangles);
    
    serial.serialEncoder(IMUangles);

    
  }
}

/*------------------------------- Functions ---------------------------------*/
/*
 * Moves the motors to the desired angle
 * @Param: motor1_angle motor 1 desired angle
 *         motor2_angle motor 2 desired angle
 *         motor3_angle motor 3 desired angle
 */
void moveMotors(float motor1_angle, float motor2_angle, float motor3_angle)
{
  dxl_wb.goalPosition(motorsID[0], motor1_angle);
  dxl_wb.goalPosition(motorsID[1], motor2_angle);
  dxl_wb.goalPosition(motorsID[2], motor3_angle);
}

/*
 * Get the OpenCR IMU angles
 * @Param: angles array of floats of the OpenCR IMU angles 
 */
void updateOpenCR_IMU_Angles(float IMUangles[2])
{
  if( (millis()-tTime[0]) >= 500 )
  {
    tTime[0] = millis();
  }

  tTime[2] = micros();
  if( IMU.update() > 0 ) imu_time = micros()-tTime[2];

  if( (millis()-tTime[1]) >= 50 )
  {
    tTime[1] = millis();
    
    IMUangles[0] = IMU.rpy[0];
    IMUangles[1] = IMU.rpy[1];
    IMUangles[2] = IMU.rpy[2];
  }
}
