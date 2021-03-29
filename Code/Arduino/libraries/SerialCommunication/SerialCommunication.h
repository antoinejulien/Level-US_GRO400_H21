/*
Level-US project
Class to use serial communication between OpenCR
and the python code.
@author Antoine Julien (Level-US team)
@version 1.0 28/03/2021
*/

#ifndef SerialCommunication_H_
#define SerialCommunication_H_

#include <Arduino.h>

class SerialCommunication
{
    public:
        SerialCommunication();
		
		int serialEncoder(float IMUangles[2]);
		int serialDecoder(int commands[3]);
};

#endif //SerialCommunication_H_