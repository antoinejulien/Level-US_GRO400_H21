/*
Level-US project
Class to use the OpenCR IMU
@author Antoine Julien (Level-US team)
@version 1.0 28/03/2021
*/

#include "OpenCR_IMU.h"

/*
 * OpenCR_IMU constructor
 * @Param: IMUangles array containing the IMU angles
 */
 
OpenCR_IMU::OpenCR_IMU()
{
	//IMU.begin();
	imu_time = 0;
	
	//OpenCR IMU calibration
	IMU.SEN.acc_cali_start();
	
	while( IMU.SEN.acc_cali_get_done() == false )
	{
		IMU.update();
	}

	//WARNING: There is a small delay before the IMU calibrates 
	//accordingly. First few values might be wrong.
	OpenCR_IMU::updateAngles();
}

/*
 * Update the current angles stored in the array
 */
int OpenCR_IMU::updateAngles()
{
	if( (millis()-tTime[0]) >= 500 )
	{
		tTime[0] = millis();
	}

	tTime[2] = micros();
	
	if( IMU.update() > 0 ) 
	{
		imu_time = micros()-tTime[2];
	}

	if( (millis()-tTime[1]) >= 50 )
	{
		tTime[1] = millis();

		IMUangles[0] = IMU.rpy[0];
		IMUangles[1] = IMU.rpy[1];
		IMUangles[2] = IMU.rpy[2];
	}

	return 0;
}

/*
 * Getter for the IMU angles
 * @Return: array of floats containing the IMU angles
 */
float* OpenCR_IMU::getAngles()
{
	return IMUangles;
}