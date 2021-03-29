from getAngles_cffi import ffi,lib
import ctypes


if __name__ == '__main__':
    anglex = ffi.cast("double",10.0)
    #angle1[0] = 10.0
    print(anglex)
    #print(angle1[0])
    angley = ffi.cast("double",10)
    hauteur = ffi.cast("double",100)




    #angley = ffi.new("double *")
    #angley[0] = 10
    #hauteur = ffi.new("double *")
    #hauteur[0] = 100

    anglesMoteurs = ffi.new("double[3]")
    #print(anglesMoteurs)
    lib.getAngles(anglex, angley, hauteur, anglesMoteurs)
    i = 1
    for angles in anglesMoteurs:
        print("angle moteur-" + str(i) + " = " + str(angles) + " degres \n")

        
        #print("angle moteur-" )
        #print( i )
        #print(" = ")
        #print(angles)
        #print(" degres \n")
        i += 1
