import _struct as stc
import serial
import sys

def encoding_tests():
    mode = 0
    angle1 = 45
    angle2 = 45
    angle3 = 45

    msg1 = (str(mode) + " " + str(angle1) +" " +  str(angle2) +" " +  str(angle3)).encode()

    #msg2 = stc.pack("HHHH", mode, angle1, angle2, angle3)

    print(msg1)

    ser.write(encoding_tests)

if __name__ == "__main__":

    mode = 0
    angle1 = 45
    angle2 = 50
    angle3 = 55

    msg2 = stc.pack("HHHH",mode, angle1, angle2, angle3)

    ser = serial.Serial('COM3', 115200, timeout=1)
    ser.flush()
    print("connected")

    print(stc.unpack("HHHH", msg2))

    ser.write(msg2)

    print("sent")

    while True:
        if ser.in_waiting > 0:
            line = ser.readline()
            line = line.decode("utf-8").rstrip()
            #print(sys.getsizeof(line))
            #msg = stc.unpack("hhh", line)

            print(line)

    ser.close()