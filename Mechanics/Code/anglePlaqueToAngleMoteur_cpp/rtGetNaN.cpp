/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * rtGetNaN.cpp
 *
 * Code generation for function 'anglePlaqueToAngleMoteur'
 *
 */

/*
 * Abstract:
 *       MATLAB for code generation function to initialize non-finite, NaN
 */
#include "rtGetNaN.h"

/* Function: rtGetNaN ==================================================
 * Abstract:
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetNaN(void)
{
  return rtNaN;
}

/* Function: rtGetNaNF ==================================================
 * Abstract:
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF(void)
{
  return rtNaNF;
}

/* End of code generation (rtGetNaN.cpp) */
