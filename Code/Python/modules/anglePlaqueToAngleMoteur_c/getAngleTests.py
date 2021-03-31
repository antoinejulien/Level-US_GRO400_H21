from getAngles_cffi import ffi,lib
import time


if __name__ == '__main__':
    ## asking user for values
    print("\n\n\n")
    userX = float(input("enter X angle :"))
    userY = float(input("enter Y angle :"))
    userH = float(input("enter height :"))
    print("\n\n\n")


    ## declaring angles
    anglex = ffi.cast("double",userX)
    angley = ffi.cast("double",userY)
    hauteur = ffi.cast("double",userH)
    anglesMoteurs = ffi.new("double[3]")

    ## processing 
    timestart = time.perf_counter()
    lib.getAngles(anglex, angley, hauteur, anglesMoteurs)
    timeAfter = time.perf_counter()

    ## printing results
    print("\n\n\ninitial values :\n" + "angle X :\t" + str(float(anglex)) + "\nanlge Y :\t" + str(float(angley)) + "\nheight :\t" + str(float(hauteur)) + "\n")
    i = 1
    for angles in anglesMoteurs:
        print("angle moteur-" + str(i) + " = " + str(angles) + " degres \n")
        i += 1
    print("Calculation took :" + str(timeAfter-timestart) + " seconds.\n")