import serial
import _struct as stc

class serialport():

    def __init__(self, port, baud, tout):
        self.port_ = port
        self.baud_ = baud
        self.tout_ = tout
        try:
            self.ser = serial.Serial(port, baud, timeout=tout)
            self.ser.flush()
            self.ser_status = True
        except:
            self.ser_status = False

    def __del__(self):
        try:
            self.ser.close()
        except:
            pass
    
    def test_comm(self):
        if self.ser_status:
            self.ser.close()
        try:
            self.ser = serial.Serial(self.port_, self.baud_, timeout=self.tout_)
            self.ser_status = True
            result = True
        except:
            self.ser_status = False
            result =  False

        return result

    def write(self,value):
        self.ser.write(value)

    def read(self):
        while True:
            if self.ser.in_waiting > 0:
                line = self.ser.readline()

                return line

    def encode(self, mode, msg):
        
        if mode == 0:
            #return stc.pack("HHHH", mode, int(msg[0]), int(msg[1]), int(msg[2]))
            #return stc.pack("<fff", mode, msg[0], msg[1], msg[2])
            
            self.ser.write(stc.pack("H", mode))
            self.ser.write((str(msg[0]) + " ").encode("utf-8"))
            self.ser.write((str(msg[1]) + " ").encode("utf-8"))
            self.ser.write(str(msg[2]).encode("utf-8"))
            
        elif mode == 1:
            return stc.pack("H", mode)

    def decode(self, msg):
        #return stc.unpack("fff", msg)
        return msg.decode("utf-8").rstrip().split()



