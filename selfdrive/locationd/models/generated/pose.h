#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_4814816550392172101);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6466588547708167171);
void pose_H_mod_fun(double *state, double *out_6289018716856289817);
void pose_f_fun(double *state, double dt, double *out_2810608996408053875);
void pose_F_fun(double *state, double dt, double *out_853953707448176894);
void pose_h_4(double *state, double *unused, double *out_4183473660625043839);
void pose_H_4(double *state, double *unused, double *out_8745371835873163266);
void pose_h_10(double *state, double *unused, double *out_638079796201012561);
void pose_H_10(double *state, double *unused, double *out_3338619363719351940);
void pose_h_13(double *state, double *unused, double *out_672204314443848005);
void pose_H_13(double *state, double *unused, double *out_6489098412504055549);
void pose_h_14(double *state, double *unused, double *out_951178958321836501);
void pose_H_14(double *state, double *unused, double *out_5738131381496903821);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}