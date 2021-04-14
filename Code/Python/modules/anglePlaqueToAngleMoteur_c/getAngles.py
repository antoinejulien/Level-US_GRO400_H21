from getAngles_cffi import ffi,lib

def getAngles(angleX, angleY, hauteur):
    # forcing variable to be doubles
    anglex = ffi.cast("double",float(angleX))
    angley = ffi.cast("double",float(angleY))
    hauteur = ffi.cast("double",float(hauteur))
    anglesMoteurs = ffi.new("double[3]")

    # computing
    lib.getAngles(anglex, angley, hauteur, anglesMoteurs)

    # 
    for i, angle in enumerate(anglesMoteurs):
        anglesMoteurs[i] = 312 - angle
    
    # returning array of 3 angles
    return anglesMoteurs

