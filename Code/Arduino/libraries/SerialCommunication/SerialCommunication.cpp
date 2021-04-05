/*
Level-US project
Class to use serial communication between OpenCR
and the python code.
@author Antoine Julien (Level-US team)
@version 1.0 28/03/2021
*/

#include "SerialCommunication.h"

/*
 * Encodes IMU values to send to the python script
 * @Param: OpenCRangles angles of the OpenCR IMU
 * 		   MPU6050angleX X angle of the MPU6050 
 *         MPU6050angleY Y angle of the MPU6050 
 * @Return: always returns 0
 */
 
int SerialCommunication::serialEncoder(float OpenCRangles[2], float MPU6050angles[2])
{
	Serial.print(OpenCRangles[0]);
	Serial.print(" ");
	Serial.print(OpenCRangles[1]);
	Serial.print(" ");
	Serial.print(OpenCRangles[2]);
	Serial.print(" ");
	
	Serial.print(MPU6050angles[0]);
	Serial.print(" ");
	Serial.print(MPU6050angles[1]);
	Serial.print(" ");
	Serial.print(MPU6050angles[2]);
	Serial.print("\n");
	
	return 0;
}

/*
 * Decodes incoming angle values sent from the python code in bytes 
 * and stores it into the commands array.
 * @Param: commands int array that stores next motor angles commands
 * @Return: always returns 0
 */
 
int SerialCommunication::serialDecoder(float commands[3])
{
	byte inputBytes[2];
	Serial.readBytes(inputBytes, 2);

	//Fist bytes represent the operating mode
	if(inputBytes[0] == 0)
	{
		for(int i = 0; i < 3; i++)
		{
		  Serial.readBytes(inputBytes, 2);
		  commands[i] = inputBytes[0];
		}
	}
	
	return 0;
}