/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * anglePlaqueToAngleMoteur.cpp
 *
 * Code generation for function 'anglePlaqueToAngleMoteur'
 *
 */

/* Include files */
#include <cmath>
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "anglePlaqueToAngleMoteur.h"
#include "svd.h"
#include <stdio.h>

/* Type Definitions */
typedef struct {
  double contents;
} coder_internal_ref;

typedef struct {
  double contents[4];
} coder_internal_ref_1;

/* Function Declarations */
static double CalculateErrorInSetOfFunctions(coder_internal_ref
  *distancePlaqueTop_x, coder_internal_ref *distancePlaqueTop_y,
  coder_internal_ref *anglePlaqueTop_z, coder_internal_ref *angleMot1,
  coder_internal_ref *angleMot2, coder_internal_ref *angleMot3,
  coder_internal_ref *angleBras1Middle, coder_internal_ref *angleBras2Middle,
  coder_internal_ref *angleBras3Middle, const coder_internal_ref
  *rayonDistanceAncrageEtPivot, const coder_internal_ref *anglePlaqueTop_y,
  const coder_internal_ref *longueurBras2, const coder_internal_ref
  *anglePlaqueTop_x, const coder_internal_ref *rayonDistanceMoteur, const
  coder_internal_ref *longueurBras1, const coder_internal_ref *hauteurPlaqueTop,
  const coder_internal_ref *hauteurAxeMoteur, const double X[9]);
static void CalculateFunctionEvaluatedAtX(coder_internal_ref
  *distancePlaqueTop_x, coder_internal_ref *distancePlaqueTop_y,
  coder_internal_ref *anglePlaqueTop_z, coder_internal_ref *angleMot1,
  coder_internal_ref *angleMot2, coder_internal_ref *angleMot3,
  coder_internal_ref *angleBras1Middle, coder_internal_ref *angleBras2Middle,
  coder_internal_ref *angleBras3Middle, const coder_internal_ref
  *rayonDistanceAncrageEtPivot, const coder_internal_ref *anglePlaqueTop_y,
  const coder_internal_ref *longueurBras2, const coder_internal_ref
  *anglePlaqueTop_x, const coder_internal_ref *rayonDistanceMoteur, const
  coder_internal_ref *longueurBras1, const coder_internal_ref *hauteurPlaqueTop,
  const coder_internal_ref *hauteurAxeMoteur, const double VAR[9], double RHS[9]);
static void CalculateGradientAtX(coder_internal_ref *distancePlaqueTop_x,
  coder_internal_ref *distancePlaqueTop_y, coder_internal_ref *anglePlaqueTop_z,
  coder_internal_ref *angleMot1, coder_internal_ref *angleMot2,
  coder_internal_ref *angleMot3, coder_internal_ref *angleBras1Middle,
  coder_internal_ref *angleBras2Middle, coder_internal_ref *angleBras3Middle,
  const coder_internal_ref *rayonDistanceAncrageEtPivot, const
  coder_internal_ref *anglePlaqueTop_y, const coder_internal_ref *longueurBras2,
  const coder_internal_ref *anglePlaqueTop_x, const coder_internal_ref
  *rayonDistanceMoteur, const coder_internal_ref *longueurBras1, const
  coder_internal_ref *hauteurPlaqueTop, const coder_internal_ref
  *hauteurAxeMoteur, const double VAR[9], double GradientAtX[9]);
static void c_SolveSetOfNonlinearAlgebraicE(coder_internal_ref
  *distancePlaqueTop_x, coder_internal_ref *distancePlaqueTop_y,
  coder_internal_ref *anglePlaqueTop_z, coder_internal_ref *angleMot1,
  coder_internal_ref *angleMot2, coder_internal_ref *angleMot3,
  coder_internal_ref *angleBras1Middle, coder_internal_ref *angleBras2Middle,
  coder_internal_ref *angleBras3Middle, const coder_internal_ref
  *rayonDistanceAncrageEtPivot, const coder_internal_ref *anglePlaqueTop_y,
  const coder_internal_ref *longueurBras2, const coder_internal_ref
  *anglePlaqueTop_x, const coder_internal_ref *rayonDistanceMoteur, const
  coder_internal_ref *longueurBras1, const coder_internal_ref *hauteurPlaqueTop,
  const coder_internal_ref *hauteurAxeMoteur, coder_internal_ref_1 *error,
  double X[9], double AbsoluteError);

/* Function Definitions */
static double CalculateErrorInSetOfFunctions(coder_internal_ref
  *distancePlaqueTop_x, coder_internal_ref *distancePlaqueTop_y,
  coder_internal_ref *anglePlaqueTop_z, coder_internal_ref *angleMot1,
  coder_internal_ref *angleMot2, coder_internal_ref *angleMot3,
  coder_internal_ref *angleBras1Middle, coder_internal_ref *angleBras2Middle,
  coder_internal_ref *angleBras3Middle, const coder_internal_ref
  *rayonDistanceAncrageEtPivot, const coder_internal_ref *anglePlaqueTop_y,
  const coder_internal_ref *longueurBras2, const coder_internal_ref
  *anglePlaqueTop_x, const coder_internal_ref *rayonDistanceMoteur, const
  coder_internal_ref *longueurBras1, const coder_internal_ref *hauteurPlaqueTop,
  const coder_internal_ref *hauteurAxeMoteur, const double X[9])
{
  double ErrorInSetOfFunctions;
  double x[9];
  double scale;
  int k;
  double absxk;
  double t;

  /* =========================================================================== */
  /* =========================================================================== */
  CalculateFunctionEvaluatedAtX(distancePlaqueTop_x, distancePlaqueTop_y,
    anglePlaqueTop_z, angleMot1, angleMot2, angleMot3, angleBras1Middle,
    angleBras2Middle, angleBras3Middle, rayonDistanceAncrageEtPivot,
    anglePlaqueTop_y, longueurBras2, anglePlaqueTop_x, rayonDistanceMoteur,
    longueurBras1, hauteurPlaqueTop, hauteurAxeMoteur, X, x);
  ErrorInSetOfFunctions = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 9; k++) {
    absxk = std::abs(x[k]);
    if (absxk > scale) {
      t = scale / absxk;
      ErrorInSetOfFunctions = 1.0 + ErrorInSetOfFunctions * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      ErrorInSetOfFunctions += t * t;
    }
  }

  return scale * std::sqrt(ErrorInSetOfFunctions);
}

static void CalculateFunctionEvaluatedAtX(coder_internal_ref
  *distancePlaqueTop_x, coder_internal_ref *distancePlaqueTop_y,
  coder_internal_ref *anglePlaqueTop_z, coder_internal_ref *angleMot1,
  coder_internal_ref *angleMot2, coder_internal_ref *angleMot3,
  coder_internal_ref *angleBras1Middle, coder_internal_ref *angleBras2Middle,
  coder_internal_ref *angleBras3Middle, const coder_internal_ref
  *rayonDistanceAncrageEtPivot, const coder_internal_ref *anglePlaqueTop_y,
  const coder_internal_ref *longueurBras2, const coder_internal_ref
  *anglePlaqueTop_x, const coder_internal_ref *rayonDistanceMoteur, const
  coder_internal_ref *longueurBras1, const coder_internal_ref *hauteurPlaqueTop,
  const coder_internal_ref *hauteurAxeMoteur, const double VAR[9], double RHS[9])
{
  /*  Truncate Output matrix for proper return size. */
  /* =========================================================================== */
  /* =========================================================================== */
  /*  Update variables with new values */
  distancePlaqueTop_x->contents = VAR[0];
  distancePlaqueTop_y->contents = VAR[1];
  anglePlaqueTop_z->contents = VAR[2];
  angleMot1->contents = VAR[3];
  angleMot2->contents = VAR[4];
  angleMot3->contents = VAR[5];
  angleBras1Middle->contents = VAR[6];
  angleBras2Middle->contents = VAR[7];
  angleBras3Middle->contents = VAR[8];
  RHS[0] = distancePlaqueTop_x->contents - rayonDistanceAncrageEtPivot->contents
    * std::cos(anglePlaqueTop_y->contents) * std::sin(anglePlaqueTop_z->contents);
  RHS[1] = (((distancePlaqueTop_y->contents + longueurBras2->contents * std::cos
              (angleBras1Middle->contents - angleMot1->contents)) +
             rayonDistanceAncrageEtPivot->contents * (std::cos
              (anglePlaqueTop_x->contents) * std::cos(anglePlaqueTop_z->contents)
              - std::sin(anglePlaqueTop_x->contents) * std::sin
              (anglePlaqueTop_y->contents) * std::sin(anglePlaqueTop_z->contents)))
            - rayonDistanceMoteur->contents) - longueurBras1->contents * std::
    cos(angleMot1->contents);
  RHS[2] = (((hauteurPlaqueTop->contents + rayonDistanceAncrageEtPivot->contents
              * (std::sin(anglePlaqueTop_x->contents) * std::cos
                 (anglePlaqueTop_z->contents) + std::sin
                 (anglePlaqueTop_y->contents) * std::cos
                 (anglePlaqueTop_x->contents) * std::sin
                 (anglePlaqueTop_z->contents))) - hauteurAxeMoteur->contents) -
            longueurBras1->contents * std::sin(angleMot1->contents)) -
    longueurBras2->contents * std::sin(angleBras1Middle->contents -
    angleMot1->contents);
  RHS[3] = ((((distancePlaqueTop_x->contents + 0.8660254037844386 *
               longueurBras2->contents * std::cos(angleBras2Middle->contents -
    angleMot2->contents)) + 0.5 * rayonDistanceAncrageEtPivot->contents * std::
              cos(anglePlaqueTop_y->contents) * std::sin
              (anglePlaqueTop_z->contents)) + 0.8660254037844386 *
             rayonDistanceAncrageEtPivot->contents * std::cos
             (anglePlaqueTop_y->contents) * std::cos(anglePlaqueTop_z->contents))
            - 0.8660254037844386 * rayonDistanceMoteur->contents) -
    0.8660254037844386 * longueurBras1->contents * std::cos(angleMot2->contents);
  RHS[4] = ((((0.5 * rayonDistanceMoteur->contents +
               distancePlaqueTop_y->contents) + 0.5 * longueurBras1->contents *
              std::cos(angleMot2->contents)) + 0.8660254037844386 *
             rayonDistanceAncrageEtPivot->contents * (std::cos
              (anglePlaqueTop_x->contents) * std::sin(anglePlaqueTop_z->contents)
              + std::sin(anglePlaqueTop_x->contents) * std::sin
              (anglePlaqueTop_y->contents) * std::cos(anglePlaqueTop_z->contents)))
            - 0.5 * longueurBras2->contents * std::cos
            (angleBras2Middle->contents - angleMot2->contents)) - 0.5 *
    rayonDistanceAncrageEtPivot->contents * (std::cos(anglePlaqueTop_x->contents)
    * std::cos(anglePlaqueTop_z->contents) - std::sin(anglePlaqueTop_x->contents)
    * std::sin(anglePlaqueTop_y->contents) * std::sin(anglePlaqueTop_z->contents));
  RHS[5] = ((((hauteurPlaqueTop->contents + 0.8660254037844386 *
               rayonDistanceAncrageEtPivot->contents * (std::sin
    (anglePlaqueTop_x->contents) * std::sin(anglePlaqueTop_z->contents) - std::
    sin(anglePlaqueTop_y->contents) * std::cos(anglePlaqueTop_x->contents) * std::
    cos(anglePlaqueTop_z->contents))) - hauteurAxeMoteur->contents) -
             longueurBras1->contents * std::sin(angleMot2->contents)) -
            longueurBras2->contents * std::sin(angleBras2Middle->contents -
             angleMot2->contents)) - 0.5 * rayonDistanceAncrageEtPivot->contents
    * (std::sin(anglePlaqueTop_x->contents) * std::cos
       (anglePlaqueTop_z->contents) + std::sin(anglePlaqueTop_y->contents) * std::
       cos(anglePlaqueTop_x->contents) * std::sin(anglePlaqueTop_z->contents));
  RHS[6] = ((((0.8660254037844386 * rayonDistanceMoteur->contents +
               distancePlaqueTop_x->contents) + 0.8660254037844386 *
              longueurBras1->contents * std::cos(angleMot3->contents)) + 0.5 *
             rayonDistanceAncrageEtPivot->contents * std::cos
             (anglePlaqueTop_y->contents) * std::sin(anglePlaqueTop_z->contents))
            - 0.8660254037844386 * longueurBras2->contents * std::cos
            (angleBras3Middle->contents - angleMot3->contents)) -
    0.8660254037844386 * rayonDistanceAncrageEtPivot->contents * std::cos
    (anglePlaqueTop_y->contents) * std::cos(anglePlaqueTop_z->contents);
  RHS[7] = ((((0.5 * rayonDistanceMoteur->contents +
               distancePlaqueTop_y->contents) + 0.5 * longueurBras1->contents *
              std::cos(angleMot3->contents)) - 0.5 * longueurBras2->contents *
             std::cos(angleBras3Middle->contents - angleMot3->contents)) -
            0.8660254037844386 * rayonDistanceAncrageEtPivot->contents * (std::
             cos(anglePlaqueTop_x->contents) * std::sin
             (anglePlaqueTop_z->contents) + std::sin(anglePlaqueTop_x->contents)
             * std::sin(anglePlaqueTop_y->contents) * std::cos
             (anglePlaqueTop_z->contents))) - 0.5 *
    rayonDistanceAncrageEtPivot->contents * (std::cos(anglePlaqueTop_x->contents)
    * std::cos(anglePlaqueTop_z->contents) - std::sin(anglePlaqueTop_x->contents)
    * std::sin(anglePlaqueTop_y->contents) * std::sin(anglePlaqueTop_z->contents));
  RHS[8] = ((((hauteurPlaqueTop->contents - hauteurAxeMoteur->contents) -
              longueurBras1->contents * std::sin(angleMot3->contents)) -
             longueurBras2->contents * std::sin(angleBras3Middle->contents -
              angleMot3->contents)) - 0.5 *
            rayonDistanceAncrageEtPivot->contents * (std::sin
             (anglePlaqueTop_x->contents) * std::cos(anglePlaqueTop_z->contents)
             + std::sin(anglePlaqueTop_y->contents) * std::cos
             (anglePlaqueTop_x->contents) * std::sin(anglePlaqueTop_z->contents)))
    - 0.8660254037844386 * rayonDistanceAncrageEtPivot->contents * (std::sin
    (anglePlaqueTop_x->contents) * std::sin(anglePlaqueTop_z->contents) - std::
    sin(anglePlaqueTop_y->contents) * std::cos(anglePlaqueTop_x->contents) * std::
    cos(anglePlaqueTop_z->contents));
}

static void CalculateGradientAtX(coder_internal_ref *distancePlaqueTop_x,
  coder_internal_ref *distancePlaqueTop_y, coder_internal_ref *anglePlaqueTop_z,
  coder_internal_ref *angleMot1, coder_internal_ref *angleMot2,
  coder_internal_ref *angleMot3, coder_internal_ref *angleBras1Middle,
  coder_internal_ref *angleBras2Middle, coder_internal_ref *angleBras3Middle,
  const coder_internal_ref *rayonDistanceAncrageEtPivot, const
  coder_internal_ref *anglePlaqueTop_y, const coder_internal_ref *longueurBras2,
  const coder_internal_ref *anglePlaqueTop_x, const coder_internal_ref
  *rayonDistanceMoteur, const coder_internal_ref *longueurBras1, const
  coder_internal_ref *hauteurPlaqueTop, const coder_internal_ref
  *hauteurAxeMoteur, const double VAR[9], double GradientAtX[9])
{
  double RHS[9];
  double COEF[81];
  double X[81];
  boolean_T p;
  int br;
  double U[81];
  double s[9];
  double V[81];
  int i0;
  double absxk;
  int vcol;
  int r;
  int j;
  int ar;
  int ib;
  int ia;

  /* =========================================================================== */
  /* =========================================================================== */
  CalculateFunctionEvaluatedAtX(distancePlaqueTop_x, distancePlaqueTop_y,
    anglePlaqueTop_z, angleMot1, angleMot2, angleMot3, angleBras1Middle,
    angleBras2Middle, angleBras3Middle, rayonDistanceAncrageEtPivot,
    anglePlaqueTop_y, longueurBras2, anglePlaqueTop_x, rayonDistanceMoteur,
    longueurBras1, hauteurPlaqueTop, hauteurAxeMoteur, VAR, RHS);
  memset(&COEF[0], 0, 81U * sizeof(double));
  memset(&X[0], 0, 81U * sizeof(double));
  COEF[0] = -1.0;
  COEF[18] = rayonDistanceAncrageEtPivot->contents * std::cos
    (anglePlaqueTop_y->contents) * std::cos(anglePlaqueTop_z->contents);
  COEF[10] = -1.0;
  COEF[19] = rayonDistanceAncrageEtPivot->contents * (std::cos
    (anglePlaqueTop_x->contents) * std::sin(anglePlaqueTop_z->contents) + std::
    sin(anglePlaqueTop_x->contents) * std::sin(anglePlaqueTop_y->contents) * std::
    cos(anglePlaqueTop_z->contents));
  COEF[28] = -longueurBras1->contents * std::sin(angleMot1->contents) -
    longueurBras2->contents * std::sin(angleBras1Middle->contents -
    angleMot1->contents);
  COEF[55] = longueurBras2->contents * std::sin(angleBras1Middle->contents -
    angleMot1->contents);
  COEF[20] = rayonDistanceAncrageEtPivot->contents * (std::sin
    (anglePlaqueTop_x->contents) * std::sin(anglePlaqueTop_z->contents) - std::
    sin(anglePlaqueTop_y->contents) * std::cos(anglePlaqueTop_x->contents) * std::
    cos(anglePlaqueTop_z->contents));
  COEF[29] = longueurBras1->contents * std::cos(angleMot1->contents) -
    longueurBras2->contents * std::cos(angleBras1Middle->contents -
    angleMot1->contents);
  COEF[56] = longueurBras2->contents * std::cos(angleBras1Middle->contents -
    angleMot1->contents);
  COEF[3] = -1.0;
  COEF[21] = 0.5 * rayonDistanceAncrageEtPivot->contents * std::cos
    (anglePlaqueTop_y->contents) * (1.732050807568877 * std::sin
    (anglePlaqueTop_z->contents) - std::cos(anglePlaqueTop_z->contents));
  COEF[39] = -0.8660254037844386 * longueurBras1->contents * std::sin
    (angleMot2->contents) - 0.8660254037844386 * longueurBras2->contents * std::
    sin(angleBras2Middle->contents - angleMot2->contents);
  COEF[66] = 0.8660254037844386 * longueurBras2->contents * std::sin
    (angleBras2Middle->contents - angleMot2->contents);
  COEF[13] = -1.0;
  COEF[22] = 0.5 * rayonDistanceAncrageEtPivot->contents * (((1.732050807568877 *
    std::sin(anglePlaqueTop_x->contents) * std::sin(anglePlaqueTop_y->contents) *
    std::sin(anglePlaqueTop_z->contents) - 1.732050807568877 * std::cos
    (anglePlaqueTop_x->contents) * std::cos(anglePlaqueTop_z->contents)) - std::
    cos(anglePlaqueTop_x->contents) * std::sin(anglePlaqueTop_z->contents)) -
    std::sin(anglePlaqueTop_x->contents) * std::sin(anglePlaqueTop_y->contents) *
    std::cos(anglePlaqueTop_z->contents));
  COEF[40] = 0.5 * longueurBras1->contents * std::sin(angleMot2->contents) + 0.5
    * longueurBras2->contents * std::sin(angleBras2Middle->contents -
    angleMot2->contents);
  COEF[67] = -0.5 * longueurBras2->contents * std::sin
    (angleBras2Middle->contents - angleMot2->contents);
  COEF[23] = -0.5 * rayonDistanceAncrageEtPivot->contents * (((std::sin
    (anglePlaqueTop_x->contents) * std::sin(anglePlaqueTop_z->contents) +
    1.732050807568877 * std::sin(anglePlaqueTop_x->contents) * std::cos
    (anglePlaqueTop_z->contents)) + 1.732050807568877 * std::sin
    (anglePlaqueTop_y->contents) * std::cos(anglePlaqueTop_x->contents) * std::
    sin(anglePlaqueTop_z->contents)) - std::sin(anglePlaqueTop_y->contents) *
    std::cos(anglePlaqueTop_x->contents) * std::cos(anglePlaqueTop_z->contents));
  COEF[41] = longueurBras1->contents * std::cos(angleMot2->contents) -
    longueurBras2->contents * std::cos(angleBras2Middle->contents -
    angleMot2->contents);
  COEF[68] = longueurBras2->contents * std::cos(angleBras2Middle->contents -
    angleMot2->contents);
  COEF[6] = -1.0;
  COEF[24] = -0.5 * rayonDistanceAncrageEtPivot->contents * std::cos
    (anglePlaqueTop_y->contents) * (std::cos(anglePlaqueTop_z->contents) +
    1.732050807568877 * std::sin(anglePlaqueTop_z->contents));
  COEF[51] = 0.8660254037844386 * longueurBras1->contents * std::sin
    (angleMot3->contents) + 0.8660254037844386 * longueurBras2->contents * std::
    sin(angleBras3Middle->contents - angleMot3->contents);
  COEF[78] = -0.8660254037844386 * longueurBras2->contents * std::sin
    (angleBras3Middle->contents - angleMot3->contents);
  COEF[16] = -1.0;
  COEF[25] = 0.5 * rayonDistanceAncrageEtPivot->contents * (((1.732050807568877 *
    std::cos(anglePlaqueTop_x->contents) * std::cos(anglePlaqueTop_z->contents)
    - std::cos(anglePlaqueTop_x->contents) * std::sin(anglePlaqueTop_z->contents))
    - 1.732050807568877 * std::sin(anglePlaqueTop_x->contents) * std::sin
    (anglePlaqueTop_y->contents) * std::sin(anglePlaqueTop_z->contents)) - std::
    sin(anglePlaqueTop_x->contents) * std::sin(anglePlaqueTop_y->contents) * std::
    cos(anglePlaqueTop_z->contents));
  COEF[52] = 0.5 * longueurBras1->contents * std::sin(angleMot3->contents) + 0.5
    * longueurBras2->contents * std::sin(angleBras3Middle->contents -
    angleMot3->contents);
  COEF[79] = -0.5 * longueurBras2->contents * std::sin
    (angleBras3Middle->contents - angleMot3->contents);
  COEF[26] = -0.5 * rayonDistanceAncrageEtPivot->contents * (((std::sin
    (anglePlaqueTop_x->contents) * std::sin(anglePlaqueTop_z->contents) -
    1.732050807568877 * std::sin(anglePlaqueTop_x->contents) * std::cos
    (anglePlaqueTop_z->contents)) - 1.732050807568877 * std::sin
    (anglePlaqueTop_y->contents) * std::cos(anglePlaqueTop_x->contents) * std::
    sin(anglePlaqueTop_z->contents)) - std::sin(anglePlaqueTop_y->contents) *
    std::cos(anglePlaqueTop_x->contents) * std::cos(anglePlaqueTop_z->contents));
  COEF[53] = longueurBras1->contents * std::cos(angleMot3->contents) -
    longueurBras2->contents * std::cos(angleBras3Middle->contents -
    angleMot3->contents);
  COEF[80] = longueurBras2->contents * std::cos(angleBras3Middle->contents -
    angleMot3->contents);
  p = true;
  for (br = 0; br < 81; br++) {
    if (p && ((!rtIsInf(COEF[br])) && (!rtIsNaN(COEF[br])))) {
      p = true;
    } else {
      p = false;
    }
  }

  if (!p) {
    for (i0 = 0; i0 < 81; i0++) {
      X[i0] = rtNaN;
    }
  } else {
    svd(COEF, U, s, V);
    absxk = std::abs(s[0]);
    if ((!rtIsInf(absxk)) && (!rtIsNaN(absxk))) {
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &vcol);
        absxk = std::ldexp(1.0, vcol - 53);
      }
    } else {
      absxk = rtNaN;
    }

    absxk *= 9.0;
    r = 0;
    br = 1;
    while ((br < 10) && (s[br - 1] > absxk)) {
      r++;
      br++;
    }

    if (r > 0) {
      vcol = 0;
      for (j = 1; j <= r; j++) {
        absxk = 1.0 / s[j - 1];
        for (br = vcol; br < vcol + 9; br++) {
          V[br] *= absxk;
        }

        vcol += 9;
      }

      for (vcol = 0; vcol <= 73; vcol += 9) {
        for (j = vcol; j < vcol + 9; j++) {
          X[j] = 0.0;
        }
      }

      br = -1;
      for (vcol = 0; vcol <= 73; vcol += 9) {
        ar = -1;
        br++;
        i0 = (br + 9 * (r - 1)) + 1;
        for (ib = br; ib + 1 <= i0; ib += 9) {
          if (U[ib] != 0.0) {
            ia = ar;
            for (j = vcol; j < vcol + 9; j++) {
              ia++;
              X[j] += U[ib] * V[ia];
            }
          }

          ar += 9;
        }
      }
    }
  }

  for (i0 = 0; i0 < 9; i0++) {
    GradientAtX[i0] = 0.0;
    for (vcol = 0; vcol < 9; vcol++) {
      GradientAtX[i0] += X[i0 + 9 * vcol] * RHS[vcol];
    }
  }
}

static void c_SolveSetOfNonlinearAlgebraicE(coder_internal_ref
  *distancePlaqueTop_x, coder_internal_ref *distancePlaqueTop_y,
  coder_internal_ref *anglePlaqueTop_z, coder_internal_ref *angleMot1,
  coder_internal_ref *angleMot2, coder_internal_ref *angleMot3,
  coder_internal_ref *angleBras1Middle, coder_internal_ref *angleBras2Middle,
  coder_internal_ref *angleBras3Middle, const coder_internal_ref
  *rayonDistanceAncrageEtPivot, const coder_internal_ref *anglePlaqueTop_y,
  const coder_internal_ref *longueurBras2, const coder_internal_ref
  *anglePlaqueTop_x, const coder_internal_ref *rayonDistanceMoteur, const
  coder_internal_ref *longueurBras1, const coder_internal_ref *hauteurPlaqueTop,
  const coder_internal_ref *hauteurAxeMoteur, coder_internal_ref_1 *error,
  double X[9], double AbsoluteError)
{
  double alphaBest;
  int numberOfGradientCalculations;
  int b_numberOfGradientCalculations;
  boolean_T exitg1;
  double magErrorInSetOfFunctions;
  double dX[9];
  int i;
  double y[9];
  int idx;
  boolean_T exitg2;
  double space23;
  double alpha_idx_1;
  double alpha_idx_2;
  double alpha_idx_3;

  /* =========================================================================== */
  /* =========================================================================== */
  alphaBest = 0.1;
  numberOfGradientCalculations = 0;
  b_numberOfGradientCalculations = 0;
  exitg1 = false;
  while ((!exitg1) && (b_numberOfGradientCalculations < 101)) {
    numberOfGradientCalculations = b_numberOfGradientCalculations;
    magErrorInSetOfFunctions = CalculateErrorInSetOfFunctions
      (distancePlaqueTop_x, distancePlaqueTop_y, anglePlaqueTop_z, angleMot1,
       angleMot2, angleMot3, angleBras1Middle, angleBras2Middle,
       angleBras3Middle, rayonDistanceAncrageEtPivot, anglePlaqueTop_y,
       longueurBras2, anglePlaqueTop_x, rayonDistanceMoteur, longueurBras1,
       hauteurPlaqueTop, hauteurAxeMoteur, X);
    if (magErrorInSetOfFunctions < AbsoluteError) {
      exitg1 = true;
    } else {
      CalculateGradientAtX(distancePlaqueTop_x, distancePlaqueTop_y,
                           anglePlaqueTop_z, angleMot1, angleMot2, angleMot3,
                           angleBras1Middle, angleBras2Middle, angleBras3Middle,
                           rayonDistanceAncrageEtPivot, anglePlaqueTop_y,
                           longueurBras2, anglePlaqueTop_x, rayonDistanceMoteur,
                           longueurBras1, hauteurPlaqueTop, hauteurAxeMoteur, X,
                           dX);
      for (i = 0; i < 9; i++) {
        y[i] = std::abs(dX[i]);
      }

      if (!rtIsNaN(y[0])) {
        idx = 1;
      } else {
        idx = 0;
        i = 2;
        exitg2 = false;
        while ((!exitg2) && (i < 10)) {
          if (!rtIsNaN(y[i - 1])) {
            idx = i;
            exitg2 = true;
          } else {
            i++;
          }
        }
      }

      if (idx == 0) {
        space23 = y[0];
      } else {
        space23 = y[idx - 1];
        while (idx + 1 < 10) {
          if (space23 < y[idx]) {
            space23 = y[idx];
          }

          idx++;
        }
      }

      if (space23 == 0.0) {
        printf("Nonlinear solver failed (dX == 0)");
        fflush(stdout);
        exitg1 = true;
      } else {
        /* =========================================================================== */
        /* =========================================================================== */
        if (alphaBest > 0.5) {
          alphaBest = 0.5;
        }

        alpha_idx_1 = 0.8 * alphaBest;
        alpha_idx_2 = 1.2 * alphaBest;
        alpha_idx_3 = 2.0 * alphaBest;
        for (i = 0; i < 4; i++) {
          error->contents[i] = 1.0 + (double)i;
        }

        for (i = 0; i < 9; i++) {
          y[i] = X[i] + alpha_idx_3 * dX[i];
        }

        error->contents[3] = CalculateErrorInSetOfFunctions(distancePlaqueTop_x,
          distancePlaqueTop_y, anglePlaqueTop_z, angleMot1, angleMot2, angleMot3,
          angleBras1Middle, angleBras2Middle, angleBras3Middle,
          rayonDistanceAncrageEtPivot, anglePlaqueTop_y, longueurBras2,
          anglePlaqueTop_x, rayonDistanceMoteur, longueurBras1, hauteurPlaqueTop,
          hauteurAxeMoteur, y);
        for (i = 0; i < 9; i++) {
          y[i] = X[i] + alpha_idx_2 * dX[i];
        }

        error->contents[2] = CalculateErrorInSetOfFunctions(distancePlaqueTop_x,
          distancePlaqueTop_y, anglePlaqueTop_z, angleMot1, angleMot2, angleMot3,
          angleBras1Middle, angleBras2Middle, angleBras3Middle,
          rayonDistanceAncrageEtPivot, anglePlaqueTop_y, longueurBras2,
          anglePlaqueTop_x, rayonDistanceMoteur, longueurBras1, hauteurPlaqueTop,
          hauteurAxeMoteur, y);
        for (i = 0; i < 9; i++) {
          y[i] = X[i] + alpha_idx_1 * dX[i];
        }

        error->contents[1] = CalculateErrorInSetOfFunctions(distancePlaqueTop_x,
          distancePlaqueTop_y, anglePlaqueTop_z, angleMot1, angleMot2, angleMot3,
          angleBras1Middle, angleBras2Middle, angleBras3Middle,
          rayonDistanceAncrageEtPivot, anglePlaqueTop_y, longueurBras2,
          anglePlaqueTop_x, rayonDistanceMoteur, longueurBras1, hauteurPlaqueTop,
          hauteurAxeMoteur, y);
        error->contents[0] = magErrorInSetOfFunctions;
        alphaBest = 0.0;
        idx = 0;
        exitg2 = false;
        while ((!exitg2) && (idx < 21)) {
          if ((error->contents[0] < error->contents[1]) || (error->contents[1] <
               error->contents[2])) {
            alpha_idx_3 = alpha_idx_2;
            alpha_idx_2 = alpha_idx_1;
            alpha_idx_1 *= 0.5;
            error->contents[3] = error->contents[2];
            error->contents[2] = error->contents[1];
            for (i = 0; i < 9; i++) {
              y[i] = X[i] + alpha_idx_1 * dX[i];
            }

            error->contents[1] = CalculateErrorInSetOfFunctions
              (distancePlaqueTop_x, distancePlaqueTop_y, anglePlaqueTop_z,
               angleMot1, angleMot2, angleMot3, angleBras1Middle,
               angleBras2Middle, angleBras3Middle, rayonDistanceAncrageEtPivot,
               anglePlaqueTop_y, longueurBras2, anglePlaqueTop_x,
               rayonDistanceMoteur, longueurBras1, hauteurPlaqueTop,
               hauteurAxeMoteur, y);
            idx++;
          } else if (error->contents[2] < error->contents[3]) {
            space23 = alpha_idx_2 - alpha_idx_1;
            magErrorInSetOfFunctions = alpha_idx_3 - alpha_idx_2;
            if ((alpha_idx_1 >= 0.99 * space23) && (alpha_idx_1 >= 0.99 *
                 magErrorInSetOfFunctions)) {
              alpha_idx_3 = alpha_idx_2;
              alpha_idx_2 = alpha_idx_1;
              alpha_idx_1 *= 0.5;
              error->contents[3] = error->contents[2];
              error->contents[2] = error->contents[1];
              for (i = 0; i < 9; i++) {
                y[i] = X[i] + alpha_idx_1 * dX[i];
              }

              error->contents[1] = CalculateErrorInSetOfFunctions
                (distancePlaqueTop_x, distancePlaqueTop_y, anglePlaqueTop_z,
                 angleMot1, angleMot2, angleMot3, angleBras1Middle,
                 angleBras2Middle, angleBras3Middle, rayonDistanceAncrageEtPivot,
                 anglePlaqueTop_y, longueurBras2, anglePlaqueTop_x,
                 rayonDistanceMoteur, longueurBras1, hauteurPlaqueTop,
                 hauteurAxeMoteur, y);
            } else if (magErrorInSetOfFunctions >= 0.99 * space23) {
              alpha_idx_3 = 0.5 * (alpha_idx_2 + alpha_idx_3);
              for (i = 0; i < 9; i++) {
                y[i] = X[i] + alpha_idx_3 * dX[i];
              }

              error->contents[3] = CalculateErrorInSetOfFunctions
                (distancePlaqueTop_x, distancePlaqueTop_y, anglePlaqueTop_z,
                 angleMot1, angleMot2, angleMot3, angleBras1Middle,
                 angleBras2Middle, angleBras3Middle, rayonDistanceAncrageEtPivot,
                 anglePlaqueTop_y, longueurBras2, anglePlaqueTop_x,
                 rayonDistanceMoteur, longueurBras1, hauteurPlaqueTop,
                 hauteurAxeMoteur, y);
            } else {
              alpha_idx_3 = alpha_idx_2;
              alpha_idx_2 = 0.5 * (alpha_idx_1 + alpha_idx_2);
              error->contents[3] = error->contents[2];
              for (i = 0; i < 9; i++) {
                y[i] = X[i] + alpha_idx_2 * dX[i];
              }

              error->contents[2] = CalculateErrorInSetOfFunctions
                (distancePlaqueTop_x, distancePlaqueTop_y, anglePlaqueTop_z,
                 angleMot1, angleMot2, angleMot3, angleBras1Middle,
                 angleBras2Middle, angleBras3Middle, rayonDistanceAncrageEtPivot,
                 anglePlaqueTop_y, longueurBras2, anglePlaqueTop_x,
                 rayonDistanceMoteur, longueurBras1, hauteurPlaqueTop,
                 hauteurAxeMoteur, y);
            }

            idx++;
          } else if (error->contents[3] < error->contents[0]) {
            alphaBest = alpha_idx_3;
            exitg2 = true;
          } else {
            idx++;
          }
        }

        if (alphaBest == 0.0) {
          printf("Nonlinear solver failed (alphaBest == 0)");
          fflush(stdout);
          exitg1 = true;
        } else {
          for (i = 0; i < 9; i++) {
            X[i] += alphaBest * dX[i];
          }

          b_numberOfGradientCalculations++;
        }
      }
    }
  }

  if (numberOfGradientCalculations >= 100) {
    printf("Nonlinear solver failed (too many gradient calculations)");
    fflush(stdout);
  }
}

void anglePlaqueToAngleMoteur(double anglePlaqueTop_x, double anglePlaqueTop_y,
  double hauteurPlaqueTop, double Output[3])
{
  coder_internal_ref angleBras1Middle;
  coder_internal_ref angleBras2Middle;
  coder_internal_ref angleBras3Middle;
  coder_internal_ref angleMot1;
  coder_internal_ref angleMot2;
  coder_internal_ref angleMot3;
  coder_internal_ref anglePlaqueTop_z;
  coder_internal_ref distancePlaqueTop_x;
  coder_internal_ref distancePlaqueTop_y;
  coder_internal_ref hauteurAxeMoteur;
  coder_internal_ref longueurBras1;
  coder_internal_ref longueurBras2;
  coder_internal_ref rayonDistanceAncrageEtPivot;
  coder_internal_ref rayonDistanceMoteur;
  coder_internal_ref b_anglePlaqueTop_x;
  coder_internal_ref b_anglePlaqueTop_y;
  coder_internal_ref b_hauteurPlaqueTop;
  double VAR[9];
  coder_internal_ref_1 error;
  double ErrorInConvergenceOfSolution[9];
  int k;
  int idx;
  boolean_T exitg1;
  double MaxErrorInConvergence;
  double b_Output[13];

  /* =========================================================================== */
  /*  File: anglePlaqueToAngleMoteur.m created Feb 23 2021 by MotionGenesis 5.9. */
  /*  Portions copyright (c) 2009-2020 Motion Genesis LLC.  Rights reserved. */
  /*  MotionGenesis Student Licensee: francis trepanier. (until March 2024). */
  /*  Paid-up MotionGenesis Student licensees are granted the right */
  /*  to distribute this code for legal student-academic (non-professional) purposes only, */
  /*  provided this copyright notice appears in all copies and distributions. */
  /* =========================================================================== */
  /*  The software is provided "as is", without warranty of any kind, express or     */
  /*  implied, including but not limited to the warranties of merchantability or     */
  /*  fitness for a particular purpose. In no event shall the authors, contributors, */
  /*  or copyright holders be liable for any claim, damages or other liability,      */
  /*  whether in an action of contract, tort, or otherwise, arising from, out of, or */
  /*  in connection with the software or the use or other dealings in the software.  */
  /* =========================================================================== */
  /* -------------------------------+--------------------------+-------------------+----------------- */
  /*  Quantity                      | Value                    | Units             | Description */
  /* -------------------------------|--------------------------|-------------------|----------------- */
  /*  mm                  Constant */
  /*  in                  Constant */
  /*  in                  Constant */
  /*  mm                  Constant */
  /*  mm                  Constant */
  angleBras1Middle.contents = 0.0;

  /*  UNITS               Guess */
  angleBras2Middle.contents = 0.0;

  /*  UNITS               Guess */
  angleBras3Middle.contents = 0.0;

  /*  UNITS               Guess */
  angleMot1.contents = 0.0;

  /*  UNITS               Guess */
  angleMot2.contents = 0.0;

  /*  UNITS               Guess */
  angleMot3.contents = 0.0;

  /*  UNITS               Guess */
  anglePlaqueTop_z.contents = 0.0;

  /*  UNITS               Guess */
  distancePlaqueTop_x.contents = 0.0;

  /*  UNITS               Guess */
  distancePlaqueTop_y.contents = 0.0;

  /*  UNITS               Guess */
  /*                      Absolute Error */
  /*  NoUnits             0 or 1 */
  /*  NoUnits             0 or 1 */
  /* -------------------------------+--------------------------+-------------------+----------------- */
  /*  Unit conversions.  UnitSystem: kg, meter, second. */
  hauteurAxeMoteur.contents = 0.02863;

  /*   Converted from mm  */
  longueurBras1.contents = 0.07619999999999999;

  /*   Converted from in  */
  longueurBras2.contents = 0.1016;

  /*   Converted from in  */
  rayonDistanceAncrageEtPivot.contents = 0.14833000000000002;
  rayonDistanceMoteur.contents = 0.14833000000000002;

  /*   Converted from mm  */
  b_anglePlaqueTop_x.contents = anglePlaqueTop_x * 0.017453292519943295;

  /*   Converted from deg  */
  b_anglePlaqueTop_y.contents = anglePlaqueTop_y * 0.017453292519943295;

  /*   Converted from deg  */
  b_hauteurPlaqueTop.contents = hauteurPlaqueTop * 0.001;

  /*   Converted from mm  */
  memset(&VAR[0], 0, 9U * sizeof(double));
  c_SolveSetOfNonlinearAlgebraicE(&distancePlaqueTop_x, &distancePlaqueTop_y,
    &anglePlaqueTop_z, &angleMot1, &angleMot2, &angleMot3, &angleBras1Middle,
    &angleBras2Middle, &angleBras3Middle, &rayonDistanceAncrageEtPivot,
    &b_anglePlaqueTop_y, &longueurBras2, &b_anglePlaqueTop_x,
    &rayonDistanceMoteur, &longueurBras1, &b_hauteurPlaqueTop, &hauteurAxeMoteur,
    &error, VAR, 1.0E-9);
  CalculateFunctionEvaluatedAtX(&distancePlaqueTop_x, &distancePlaqueTop_y,
    &anglePlaqueTop_z, &angleMot1, &angleMot2, &angleMot3, &angleBras1Middle,
    &angleBras2Middle, &angleBras3Middle, &rayonDistanceAncrageEtPivot,
    &b_anglePlaqueTop_y, &longueurBras2, &b_anglePlaqueTop_x,
    &rayonDistanceMoteur, &longueurBras1, &b_hauteurPlaqueTop, &hauteurAxeMoteur,
    VAR, ErrorInConvergenceOfSolution);
  for (k = 0; k < 9; k++) {
    VAR[k] = std::abs(ErrorInConvergenceOfSolution[k]);
  }

  if (!rtIsNaN(VAR[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!rtIsNaN(VAR[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    MaxErrorInConvergence = VAR[0];
  } else {
    MaxErrorInConvergence = VAR[idx - 1];
    while (idx + 1 < 10) {
      if (MaxErrorInConvergence < VAR[idx]) {
        MaxErrorInConvergence = VAR[idx];
      }

      idx++;
    }
  }

  /* =========================================================================== */
  /* =========================================================================== */
  b_Output[0] = MaxErrorInConvergence;
  b_Output[1] = distancePlaqueTop_x.contents;
  b_Output[2] = distancePlaqueTop_y.contents;
  b_Output[3] = anglePlaqueTop_z.contents;
  b_Output[4] = angleMot1.contents;
  b_Output[5] = angleMot2.contents;
  b_Output[6] = angleMot3.contents;
  b_Output[7] = angleBras1Middle.contents;
  b_Output[8] = angleBras2Middle.contents;
  b_Output[9] = angleBras3Middle.contents;
  b_Output[10] = angleMot1.contents * 57.295779513082323;

  /*  Converted to deg */
  b_Output[11] = angleMot2.contents * 57.295779513082323;

  /*  Converted to deg */
  b_Output[12] = angleMot3.contents * 57.295779513082323;

  /*  Converted to deg */
  /*  Close output files. */
  for (k = 0; k < 3; k++) {
    Output[k] = b_Output[10 + k];
  }

  /* ============================= */
  /*  End of function anglePlaqueToAngleMoteur */
  /* ============================= */
}

/* End of code generation (anglePlaqueToAngleMoteur.cpp) */
