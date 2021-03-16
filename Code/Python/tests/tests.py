import _struct as stc

mode = 0
angle1 = 45
angle2 = 45
angle3 = 45

msg = stc.pack("HHHH", mode, angle1, angle2, angle3)

print(msg)