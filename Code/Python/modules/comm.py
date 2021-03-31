import serial
import _struct as stc

class serialport():

    def __init__(self, port, baud, tout):
        try:
            self.ser = serial.Serial(port, baud, timeout=tout)
            self.ser.flush()
        except:
            pass

    def __del__(self):
        try:
            self.ser.close()
        except:
            pass
    
    def test_comm(self):
        try:
            if self.ser:
                return True
        except:
            return False

    def write(self,value):
        self.ser.write(value)

    def read(self):
        while True:
            if self.ser.in_waiting > 0:
                line = self.ser.readline().decode("utf-8").rstrip()

                return line

    def encode(self, msg):
        return stc.pack("HHHH", msg[0], msg[1], msg[2], msg[3])

    def decode(self, msg):
        return msg.split()



