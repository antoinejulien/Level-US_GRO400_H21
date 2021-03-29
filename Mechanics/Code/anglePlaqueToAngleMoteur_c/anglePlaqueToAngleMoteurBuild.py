from cffi import FFI
ffibuilder = FFI()

ffibuilder.cdef("""
    void anglePlaqueToAngleMoteur(double anglePlaqueTop_x, double anglePlaqueTop_y,double hauteurPlaqueTop, double Output[3]);
""")

ffibuilder.set_source("anglePlaqueToAngleMoteur_cffi",
"""
    #include <math.h>
    #include <string.h>
    #include "rt_nonfinite.h"
    #include "anglePlaqueToAngleMoteur.h"
    #include "svd.h"
    #include <stdio.h>
    
""",
    sources = ['anglePlaqueToAngleMoteur.c','svd.c'],
    libraries = [])

if __name__=="__main__":
    ffibuilder.compile(verbose=True)