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
 * @Return: always returns 0
 */
 
int SerialCommunication::serialEncoder(float OpenCRangles[2])
{
	Serial.print(OpenCRangles[0]);
	Serial.print(" ");
	Serial.print(OpenCRangles[1]);
	Serial.print("\n");
	
	return 0;
}

/*
 * Decodes incoming angle values sent from the python code in bytes 
 * and stores it into the commands array.
 * @Param: commands int array that stores next motor angles commands
 * @Return: returns the bytes corresponding to the operation mode sent by the python code
 *          - 0 means that the values are motor angles 
 *          - anything else means that python code is ready to receive IMUs values
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
			commands[i] = Serial.parseFloat(); 
			//commands[i] = Serial.readBytes(inputBytes, 2);
		}
		return 0;
	}
	
	return 1;
}