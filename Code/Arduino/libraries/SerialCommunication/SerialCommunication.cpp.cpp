/*
Level-US project
Class to use serial communication between OpenCR
and the python code.
@author Antoine Julien (Level-US team)
@version 1.0 28/03/2021
*/

#include "SerialCommunication.h"

SerialCommunication::SerialCommunication()
{
}

/*
 * Encodes IMU values to send to the python script
 * @Param: IMUangles angles of the OpenCR IMU
 * @Return: always returns 0
 */
 
int SerialCommunication::serialEncoder(float IMUangles[2])
{
	Serial.print(IMUangles[0]);
	Serial.print(" ");
	Serial.print(IMUangles[1]);
	Serial.print(" ");
	Serial.print(IMUangles[2]);
	Serial.print("\n");
	
	return 0;
}

/*
 * Decodes incoming angle values sent from the python code in bytes 
 * and stores it into the commands array.
 * @Param: commands int array that stores next motor angles commands
 * @Return: always returns 0
 */
 
int SerialCommunication::serialDecoder(int commands[3])
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