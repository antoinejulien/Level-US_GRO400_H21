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
#include <math.h>
#include <SerialCommunication.h>
#include <OpenCR_IMU.h>
#include "Wire.h"
#include <MPU6050_light.h>

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
uint8_t motorsID[3];

/* OpenCR IMU variables */
OpenCR_IMU OCRimu_;
float OCRimu_angles[3];

/* MPU6050 variables */
MPU6050 mpu(Wire);
float MPU6050angles[3];

/*-------------------------- Function headers -------------------------------*/
void moveMotors(float motor1_angle, float motor2_angle, float motor3_angle);
void getMPU6050angles(float angles[3]);

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

void getMPU6050angles(float angles[3])
{
  angles[0] = mpu.getAngleX();
  angles[1] = mpu.getAngleY();
  angles[2] = mpu.getAngleZ();
}
/*-------------------------------- Setup ------------------------------------*/
void setup() 
{
  Serial.setTimeout(50);
  Serial.begin(115200);

  Wire.begin();
  
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);

  //Stop everything if could not connect to MPU6050
  while(status!=0){ }
  
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);

  //Uncomment this line if the MPU6050 is mounted upside-down
  mpu.upsideDownMounting = true; 

  //MPU6050 gyroscope and accelerometer
  mpu.calcOffsets();
  Serial.println("Done!\n");

  OCRimu_.initIMU();

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
}

/*--------------------------------- Loop ------------------------------------*/
void loop() 
{   
  float commands[3];
  
  OCRimu_.updateAngles();
  mpu.update();

  if(Serial.available() > 0) 
  {
    serial.serialDecoder(commands);
    //moveMotors(commands[0], commands[1], commands[2]);

    //Update IMU angles before sending the values
    OCRimu_.updateAngles();
    OCRimu_.getAngles(OCRimu_angles);

    mpu.update();
    getMPU6050angles(MPU6050angles);
    
    serial.serialEncoder(OCRimu_angles, MPU6050angles);   
  }
}
