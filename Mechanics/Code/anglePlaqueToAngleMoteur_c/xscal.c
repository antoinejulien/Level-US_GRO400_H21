/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * xscal.c
 *
 * Code generation for function 'xscal'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "anglePlaqueToAngleMoteur.h"
#include "xscal.h"

/* Function Definitions */
void xscal(double a, double x[81], int ix0)
{
  int k;
  for (k = ix0; k <= ix0 + 8; k++) {
    x[k - 1] *= a;
  }
}

/* End of code generation (xscal.c) */
