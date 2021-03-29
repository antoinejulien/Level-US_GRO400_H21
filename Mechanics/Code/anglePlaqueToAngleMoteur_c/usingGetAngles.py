from cffi import FFI
ffibuilder = FFI()

ffibuilder.cdef("""
    void getAngles(double anglex,double angley,double hauteur,double angles[3]);
""")

ffibuilder.set_source("getAngles_cffi",
"""
    #include <stdio.h>
    #include "anglePlaqueToAngleMoteur.h"
    #include "anglePlaqueToAngleMoteur_initialize.h"
    #include "anglePlaqueToAngleMoteur_terminate.h"
    #include "anglePlaqueToAngleMoteur_types.h"
    #include "rt_nonfinite.h"
    #include "rtGetInf.h"
    #include "rtGetNaN.h"
    #include "rtwtypes.h"
    #include "sqrt.h"
    #include "svd.h"
    #include "xaxpy.h"
    #include "xdotc.h"
    #include "xnrm2.h"
    #include "xrot.h"
    #include "xrotg.h"
    #include "xscal.h"
    #include "xswap.h"


    
    
""",
    sources = ['anglePlaqueToAngleMoteur.c','anglePlaqueToAngleMoteur_initialize.c','anglePlaqueToAngleMoteur_terminate.c','getAngles.c','rt_nonfinite.c','rtGetInf.c','rtGetNaN.c','sqrt.c','svd.c','xaxpy.c','xdotc.c','xnrm2.c','xrot.c','xrotg.c','xscal.c','xswap.c'],
    libraries = [])

if __name__=="__main__":
    ffibuilder.compile(verbose=True)