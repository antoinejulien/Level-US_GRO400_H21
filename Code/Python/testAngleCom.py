from modules.anglePlaqueToAngleMoteur_c import getAngles_cffi
from modules.anglePlaqueToAngleMoteur_c.getAngles import getAngles
import time



if __name__ == '__main__':
    ## asking user for values
    print("\n\n\n")
    userX = float(input("enter X angle :"))
    userY = float(input("enter Y angle :"))
    userH = float(input("enter height :"))
    print("\n\n\n")

    ## processing 
    timestart = time.perf_counter()
    anglesMoteurs = getAngles(userX, userY, userH)
    timeAfter = time.perf_counter()

    ## printing results
    i = 1
    for angles in anglesMoteurs:
        print("angle moteur-" + str(i) + " = " + str(angles) + " degres \n")
        i += 1
    print("Calculation took :" + str(timeAfter-timestart) + " seconds.\n")
