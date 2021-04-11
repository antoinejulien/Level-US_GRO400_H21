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
#define DXL_ID_2    202
#define DXL_ID_3    209
DynamixelWorkbench dxl_wb;

int initialMotorsPos = 180; //Angles go from 200 (which will be 0 -20 from the horizontal)
                            //and 90 (which is the vertical)
int motorSpeed = 100;
uint8_t motor1 = DXL_ID_1;
uint8_t motor2 = DXL_ID_2;
uint8_t motor3 = DXL_ID_3;

/* OpenCR IMU variables */
OpenCR_IMU OCRimu_;
float OCRimu_angles[3];

/* MPU6050 variables */
MPU6050 mpu(Wire);
float MPU6050angles[3];

/*-------------------------- Function headers -------------------------------*/
void moveMotors(float motor1_angle, float motor2_angle, float motor3_angle);
void getMPU6050angles(float angles[3]);
int32_t degToInt(float angle);

/*------------------------------- Functions ---------------------------------*/
/*
 * Moves the motors to the desired angle
 * @Param: motor1_angle motor 1 desired angle
 *         motor2_angle motor 2 desired angle
 *         motor3_angle motor 3 desired angle
 */
void moveMotors(float motor1_angle, float motor2_angle, float motor3_angle)
{
  dxl_wb.goalPosition(motor1, degToInt(motor1_angle));
  dxl_wb.goalPosition(motor2, degToInt(motor2_angle));
  dxl_wb.goalPosition(motor3, degToInt(motor3_angle));
}

/*
 * Get the angles from the MPU6050
 * @Param: angles array of float containing the angles
 */
void getMPU6050angles(float angles[3])
{
  angles[0] = mpu.getAngleX();
  angles[1] = mpu.getAngleY();
  angles[2] = mpu.getAngleZ();
}

/*
 * Transfer float angles into int angles
 * @Param: angle angle to transform
 * @Return: return the angle in int32_t
 */
int32_t degToInt(float angle)
{
  return (int32_t)(angle*4097/360);
}
/*-------------------------------- Setup ------------------------------------*/
void setup() 
{
  Serial.setTimeout(5);
  Serial.begin(115200);

  // All commented code are for the second IMU.
  // Uncommet if the MPU6050 is being used. Code
  // will return current angles.
  //  Wire.begin();
  //  
  //  byte status = mpu.begin();
  //  Serial.print(F("MPU6050 status: "));
  //  Serial.println(status);
  //
  //  //Stop everything if could not connect to MPU6050
  //  while(status!=0){ }
  //  
  //  Serial.println(F("Calculating offsets, do not move MPU6050"));
  //  delay(1000);
  //
  //  //Uncomment this line if the MPU6050 is mounted upside-down
  //  mpu.upsideDownMounting = true; 
  //
  //  //MPU6050 gyroscope and accelerometer
  //  mpu.calcOffsets();
  //  Serial.println("Done!\n");

  OCRimu_.initIMU();

  const char *log;
  bool result = false;
  uint16_t model_number = 0;
  float Angle;

  result = dxl_wb.init(DEVICE_NAME, MOTORS_BAUDRATE, &log);

  //Ping motors to make sure they are available
  dxl_wb.ping(motor1, &model_number, &log);
  dxl_wb.ping(motor2, &model_number, &log);
  dxl_wb.ping(motor3, &model_number, &log);

  //Switch motors movement to joint mode
  dxl_wb.jointMode(motor1, motorSpeed, 0, &log);
  dxl_wb.jointMode(motor2, motorSpeed, 0, &log);
  dxl_wb.jointMode(motor3, motorSpeed, 0, &log);

  //Activate torque on the motors
  dxl_wb.torqueOn(motor1);
  dxl_wb.torqueOn(motor2);
  dxl_wb.torqueOn(motor3);

  //Set an initial motor angle
  moveMotors(initialMotorsPos, initialMotorsPos, initialMotorsPos);

  //Delay to let the motors move to the initial position
  delay(2000);
}

/*--------------------------------- Loop ------------------------------------*/
void loop() 
{   
  float commands[3];
  
  OCRimu_.updateAngles();
  //mpu.update();

  if(Serial.available() > 0) 
  {
    if(serial.serialDecoder(commands) == 0)
    {
      moveMotors(commands[0], commands[1], commands[2]);
    }
    else
    {
      //Update IMU angles before sending the values
      OCRimu_.updateAngles();
      OCRimu_.getAngles(OCRimu_angles);

      //mpu.update();
      //getMPU6050angles(MPU6050angles);
      
      serial.serialEncoder(OCRimu_angles);   
    }
  }
}
