#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_3072746509555313076) {
   out_3072746509555313076[0] = delta_x[0] + nom_x[0];
   out_3072746509555313076[1] = delta_x[1] + nom_x[1];
   out_3072746509555313076[2] = delta_x[2] + nom_x[2];
   out_3072746509555313076[3] = delta_x[3] + nom_x[3];
   out_3072746509555313076[4] = delta_x[4] + nom_x[4];
   out_3072746509555313076[5] = delta_x[5] + nom_x[5];
   out_3072746509555313076[6] = delta_x[6] + nom_x[6];
   out_3072746509555313076[7] = delta_x[7] + nom_x[7];
   out_3072746509555313076[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4286844536936514879) {
   out_4286844536936514879[0] = -nom_x[0] + true_x[0];
   out_4286844536936514879[1] = -nom_x[1] + true_x[1];
   out_4286844536936514879[2] = -nom_x[2] + true_x[2];
   out_4286844536936514879[3] = -nom_x[3] + true_x[3];
   out_4286844536936514879[4] = -nom_x[4] + true_x[4];
   out_4286844536936514879[5] = -nom_x[5] + true_x[5];
   out_4286844536936514879[6] = -nom_x[6] + true_x[6];
   out_4286844536936514879[7] = -nom_x[7] + true_x[7];
   out_4286844536936514879[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3867593001987960466) {
   out_3867593001987960466[0] = 1.0;
   out_3867593001987960466[1] = 0.0;
   out_3867593001987960466[2] = 0.0;
   out_3867593001987960466[3] = 0.0;
   out_3867593001987960466[4] = 0.0;
   out_3867593001987960466[5] = 0.0;
   out_3867593001987960466[6] = 0.0;
   out_3867593001987960466[7] = 0.0;
   out_3867593001987960466[8] = 0.0;
   out_3867593001987960466[9] = 0.0;
   out_3867593001987960466[10] = 1.0;
   out_3867593001987960466[11] = 0.0;
   out_3867593001987960466[12] = 0.0;
   out_3867593001987960466[13] = 0.0;
   out_3867593001987960466[14] = 0.0;
   out_3867593001987960466[15] = 0.0;
   out_3867593001987960466[16] = 0.0;
   out_3867593001987960466[17] = 0.0;
   out_3867593001987960466[18] = 0.0;
   out_3867593001987960466[19] = 0.0;
   out_3867593001987960466[20] = 1.0;
   out_3867593001987960466[21] = 0.0;
   out_3867593001987960466[22] = 0.0;
   out_3867593001987960466[23] = 0.0;
   out_3867593001987960466[24] = 0.0;
   out_3867593001987960466[25] = 0.0;
   out_3867593001987960466[26] = 0.0;
   out_3867593001987960466[27] = 0.0;
   out_3867593001987960466[28] = 0.0;
   out_3867593001987960466[29] = 0.0;
   out_3867593001987960466[30] = 1.0;
   out_3867593001987960466[31] = 0.0;
   out_3867593001987960466[32] = 0.0;
   out_3867593001987960466[33] = 0.0;
   out_3867593001987960466[34] = 0.0;
   out_3867593001987960466[35] = 0.0;
   out_3867593001987960466[36] = 0.0;
   out_3867593001987960466[37] = 0.0;
   out_3867593001987960466[38] = 0.0;
   out_3867593001987960466[39] = 0.0;
   out_3867593001987960466[40] = 1.0;
   out_3867593001987960466[41] = 0.0;
   out_3867593001987960466[42] = 0.0;
   out_3867593001987960466[43] = 0.0;
   out_3867593001987960466[44] = 0.0;
   out_3867593001987960466[45] = 0.0;
   out_3867593001987960466[46] = 0.0;
   out_3867593001987960466[47] = 0.0;
   out_3867593001987960466[48] = 0.0;
   out_3867593001987960466[49] = 0.0;
   out_3867593001987960466[50] = 1.0;
   out_3867593001987960466[51] = 0.0;
   out_3867593001987960466[52] = 0.0;
   out_3867593001987960466[53] = 0.0;
   out_3867593001987960466[54] = 0.0;
   out_3867593001987960466[55] = 0.0;
   out_3867593001987960466[56] = 0.0;
   out_3867593001987960466[57] = 0.0;
   out_3867593001987960466[58] = 0.0;
   out_3867593001987960466[59] = 0.0;
   out_3867593001987960466[60] = 1.0;
   out_3867593001987960466[61] = 0.0;
   out_3867593001987960466[62] = 0.0;
   out_3867593001987960466[63] = 0.0;
   out_3867593001987960466[64] = 0.0;
   out_3867593001987960466[65] = 0.0;
   out_3867593001987960466[66] = 0.0;
   out_3867593001987960466[67] = 0.0;
   out_3867593001987960466[68] = 0.0;
   out_3867593001987960466[69] = 0.0;
   out_3867593001987960466[70] = 1.0;
   out_3867593001987960466[71] = 0.0;
   out_3867593001987960466[72] = 0.0;
   out_3867593001987960466[73] = 0.0;
   out_3867593001987960466[74] = 0.0;
   out_3867593001987960466[75] = 0.0;
   out_3867593001987960466[76] = 0.0;
   out_3867593001987960466[77] = 0.0;
   out_3867593001987960466[78] = 0.0;
   out_3867593001987960466[79] = 0.0;
   out_3867593001987960466[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4327502306778927336) {
   out_4327502306778927336[0] = state[0];
   out_4327502306778927336[1] = state[1];
   out_4327502306778927336[2] = state[2];
   out_4327502306778927336[3] = state[3];
   out_4327502306778927336[4] = state[4];
   out_4327502306778927336[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4327502306778927336[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4327502306778927336[7] = state[7];
   out_4327502306778927336[8] = state[8];
}
void F_fun(double *state, double dt, double *out_9101312322496333336) {
   out_9101312322496333336[0] = 1;
   out_9101312322496333336[1] = 0;
   out_9101312322496333336[2] = 0;
   out_9101312322496333336[3] = 0;
   out_9101312322496333336[4] = 0;
   out_9101312322496333336[5] = 0;
   out_9101312322496333336[6] = 0;
   out_9101312322496333336[7] = 0;
   out_9101312322496333336[8] = 0;
   out_9101312322496333336[9] = 0;
   out_9101312322496333336[10] = 1;
   out_9101312322496333336[11] = 0;
   out_9101312322496333336[12] = 0;
   out_9101312322496333336[13] = 0;
   out_9101312322496333336[14] = 0;
   out_9101312322496333336[15] = 0;
   out_9101312322496333336[16] = 0;
   out_9101312322496333336[17] = 0;
   out_9101312322496333336[18] = 0;
   out_9101312322496333336[19] = 0;
   out_9101312322496333336[20] = 1;
   out_9101312322496333336[21] = 0;
   out_9101312322496333336[22] = 0;
   out_9101312322496333336[23] = 0;
   out_9101312322496333336[24] = 0;
   out_9101312322496333336[25] = 0;
   out_9101312322496333336[26] = 0;
   out_9101312322496333336[27] = 0;
   out_9101312322496333336[28] = 0;
   out_9101312322496333336[29] = 0;
   out_9101312322496333336[30] = 1;
   out_9101312322496333336[31] = 0;
   out_9101312322496333336[32] = 0;
   out_9101312322496333336[33] = 0;
   out_9101312322496333336[34] = 0;
   out_9101312322496333336[35] = 0;
   out_9101312322496333336[36] = 0;
   out_9101312322496333336[37] = 0;
   out_9101312322496333336[38] = 0;
   out_9101312322496333336[39] = 0;
   out_9101312322496333336[40] = 1;
   out_9101312322496333336[41] = 0;
   out_9101312322496333336[42] = 0;
   out_9101312322496333336[43] = 0;
   out_9101312322496333336[44] = 0;
   out_9101312322496333336[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_9101312322496333336[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_9101312322496333336[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_9101312322496333336[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_9101312322496333336[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_9101312322496333336[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_9101312322496333336[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_9101312322496333336[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_9101312322496333336[53] = -9.8100000000000005*dt;
   out_9101312322496333336[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_9101312322496333336[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_9101312322496333336[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_9101312322496333336[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_9101312322496333336[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_9101312322496333336[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_9101312322496333336[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_9101312322496333336[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_9101312322496333336[62] = 0;
   out_9101312322496333336[63] = 0;
   out_9101312322496333336[64] = 0;
   out_9101312322496333336[65] = 0;
   out_9101312322496333336[66] = 0;
   out_9101312322496333336[67] = 0;
   out_9101312322496333336[68] = 0;
   out_9101312322496333336[69] = 0;
   out_9101312322496333336[70] = 1;
   out_9101312322496333336[71] = 0;
   out_9101312322496333336[72] = 0;
   out_9101312322496333336[73] = 0;
   out_9101312322496333336[74] = 0;
   out_9101312322496333336[75] = 0;
   out_9101312322496333336[76] = 0;
   out_9101312322496333336[77] = 0;
   out_9101312322496333336[78] = 0;
   out_9101312322496333336[79] = 0;
   out_9101312322496333336[80] = 1;
}
void h_25(double *state, double *unused, double *out_5321446089716538159) {
   out_5321446089716538159[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6504149927003386660) {
   out_6504149927003386660[0] = 0;
   out_6504149927003386660[1] = 0;
   out_6504149927003386660[2] = 0;
   out_6504149927003386660[3] = 0;
   out_6504149927003386660[4] = 0;
   out_6504149927003386660[5] = 0;
   out_6504149927003386660[6] = 1;
   out_6504149927003386660[7] = 0;
   out_6504149927003386660[8] = 0;
}
void h_24(double *state, double *unused, double *out_4540984459767932100) {
   out_4540984459767932100[0] = state[4];
   out_4540984459767932100[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2946224328201063524) {
   out_2946224328201063524[0] = 0;
   out_2946224328201063524[1] = 0;
   out_2946224328201063524[2] = 0;
   out_2946224328201063524[3] = 0;
   out_2946224328201063524[4] = 1;
   out_2946224328201063524[5] = 0;
   out_2946224328201063524[6] = 0;
   out_2946224328201063524[7] = 0;
   out_2946224328201063524[8] = 0;
   out_2946224328201063524[9] = 0;
   out_2946224328201063524[10] = 0;
   out_2946224328201063524[11] = 0;
   out_2946224328201063524[12] = 0;
   out_2946224328201063524[13] = 0;
   out_2946224328201063524[14] = 1;
   out_2946224328201063524[15] = 0;
   out_2946224328201063524[16] = 0;
   out_2946224328201063524[17] = 0;
}
void h_30(double *state, double *unused, double *out_2559826561037511026) {
   out_2559826561037511026[0] = state[4];
}
void H_30(double *state, double *unused, double *out_3985816968496138033) {
   out_3985816968496138033[0] = 0;
   out_3985816968496138033[1] = 0;
   out_3985816968496138033[2] = 0;
   out_3985816968496138033[3] = 0;
   out_3985816968496138033[4] = 1;
   out_3985816968496138033[5] = 0;
   out_3985816968496138033[6] = 0;
   out_3985816968496138033[7] = 0;
   out_3985816968496138033[8] = 0;
}
void h_26(double *state, double *unused, double *out_4102742174530369835) {
   out_4102742174530369835[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8201090827832108732) {
   out_8201090827832108732[0] = 0;
   out_8201090827832108732[1] = 0;
   out_8201090827832108732[2] = 0;
   out_8201090827832108732[3] = 0;
   out_8201090827832108732[4] = 0;
   out_8201090827832108732[5] = 0;
   out_8201090827832108732[6] = 0;
   out_8201090827832108732[7] = 1;
   out_8201090827832108732[8] = 0;
}
void h_27(double *state, double *unused, double *out_6726256466579164311) {
   out_6726256466579164311[0] = state[3];
}
void H_27(double *state, double *unused, double *out_1762222897312194816) {
   out_1762222897312194816[0] = 0;
   out_1762222897312194816[1] = 0;
   out_1762222897312194816[2] = 0;
   out_1762222897312194816[3] = 1;
   out_1762222897312194816[4] = 0;
   out_1762222897312194816[5] = 0;
   out_1762222897312194816[6] = 0;
   out_1762222897312194816[7] = 0;
   out_1762222897312194816[8] = 0;
}
void h_29(double *state, double *unused, double *out_44578759771186625) {
   out_44578759771186625[0] = state[1];
}
void H_29(double *state, double *unused, double *out_3475585624181745849) {
   out_3475585624181745849[0] = 0;
   out_3475585624181745849[1] = 1;
   out_3475585624181745849[2] = 0;
   out_3475585624181745849[3] = 0;
   out_3475585624181745849[4] = 0;
   out_3475585624181745849[5] = 0;
   out_3475585624181745849[6] = 0;
   out_3475585624181745849[7] = 0;
   out_3475585624181745849[8] = 0;
}
void h_28(double *state, double *unused, double *out_6718814339469541660) {
   out_6718814339469541660[0] = state[0];
}
void H_28(double *state, double *unused, double *out_8557984641251276423) {
   out_8557984641251276423[0] = 1;
   out_8557984641251276423[1] = 0;
   out_8557984641251276423[2] = 0;
   out_8557984641251276423[3] = 0;
   out_8557984641251276423[4] = 0;
   out_8557984641251276423[5] = 0;
   out_8557984641251276423[6] = 0;
   out_8557984641251276423[7] = 0;
   out_8557984641251276423[8] = 0;
}
void h_31(double *state, double *unused, double *out_1223142791437166295) {
   out_1223142791437166295[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7574882725598757256) {
   out_7574882725598757256[0] = 0;
   out_7574882725598757256[1] = 0;
   out_7574882725598757256[2] = 0;
   out_7574882725598757256[3] = 0;
   out_7574882725598757256[4] = 0;
   out_7574882725598757256[5] = 0;
   out_7574882725598757256[6] = 0;
   out_7574882725598757256[7] = 0;
   out_7574882725598757256[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_3072746509555313076) {
  err_fun(nom_x, delta_x, out_3072746509555313076);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4286844536936514879) {
  inv_err_fun(nom_x, true_x, out_4286844536936514879);
}
void car_H_mod_fun(double *state, double *out_3867593001987960466) {
  H_mod_fun(state, out_3867593001987960466);
}
void car_f_fun(double *state, double dt, double *out_4327502306778927336) {
  f_fun(state,  dt, out_4327502306778927336);
}
void car_F_fun(double *state, double dt, double *out_9101312322496333336) {
  F_fun(state,  dt, out_9101312322496333336);
}
void car_h_25(double *state, double *unused, double *out_5321446089716538159) {
  h_25(state, unused, out_5321446089716538159);
}
void car_H_25(double *state, double *unused, double *out_6504149927003386660) {
  H_25(state, unused, out_6504149927003386660);
}
void car_h_24(double *state, double *unused, double *out_4540984459767932100) {
  h_24(state, unused, out_4540984459767932100);
}
void car_H_24(double *state, double *unused, double *out_2946224328201063524) {
  H_24(state, unused, out_2946224328201063524);
}
void car_h_30(double *state, double *unused, double *out_2559826561037511026) {
  h_30(state, unused, out_2559826561037511026);
}
void car_H_30(double *state, double *unused, double *out_3985816968496138033) {
  H_30(state, unused, out_3985816968496138033);
}
void car_h_26(double *state, double *unused, double *out_4102742174530369835) {
  h_26(state, unused, out_4102742174530369835);
}
void car_H_26(double *state, double *unused, double *out_8201090827832108732) {
  H_26(state, unused, out_8201090827832108732);
}
void car_h_27(double *state, double *unused, double *out_6726256466579164311) {
  h_27(state, unused, out_6726256466579164311);
}
void car_H_27(double *state, double *unused, double *out_1762222897312194816) {
  H_27(state, unused, out_1762222897312194816);
}
void car_h_29(double *state, double *unused, double *out_44578759771186625) {
  h_29(state, unused, out_44578759771186625);
}
void car_H_29(double *state, double *unused, double *out_3475585624181745849) {
  H_29(state, unused, out_3475585624181745849);
}
void car_h_28(double *state, double *unused, double *out_6718814339469541660) {
  h_28(state, unused, out_6718814339469541660);
}
void car_H_28(double *state, double *unused, double *out_8557984641251276423) {
  H_28(state, unused, out_8557984641251276423);
}
void car_h_31(double *state, double *unused, double *out_1223142791437166295) {
  h_31(state, unused, out_1223142791437166295);
}
void car_H_31(double *state, double *unused, double *out_7574882725598757256) {
  H_31(state, unused, out_7574882725598757256);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
