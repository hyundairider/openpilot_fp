#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_3072746509555313076);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4286844536936514879);
void car_H_mod_fun(double *state, double *out_3867593001987960466);
void car_f_fun(double *state, double dt, double *out_4327502306778927336);
void car_F_fun(double *state, double dt, double *out_9101312322496333336);
void car_h_25(double *state, double *unused, double *out_5321446089716538159);
void car_H_25(double *state, double *unused, double *out_6504149927003386660);
void car_h_24(double *state, double *unused, double *out_4540984459767932100);
void car_H_24(double *state, double *unused, double *out_2946224328201063524);
void car_h_30(double *state, double *unused, double *out_2559826561037511026);
void car_H_30(double *state, double *unused, double *out_3985816968496138033);
void car_h_26(double *state, double *unused, double *out_4102742174530369835);
void car_H_26(double *state, double *unused, double *out_8201090827832108732);
void car_h_27(double *state, double *unused, double *out_6726256466579164311);
void car_H_27(double *state, double *unused, double *out_1762222897312194816);
void car_h_29(double *state, double *unused, double *out_44578759771186625);
void car_H_29(double *state, double *unused, double *out_3475585624181745849);
void car_h_28(double *state, double *unused, double *out_6718814339469541660);
void car_H_28(double *state, double *unused, double *out_8557984641251276423);
void car_h_31(double *state, double *unused, double *out_1223142791437166295);
void car_H_31(double *state, double *unused, double *out_7574882725598757256);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}