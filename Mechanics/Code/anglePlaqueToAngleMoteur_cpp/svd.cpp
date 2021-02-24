/*
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * svd.cpp
 *
 * Code generation for function 'svd'
 *
 */

/* Include files */
#include <cmath>
#include <string.h>
#include "rt_nonfinite.h"
#include "anglePlaqueToAngleMoteur.h"
#include "svd.h"
#include "xrot.h"
#include "xrotg.h"
#include "sqrt.h"
#include "xswap.h"
#include "xscal.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"

/* Function Definitions */
void svd(const double A[81], double U[81], double s[9], double V[81])
{
  double b_A[81];
  double b_s[9];
  double e[9];
  double work[9];
  double Vf[81];
  int q;
  int m;
  int qq;
  boolean_T apply_transform;
  double nrm;
  int qs;
  int qp1jj;
  int qjj;
  double snorm;
  double rt;
  double r;
  int exitg1;
  boolean_T exitg2;
  double f;
  double scale;
  double sqds;
  memcpy(&b_A[0], &A[0], 81U * sizeof(double));
  memset(&b_s[0], 0, 9U * sizeof(double));
  memset(&e[0], 0, 9U * sizeof(double));
  memset(&work[0], 0, 9U * sizeof(double));
  memset(&U[0], 0, 81U * sizeof(double));
  memset(&Vf[0], 0, 81U * sizeof(double));
  for (q = 0; q < 8; q++) {
    qq = q + 9 * q;
    apply_transform = false;
    nrm = xnrm2(9 - q, b_A, qq + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq] < 0.0) {
        b_s[q] = -nrm;
      } else {
        b_s[q] = nrm;
      }

      if (std::abs(b_s[q]) >= 1.0020841800044864E-292) {
        nrm = 1.0 / b_s[q];
        qjj = (qq - q) + 9;
        for (qp1jj = qq; qp1jj < qjj; qp1jj++) {
          b_A[qp1jj] *= nrm;
        }
      } else {
        qjj = (qq - q) + 9;
        for (qp1jj = qq; qp1jj < qjj; qp1jj++) {
          b_A[qp1jj] /= b_s[q];
        }
      }

      b_A[qq]++;
      b_s[q] = -b_s[q];
    } else {
      b_s[q] = 0.0;
    }

    for (qs = q + 1; qs + 1 < 10; qs++) {
      qjj = q + 9 * qs;
      if (apply_transform) {
        xaxpy(9 - q, -(xdotc(9 - q, b_A, qq + 1, b_A, qjj + 1) / b_A[q + 9 * q]),
              qq + 1, b_A, qjj + 1);
      }

      e[qs] = b_A[qjj];
    }

    for (qp1jj = q; qp1jj + 1 < 10; qp1jj++) {
      U[qp1jj + 9 * q] = b_A[qp1jj + 9 * q];
    }

    if (q + 1 <= 7) {
      nrm = b_xnrm2(8 - q, e, q + 2);
      if (nrm == 0.0) {
        e[q] = 0.0;
      } else {
        if (e[q + 1] < 0.0) {
          e[q] = -nrm;
        } else {
          e[q] = nrm;
        }

        nrm = e[q];
        if (std::abs(e[q]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[q];
          for (qp1jj = q + 1; qp1jj < 9; qp1jj++) {
            e[qp1jj] *= nrm;
          }
        } else {
          for (qp1jj = q + 1; qp1jj < 9; qp1jj++) {
            e[qp1jj] /= nrm;
          }
        }

        e[q + 1]++;
        e[q] = -e[q];
        for (qp1jj = q + 1; qp1jj + 1 < 10; qp1jj++) {
          work[qp1jj] = 0.0;
        }

        for (qs = q + 1; qs + 1 < 10; qs++) {
          b_xaxpy(8 - q, e[qs], b_A, (q + 9 * qs) + 2, work, q + 2);
        }

        for (qs = q + 1; qs + 1 < 10; qs++) {
          c_xaxpy(8 - q, -e[qs] / e[q + 1], work, q + 2, b_A, (q + 9 * qs) + 2);
        }
      }

      for (qp1jj = q + 1; qp1jj + 1 < 10; qp1jj++) {
        Vf[qp1jj + 9 * q] = e[qp1jj];
      }
    }
  }

  m = 7;
  b_s[8] = b_A[80];
  e[7] = b_A[79];
  e[8] = 0.0;
  memset(&U[72], 0, 9U * sizeof(double));
  U[80] = 1.0;
  for (q = 7; q >= 0; q--) {
    qq = q + 9 * q;
    if (b_s[q] != 0.0) {
      for (qs = q + 1; qs + 1 < 10; qs++) {
        qjj = (q + 9 * qs) + 1;
        xaxpy(9 - q, -(xdotc(9 - q, U, qq + 1, U, qjj) / U[qq]), qq + 1, U, qjj);
      }

      for (qp1jj = q; qp1jj + 1 < 10; qp1jj++) {
        U[qp1jj + 9 * q] = -U[qp1jj + 9 * q];
      }

      U[qq]++;
      for (qp1jj = 1; qp1jj <= q; qp1jj++) {
        U[(qp1jj + 9 * q) - 1] = 0.0;
      }
    } else {
      memset(&U[q * 9], 0, 9U * sizeof(double));
      U[qq] = 1.0;
    }
  }

  for (q = 8; q >= 0; q--) {
    if ((q + 1 <= 7) && (e[q] != 0.0)) {
      qjj = (q + 9 * q) + 2;
      for (qs = q + 1; qs + 1 < 10; qs++) {
        qp1jj = (q + 9 * qs) + 2;
        xaxpy(8 - q, -(xdotc(8 - q, Vf, qjj, Vf, qp1jj) / Vf[qjj - 1]), qjj, Vf,
              qp1jj);
      }
    }

    memset(&Vf[q * 9], 0, 9U * sizeof(double));
    Vf[q + 9 * q] = 1.0;
  }

  for (q = 0; q < 9; q++) {
    nrm = e[q];
    if (b_s[q] != 0.0) {
      rt = std::abs(b_s[q]);
      r = b_s[q] / rt;
      b_s[q] = rt;
      if (q + 1 < 9) {
        nrm = e[q] / r;
      }

      xscal(r, U, 1 + 9 * q);
    }

    if ((q + 1 < 9) && (nrm != 0.0)) {
      rt = std::abs(nrm);
      r = rt / nrm;
      nrm = rt;
      b_s[q + 1] *= r;
      xscal(r, Vf, 1 + 9 * (q + 1));
    }

    e[q] = nrm;
  }

  qq = 0;
  snorm = 0.0;
  for (qp1jj = 0; qp1jj < 9; qp1jj++) {
    nrm = std::abs(b_s[qp1jj]);
    r = std::abs(e[qp1jj]);
    if ((nrm > r) || rtIsNaN(r)) {
    } else {
      nrm = r;
    }

    if (!((snorm > nrm) || rtIsNaN(nrm))) {
      snorm = nrm;
    }
  }

  while ((m + 2 > 0) && (!(qq >= 75))) {
    qp1jj = m;
    do {
      exitg1 = 0;
      q = qp1jj + 1;
      if (qp1jj + 1 == 0) {
        exitg1 = 1;
      } else {
        nrm = std::abs(e[qp1jj]);
        if ((nrm <= 2.2204460492503131E-16 * (std::abs(b_s[qp1jj]) + std::abs
              (b_s[qp1jj + 1]))) || (nrm <= 1.0020841800044864E-292) || ((qq >
              20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[qp1jj] = 0.0;
          exitg1 = 1;
        } else {
          qp1jj--;
        }
      }
    } while (exitg1 == 0);

    if (qp1jj + 1 == m + 1) {
      qjj = 4;
    } else {
      qs = m + 2;
      qjj = m + 2;
      exitg2 = false;
      while ((!exitg2) && (qjj >= qp1jj + 1)) {
        qs = qjj;
        if (qjj == qp1jj + 1) {
          exitg2 = true;
        } else {
          nrm = 0.0;
          if (qjj < m + 2) {
            nrm = std::abs(e[qjj - 1]);
          }

          if (qjj > qp1jj + 2) {
            nrm += std::abs(e[qjj - 2]);
          }

          r = std::abs(b_s[qjj - 1]);
          if ((r <= 2.2204460492503131E-16 * nrm) || (r <=
               1.0020841800044864E-292)) {
            b_s[qjj - 1] = 0.0;
            exitg2 = true;
          } else {
            qjj--;
          }
        }
      }

      if (qs == qp1jj + 1) {
        qjj = 3;
      } else if (qs == m + 2) {
        qjj = 1;
      } else {
        qjj = 2;
        q = qs;
      }
    }

    switch (qjj) {
     case 1:
      f = e[m];
      e[m] = 0.0;
      for (qp1jj = m; qp1jj + 1 >= q + 1; qp1jj--) {
        xrotg(&b_s[qp1jj], &f, &nrm, &r);
        if (qp1jj + 1 > q + 1) {
          f = -r * e[qp1jj - 1];
          e[qp1jj - 1] *= nrm;
        }

        xrot(Vf, 1 + 9 * qp1jj, 1 + 9 * (m + 1), nrm, r);
      }
      break;

     case 2:
      f = e[q - 1];
      e[q - 1] = 0.0;
      for (qp1jj = q; qp1jj < m + 2; qp1jj++) {
        xrotg(&b_s[qp1jj], &f, &nrm, &r);
        f = -r * e[qp1jj];
        e[qp1jj] *= nrm;
        xrot(U, 1 + 9 * qp1jj, 1 + 9 * (q - 1), nrm, r);
      }
      break;

     case 3:
      scale = std::abs(b_s[m + 1]);
      r = std::abs(b_s[m]);
      if (!((scale > r) || rtIsNaN(r))) {
        scale = r;
      }

      r = std::abs(e[m]);
      if (!((scale > r) || rtIsNaN(r))) {
        scale = r;
      }

      r = std::abs(b_s[q]);
      if (!((scale > r) || rtIsNaN(r))) {
        scale = r;
      }

      r = std::abs(e[q]);
      if (!((scale > r) || rtIsNaN(r))) {
        scale = r;
      }

      f = b_s[m + 1] / scale;
      nrm = b_s[m] / scale;
      r = e[m] / scale;
      sqds = b_s[q] / scale;
      rt = ((nrm + f) * (nrm - f) + r * r) / 2.0;
      nrm = f * r;
      nrm *= nrm;
      if ((rt != 0.0) || (nrm != 0.0)) {
        r = rt * rt + nrm;
        b_sqrt(&r);
        if (rt < 0.0) {
          r = -r;
        }

        r = nrm / (rt + r);
      } else {
        r = 0.0;
      }

      f = (sqds + f) * (sqds - f) + r;
      rt = sqds * (e[q] / scale);
      for (qp1jj = q + 1; qp1jj <= m + 1; qp1jj++) {
        xrotg(&f, &rt, &nrm, &r);
        if (qp1jj > q + 1) {
          e[qp1jj - 2] = f;
        }

        f = nrm * b_s[qp1jj - 1] + r * e[qp1jj - 1];
        e[qp1jj - 1] = nrm * e[qp1jj - 1] - r * b_s[qp1jj - 1];
        rt = r * b_s[qp1jj];
        b_s[qp1jj] *= nrm;
        xrot(Vf, 1 + 9 * (qp1jj - 1), 1 + 9 * qp1jj, nrm, r);
        b_s[qp1jj - 1] = f;
        xrotg(&b_s[qp1jj - 1], &rt, &nrm, &r);
        f = nrm * e[qp1jj - 1] + r * b_s[qp1jj];
        b_s[qp1jj] = -r * e[qp1jj - 1] + nrm * b_s[qp1jj];
        rt = r * e[qp1jj];
        e[qp1jj] *= nrm;
        xrot(U, 1 + 9 * (qp1jj - 1), 1 + 9 * qp1jj, nrm, r);
      }

      e[m] = f;
      qq++;
      break;

     default:
      if (b_s[q] < 0.0) {
        b_s[q] = -b_s[q];
        xscal(-1.0, Vf, 1 + 9 * q);
      }

      qjj = q + 1;
      while ((q + 1 < 9) && (b_s[q] < b_s[qjj])) {
        rt = b_s[q];
        b_s[q] = b_s[qjj];
        b_s[qjj] = rt;
        xswap(Vf, 1 + 9 * q, 1 + 9 * (q + 1));
        xswap(U, 1 + 9 * q, 1 + 9 * (q + 1));
        q = qjj;
        qjj++;
      }

      qq = 0;
      m--;
      break;
    }
  }

  for (qp1jj = 0; qp1jj < 9; qp1jj++) {
    s[qp1jj] = b_s[qp1jj];
    memcpy(&V[qp1jj * 9], &Vf[qp1jj * 9], 9U * sizeof(double));
  }
}

/* End of code generation (svd.cpp) */
