/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * xaxpy.h
 *
 * Code generation for function 'xaxpy'
 *
 */

#ifndef XAXPY_H
#define XAXPY_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "anglePlaqueToAngleMoteur_types.h"

/* Function Declarations */
extern void b_xaxpy(int n, double a, const double x[81], int ix0, double y[9],
                    int iy0);
extern void c_xaxpy(int n, double a, const double x[9], int ix0, double y[81],
                    int iy0);
extern void xaxpy(int n, double a, int ix0, double y[81], int iy0);

#endif

/* End of code generation (xaxpy.h) */
