/*
Level-US project
Class to use the OpenCR IMU
@author Antoine Julien (Level-US team)
@version 1.0 28/03/2021
*/

#ifndef OpenCR_IMU_H_
#define OpenCR_IMU_H_

#include <Arduino.h>
#include <IMU.h>
#include <cstdint>

class OpenCR_IMU
{
    public:
        OpenCR_IMU();
		
		int initIMU();
		int updateAngles();
		int getAngles(float inputArray[3]);
		
	private:
		cIMU IMU;
		uint32_t tTime[3];
		uint32_t imu_time;
		float IMUangles[3];
};

#endif //OpenCR_IMU_H_