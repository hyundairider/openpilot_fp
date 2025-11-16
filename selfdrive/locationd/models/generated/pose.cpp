#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4814816550392172101) {
   out_4814816550392172101[0] = delta_x[0] + nom_x[0];
   out_4814816550392172101[1] = delta_x[1] + nom_x[1];
   out_4814816550392172101[2] = delta_x[2] + nom_x[2];
   out_4814816550392172101[3] = delta_x[3] + nom_x[3];
   out_4814816550392172101[4] = delta_x[4] + nom_x[4];
   out_4814816550392172101[5] = delta_x[5] + nom_x[5];
   out_4814816550392172101[6] = delta_x[6] + nom_x[6];
   out_4814816550392172101[7] = delta_x[7] + nom_x[7];
   out_4814816550392172101[8] = delta_x[8] + nom_x[8];
   out_4814816550392172101[9] = delta_x[9] + nom_x[9];
   out_4814816550392172101[10] = delta_x[10] + nom_x[10];
   out_4814816550392172101[11] = delta_x[11] + nom_x[11];
   out_4814816550392172101[12] = delta_x[12] + nom_x[12];
   out_4814816550392172101[13] = delta_x[13] + nom_x[13];
   out_4814816550392172101[14] = delta_x[14] + nom_x[14];
   out_4814816550392172101[15] = delta_x[15] + nom_x[15];
   out_4814816550392172101[16] = delta_x[16] + nom_x[16];
   out_4814816550392172101[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6466588547708167171) {
   out_6466588547708167171[0] = -nom_x[0] + true_x[0];
   out_6466588547708167171[1] = -nom_x[1] + true_x[1];
   out_6466588547708167171[2] = -nom_x[2] + true_x[2];
   out_6466588547708167171[3] = -nom_x[3] + true_x[3];
   out_6466588547708167171[4] = -nom_x[4] + true_x[4];
   out_6466588547708167171[5] = -nom_x[5] + true_x[5];
   out_6466588547708167171[6] = -nom_x[6] + true_x[6];
   out_6466588547708167171[7] = -nom_x[7] + true_x[7];
   out_6466588547708167171[8] = -nom_x[8] + true_x[8];
   out_6466588547708167171[9] = -nom_x[9] + true_x[9];
   out_6466588547708167171[10] = -nom_x[10] + true_x[10];
   out_6466588547708167171[11] = -nom_x[11] + true_x[11];
   out_6466588547708167171[12] = -nom_x[12] + true_x[12];
   out_6466588547708167171[13] = -nom_x[13] + true_x[13];
   out_6466588547708167171[14] = -nom_x[14] + true_x[14];
   out_6466588547708167171[15] = -nom_x[15] + true_x[15];
   out_6466588547708167171[16] = -nom_x[16] + true_x[16];
   out_6466588547708167171[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_6289018716856289817) {
   out_6289018716856289817[0] = 1.0;
   out_6289018716856289817[1] = 0.0;
   out_6289018716856289817[2] = 0.0;
   out_6289018716856289817[3] = 0.0;
   out_6289018716856289817[4] = 0.0;
   out_6289018716856289817[5] = 0.0;
   out_6289018716856289817[6] = 0.0;
   out_6289018716856289817[7] = 0.0;
   out_6289018716856289817[8] = 0.0;
   out_6289018716856289817[9] = 0.0;
   out_6289018716856289817[10] = 0.0;
   out_6289018716856289817[11] = 0.0;
   out_6289018716856289817[12] = 0.0;
   out_6289018716856289817[13] = 0.0;
   out_6289018716856289817[14] = 0.0;
   out_6289018716856289817[15] = 0.0;
   out_6289018716856289817[16] = 0.0;
   out_6289018716856289817[17] = 0.0;
   out_6289018716856289817[18] = 0.0;
   out_6289018716856289817[19] = 1.0;
   out_6289018716856289817[20] = 0.0;
   out_6289018716856289817[21] = 0.0;
   out_6289018716856289817[22] = 0.0;
   out_6289018716856289817[23] = 0.0;
   out_6289018716856289817[24] = 0.0;
   out_6289018716856289817[25] = 0.0;
   out_6289018716856289817[26] = 0.0;
   out_6289018716856289817[27] = 0.0;
   out_6289018716856289817[28] = 0.0;
   out_6289018716856289817[29] = 0.0;
   out_6289018716856289817[30] = 0.0;
   out_6289018716856289817[31] = 0.0;
   out_6289018716856289817[32] = 0.0;
   out_6289018716856289817[33] = 0.0;
   out_6289018716856289817[34] = 0.0;
   out_6289018716856289817[35] = 0.0;
   out_6289018716856289817[36] = 0.0;
   out_6289018716856289817[37] = 0.0;
   out_6289018716856289817[38] = 1.0;
   out_6289018716856289817[39] = 0.0;
   out_6289018716856289817[40] = 0.0;
   out_6289018716856289817[41] = 0.0;
   out_6289018716856289817[42] = 0.0;
   out_6289018716856289817[43] = 0.0;
   out_6289018716856289817[44] = 0.0;
   out_6289018716856289817[45] = 0.0;
   out_6289018716856289817[46] = 0.0;
   out_6289018716856289817[47] = 0.0;
   out_6289018716856289817[48] = 0.0;
   out_6289018716856289817[49] = 0.0;
   out_6289018716856289817[50] = 0.0;
   out_6289018716856289817[51] = 0.0;
   out_6289018716856289817[52] = 0.0;
   out_6289018716856289817[53] = 0.0;
   out_6289018716856289817[54] = 0.0;
   out_6289018716856289817[55] = 0.0;
   out_6289018716856289817[56] = 0.0;
   out_6289018716856289817[57] = 1.0;
   out_6289018716856289817[58] = 0.0;
   out_6289018716856289817[59] = 0.0;
   out_6289018716856289817[60] = 0.0;
   out_6289018716856289817[61] = 0.0;
   out_6289018716856289817[62] = 0.0;
   out_6289018716856289817[63] = 0.0;
   out_6289018716856289817[64] = 0.0;
   out_6289018716856289817[65] = 0.0;
   out_6289018716856289817[66] = 0.0;
   out_6289018716856289817[67] = 0.0;
   out_6289018716856289817[68] = 0.0;
   out_6289018716856289817[69] = 0.0;
   out_6289018716856289817[70] = 0.0;
   out_6289018716856289817[71] = 0.0;
   out_6289018716856289817[72] = 0.0;
   out_6289018716856289817[73] = 0.0;
   out_6289018716856289817[74] = 0.0;
   out_6289018716856289817[75] = 0.0;
   out_6289018716856289817[76] = 1.0;
   out_6289018716856289817[77] = 0.0;
   out_6289018716856289817[78] = 0.0;
   out_6289018716856289817[79] = 0.0;
   out_6289018716856289817[80] = 0.0;
   out_6289018716856289817[81] = 0.0;
   out_6289018716856289817[82] = 0.0;
   out_6289018716856289817[83] = 0.0;
   out_6289018716856289817[84] = 0.0;
   out_6289018716856289817[85] = 0.0;
   out_6289018716856289817[86] = 0.0;
   out_6289018716856289817[87] = 0.0;
   out_6289018716856289817[88] = 0.0;
   out_6289018716856289817[89] = 0.0;
   out_6289018716856289817[90] = 0.0;
   out_6289018716856289817[91] = 0.0;
   out_6289018716856289817[92] = 0.0;
   out_6289018716856289817[93] = 0.0;
   out_6289018716856289817[94] = 0.0;
   out_6289018716856289817[95] = 1.0;
   out_6289018716856289817[96] = 0.0;
   out_6289018716856289817[97] = 0.0;
   out_6289018716856289817[98] = 0.0;
   out_6289018716856289817[99] = 0.0;
   out_6289018716856289817[100] = 0.0;
   out_6289018716856289817[101] = 0.0;
   out_6289018716856289817[102] = 0.0;
   out_6289018716856289817[103] = 0.0;
   out_6289018716856289817[104] = 0.0;
   out_6289018716856289817[105] = 0.0;
   out_6289018716856289817[106] = 0.0;
   out_6289018716856289817[107] = 0.0;
   out_6289018716856289817[108] = 0.0;
   out_6289018716856289817[109] = 0.0;
   out_6289018716856289817[110] = 0.0;
   out_6289018716856289817[111] = 0.0;
   out_6289018716856289817[112] = 0.0;
   out_6289018716856289817[113] = 0.0;
   out_6289018716856289817[114] = 1.0;
   out_6289018716856289817[115] = 0.0;
   out_6289018716856289817[116] = 0.0;
   out_6289018716856289817[117] = 0.0;
   out_6289018716856289817[118] = 0.0;
   out_6289018716856289817[119] = 0.0;
   out_6289018716856289817[120] = 0.0;
   out_6289018716856289817[121] = 0.0;
   out_6289018716856289817[122] = 0.0;
   out_6289018716856289817[123] = 0.0;
   out_6289018716856289817[124] = 0.0;
   out_6289018716856289817[125] = 0.0;
   out_6289018716856289817[126] = 0.0;
   out_6289018716856289817[127] = 0.0;
   out_6289018716856289817[128] = 0.0;
   out_6289018716856289817[129] = 0.0;
   out_6289018716856289817[130] = 0.0;
   out_6289018716856289817[131] = 0.0;
   out_6289018716856289817[132] = 0.0;
   out_6289018716856289817[133] = 1.0;
   out_6289018716856289817[134] = 0.0;
   out_6289018716856289817[135] = 0.0;
   out_6289018716856289817[136] = 0.0;
   out_6289018716856289817[137] = 0.0;
   out_6289018716856289817[138] = 0.0;
   out_6289018716856289817[139] = 0.0;
   out_6289018716856289817[140] = 0.0;
   out_6289018716856289817[141] = 0.0;
   out_6289018716856289817[142] = 0.0;
   out_6289018716856289817[143] = 0.0;
   out_6289018716856289817[144] = 0.0;
   out_6289018716856289817[145] = 0.0;
   out_6289018716856289817[146] = 0.0;
   out_6289018716856289817[147] = 0.0;
   out_6289018716856289817[148] = 0.0;
   out_6289018716856289817[149] = 0.0;
   out_6289018716856289817[150] = 0.0;
   out_6289018716856289817[151] = 0.0;
   out_6289018716856289817[152] = 1.0;
   out_6289018716856289817[153] = 0.0;
   out_6289018716856289817[154] = 0.0;
   out_6289018716856289817[155] = 0.0;
   out_6289018716856289817[156] = 0.0;
   out_6289018716856289817[157] = 0.0;
   out_6289018716856289817[158] = 0.0;
   out_6289018716856289817[159] = 0.0;
   out_6289018716856289817[160] = 0.0;
   out_6289018716856289817[161] = 0.0;
   out_6289018716856289817[162] = 0.0;
   out_6289018716856289817[163] = 0.0;
   out_6289018716856289817[164] = 0.0;
   out_6289018716856289817[165] = 0.0;
   out_6289018716856289817[166] = 0.0;
   out_6289018716856289817[167] = 0.0;
   out_6289018716856289817[168] = 0.0;
   out_6289018716856289817[169] = 0.0;
   out_6289018716856289817[170] = 0.0;
   out_6289018716856289817[171] = 1.0;
   out_6289018716856289817[172] = 0.0;
   out_6289018716856289817[173] = 0.0;
   out_6289018716856289817[174] = 0.0;
   out_6289018716856289817[175] = 0.0;
   out_6289018716856289817[176] = 0.0;
   out_6289018716856289817[177] = 0.0;
   out_6289018716856289817[178] = 0.0;
   out_6289018716856289817[179] = 0.0;
   out_6289018716856289817[180] = 0.0;
   out_6289018716856289817[181] = 0.0;
   out_6289018716856289817[182] = 0.0;
   out_6289018716856289817[183] = 0.0;
   out_6289018716856289817[184] = 0.0;
   out_6289018716856289817[185] = 0.0;
   out_6289018716856289817[186] = 0.0;
   out_6289018716856289817[187] = 0.0;
   out_6289018716856289817[188] = 0.0;
   out_6289018716856289817[189] = 0.0;
   out_6289018716856289817[190] = 1.0;
   out_6289018716856289817[191] = 0.0;
   out_6289018716856289817[192] = 0.0;
   out_6289018716856289817[193] = 0.0;
   out_6289018716856289817[194] = 0.0;
   out_6289018716856289817[195] = 0.0;
   out_6289018716856289817[196] = 0.0;
   out_6289018716856289817[197] = 0.0;
   out_6289018716856289817[198] = 0.0;
   out_6289018716856289817[199] = 0.0;
   out_6289018716856289817[200] = 0.0;
   out_6289018716856289817[201] = 0.0;
   out_6289018716856289817[202] = 0.0;
   out_6289018716856289817[203] = 0.0;
   out_6289018716856289817[204] = 0.0;
   out_6289018716856289817[205] = 0.0;
   out_6289018716856289817[206] = 0.0;
   out_6289018716856289817[207] = 0.0;
   out_6289018716856289817[208] = 0.0;
   out_6289018716856289817[209] = 1.0;
   out_6289018716856289817[210] = 0.0;
   out_6289018716856289817[211] = 0.0;
   out_6289018716856289817[212] = 0.0;
   out_6289018716856289817[213] = 0.0;
   out_6289018716856289817[214] = 0.0;
   out_6289018716856289817[215] = 0.0;
   out_6289018716856289817[216] = 0.0;
   out_6289018716856289817[217] = 0.0;
   out_6289018716856289817[218] = 0.0;
   out_6289018716856289817[219] = 0.0;
   out_6289018716856289817[220] = 0.0;
   out_6289018716856289817[221] = 0.0;
   out_6289018716856289817[222] = 0.0;
   out_6289018716856289817[223] = 0.0;
   out_6289018716856289817[224] = 0.0;
   out_6289018716856289817[225] = 0.0;
   out_6289018716856289817[226] = 0.0;
   out_6289018716856289817[227] = 0.0;
   out_6289018716856289817[228] = 1.0;
   out_6289018716856289817[229] = 0.0;
   out_6289018716856289817[230] = 0.0;
   out_6289018716856289817[231] = 0.0;
   out_6289018716856289817[232] = 0.0;
   out_6289018716856289817[233] = 0.0;
   out_6289018716856289817[234] = 0.0;
   out_6289018716856289817[235] = 0.0;
   out_6289018716856289817[236] = 0.0;
   out_6289018716856289817[237] = 0.0;
   out_6289018716856289817[238] = 0.0;
   out_6289018716856289817[239] = 0.0;
   out_6289018716856289817[240] = 0.0;
   out_6289018716856289817[241] = 0.0;
   out_6289018716856289817[242] = 0.0;
   out_6289018716856289817[243] = 0.0;
   out_6289018716856289817[244] = 0.0;
   out_6289018716856289817[245] = 0.0;
   out_6289018716856289817[246] = 0.0;
   out_6289018716856289817[247] = 1.0;
   out_6289018716856289817[248] = 0.0;
   out_6289018716856289817[249] = 0.0;
   out_6289018716856289817[250] = 0.0;
   out_6289018716856289817[251] = 0.0;
   out_6289018716856289817[252] = 0.0;
   out_6289018716856289817[253] = 0.0;
   out_6289018716856289817[254] = 0.0;
   out_6289018716856289817[255] = 0.0;
   out_6289018716856289817[256] = 0.0;
   out_6289018716856289817[257] = 0.0;
   out_6289018716856289817[258] = 0.0;
   out_6289018716856289817[259] = 0.0;
   out_6289018716856289817[260] = 0.0;
   out_6289018716856289817[261] = 0.0;
   out_6289018716856289817[262] = 0.0;
   out_6289018716856289817[263] = 0.0;
   out_6289018716856289817[264] = 0.0;
   out_6289018716856289817[265] = 0.0;
   out_6289018716856289817[266] = 1.0;
   out_6289018716856289817[267] = 0.0;
   out_6289018716856289817[268] = 0.0;
   out_6289018716856289817[269] = 0.0;
   out_6289018716856289817[270] = 0.0;
   out_6289018716856289817[271] = 0.0;
   out_6289018716856289817[272] = 0.0;
   out_6289018716856289817[273] = 0.0;
   out_6289018716856289817[274] = 0.0;
   out_6289018716856289817[275] = 0.0;
   out_6289018716856289817[276] = 0.0;
   out_6289018716856289817[277] = 0.0;
   out_6289018716856289817[278] = 0.0;
   out_6289018716856289817[279] = 0.0;
   out_6289018716856289817[280] = 0.0;
   out_6289018716856289817[281] = 0.0;
   out_6289018716856289817[282] = 0.0;
   out_6289018716856289817[283] = 0.0;
   out_6289018716856289817[284] = 0.0;
   out_6289018716856289817[285] = 1.0;
   out_6289018716856289817[286] = 0.0;
   out_6289018716856289817[287] = 0.0;
   out_6289018716856289817[288] = 0.0;
   out_6289018716856289817[289] = 0.0;
   out_6289018716856289817[290] = 0.0;
   out_6289018716856289817[291] = 0.0;
   out_6289018716856289817[292] = 0.0;
   out_6289018716856289817[293] = 0.0;
   out_6289018716856289817[294] = 0.0;
   out_6289018716856289817[295] = 0.0;
   out_6289018716856289817[296] = 0.0;
   out_6289018716856289817[297] = 0.0;
   out_6289018716856289817[298] = 0.0;
   out_6289018716856289817[299] = 0.0;
   out_6289018716856289817[300] = 0.0;
   out_6289018716856289817[301] = 0.0;
   out_6289018716856289817[302] = 0.0;
   out_6289018716856289817[303] = 0.0;
   out_6289018716856289817[304] = 1.0;
   out_6289018716856289817[305] = 0.0;
   out_6289018716856289817[306] = 0.0;
   out_6289018716856289817[307] = 0.0;
   out_6289018716856289817[308] = 0.0;
   out_6289018716856289817[309] = 0.0;
   out_6289018716856289817[310] = 0.0;
   out_6289018716856289817[311] = 0.0;
   out_6289018716856289817[312] = 0.0;
   out_6289018716856289817[313] = 0.0;
   out_6289018716856289817[314] = 0.0;
   out_6289018716856289817[315] = 0.0;
   out_6289018716856289817[316] = 0.0;
   out_6289018716856289817[317] = 0.0;
   out_6289018716856289817[318] = 0.0;
   out_6289018716856289817[319] = 0.0;
   out_6289018716856289817[320] = 0.0;
   out_6289018716856289817[321] = 0.0;
   out_6289018716856289817[322] = 0.0;
   out_6289018716856289817[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_2810608996408053875) {
   out_2810608996408053875[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_2810608996408053875[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_2810608996408053875[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_2810608996408053875[3] = dt*state[12] + state[3];
   out_2810608996408053875[4] = dt*state[13] + state[4];
   out_2810608996408053875[5] = dt*state[14] + state[5];
   out_2810608996408053875[6] = state[6];
   out_2810608996408053875[7] = state[7];
   out_2810608996408053875[8] = state[8];
   out_2810608996408053875[9] = state[9];
   out_2810608996408053875[10] = state[10];
   out_2810608996408053875[11] = state[11];
   out_2810608996408053875[12] = state[12];
   out_2810608996408053875[13] = state[13];
   out_2810608996408053875[14] = state[14];
   out_2810608996408053875[15] = state[15];
   out_2810608996408053875[16] = state[16];
   out_2810608996408053875[17] = state[17];
}
void F_fun(double *state, double dt, double *out_853953707448176894) {
   out_853953707448176894[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_853953707448176894[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_853953707448176894[2] = 0;
   out_853953707448176894[3] = 0;
   out_853953707448176894[4] = 0;
   out_853953707448176894[5] = 0;
   out_853953707448176894[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_853953707448176894[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_853953707448176894[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_853953707448176894[9] = 0;
   out_853953707448176894[10] = 0;
   out_853953707448176894[11] = 0;
   out_853953707448176894[12] = 0;
   out_853953707448176894[13] = 0;
   out_853953707448176894[14] = 0;
   out_853953707448176894[15] = 0;
   out_853953707448176894[16] = 0;
   out_853953707448176894[17] = 0;
   out_853953707448176894[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_853953707448176894[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_853953707448176894[20] = 0;
   out_853953707448176894[21] = 0;
   out_853953707448176894[22] = 0;
   out_853953707448176894[23] = 0;
   out_853953707448176894[24] = 0;
   out_853953707448176894[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_853953707448176894[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_853953707448176894[27] = 0;
   out_853953707448176894[28] = 0;
   out_853953707448176894[29] = 0;
   out_853953707448176894[30] = 0;
   out_853953707448176894[31] = 0;
   out_853953707448176894[32] = 0;
   out_853953707448176894[33] = 0;
   out_853953707448176894[34] = 0;
   out_853953707448176894[35] = 0;
   out_853953707448176894[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_853953707448176894[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_853953707448176894[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_853953707448176894[39] = 0;
   out_853953707448176894[40] = 0;
   out_853953707448176894[41] = 0;
   out_853953707448176894[42] = 0;
   out_853953707448176894[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_853953707448176894[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_853953707448176894[45] = 0;
   out_853953707448176894[46] = 0;
   out_853953707448176894[47] = 0;
   out_853953707448176894[48] = 0;
   out_853953707448176894[49] = 0;
   out_853953707448176894[50] = 0;
   out_853953707448176894[51] = 0;
   out_853953707448176894[52] = 0;
   out_853953707448176894[53] = 0;
   out_853953707448176894[54] = 0;
   out_853953707448176894[55] = 0;
   out_853953707448176894[56] = 0;
   out_853953707448176894[57] = 1;
   out_853953707448176894[58] = 0;
   out_853953707448176894[59] = 0;
   out_853953707448176894[60] = 0;
   out_853953707448176894[61] = 0;
   out_853953707448176894[62] = 0;
   out_853953707448176894[63] = 0;
   out_853953707448176894[64] = 0;
   out_853953707448176894[65] = 0;
   out_853953707448176894[66] = dt;
   out_853953707448176894[67] = 0;
   out_853953707448176894[68] = 0;
   out_853953707448176894[69] = 0;
   out_853953707448176894[70] = 0;
   out_853953707448176894[71] = 0;
   out_853953707448176894[72] = 0;
   out_853953707448176894[73] = 0;
   out_853953707448176894[74] = 0;
   out_853953707448176894[75] = 0;
   out_853953707448176894[76] = 1;
   out_853953707448176894[77] = 0;
   out_853953707448176894[78] = 0;
   out_853953707448176894[79] = 0;
   out_853953707448176894[80] = 0;
   out_853953707448176894[81] = 0;
   out_853953707448176894[82] = 0;
   out_853953707448176894[83] = 0;
   out_853953707448176894[84] = 0;
   out_853953707448176894[85] = dt;
   out_853953707448176894[86] = 0;
   out_853953707448176894[87] = 0;
   out_853953707448176894[88] = 0;
   out_853953707448176894[89] = 0;
   out_853953707448176894[90] = 0;
   out_853953707448176894[91] = 0;
   out_853953707448176894[92] = 0;
   out_853953707448176894[93] = 0;
   out_853953707448176894[94] = 0;
   out_853953707448176894[95] = 1;
   out_853953707448176894[96] = 0;
   out_853953707448176894[97] = 0;
   out_853953707448176894[98] = 0;
   out_853953707448176894[99] = 0;
   out_853953707448176894[100] = 0;
   out_853953707448176894[101] = 0;
   out_853953707448176894[102] = 0;
   out_853953707448176894[103] = 0;
   out_853953707448176894[104] = dt;
   out_853953707448176894[105] = 0;
   out_853953707448176894[106] = 0;
   out_853953707448176894[107] = 0;
   out_853953707448176894[108] = 0;
   out_853953707448176894[109] = 0;
   out_853953707448176894[110] = 0;
   out_853953707448176894[111] = 0;
   out_853953707448176894[112] = 0;
   out_853953707448176894[113] = 0;
   out_853953707448176894[114] = 1;
   out_853953707448176894[115] = 0;
   out_853953707448176894[116] = 0;
   out_853953707448176894[117] = 0;
   out_853953707448176894[118] = 0;
   out_853953707448176894[119] = 0;
   out_853953707448176894[120] = 0;
   out_853953707448176894[121] = 0;
   out_853953707448176894[122] = 0;
   out_853953707448176894[123] = 0;
   out_853953707448176894[124] = 0;
   out_853953707448176894[125] = 0;
   out_853953707448176894[126] = 0;
   out_853953707448176894[127] = 0;
   out_853953707448176894[128] = 0;
   out_853953707448176894[129] = 0;
   out_853953707448176894[130] = 0;
   out_853953707448176894[131] = 0;
   out_853953707448176894[132] = 0;
   out_853953707448176894[133] = 1;
   out_853953707448176894[134] = 0;
   out_853953707448176894[135] = 0;
   out_853953707448176894[136] = 0;
   out_853953707448176894[137] = 0;
   out_853953707448176894[138] = 0;
   out_853953707448176894[139] = 0;
   out_853953707448176894[140] = 0;
   out_853953707448176894[141] = 0;
   out_853953707448176894[142] = 0;
   out_853953707448176894[143] = 0;
   out_853953707448176894[144] = 0;
   out_853953707448176894[145] = 0;
   out_853953707448176894[146] = 0;
   out_853953707448176894[147] = 0;
   out_853953707448176894[148] = 0;
   out_853953707448176894[149] = 0;
   out_853953707448176894[150] = 0;
   out_853953707448176894[151] = 0;
   out_853953707448176894[152] = 1;
   out_853953707448176894[153] = 0;
   out_853953707448176894[154] = 0;
   out_853953707448176894[155] = 0;
   out_853953707448176894[156] = 0;
   out_853953707448176894[157] = 0;
   out_853953707448176894[158] = 0;
   out_853953707448176894[159] = 0;
   out_853953707448176894[160] = 0;
   out_853953707448176894[161] = 0;
   out_853953707448176894[162] = 0;
   out_853953707448176894[163] = 0;
   out_853953707448176894[164] = 0;
   out_853953707448176894[165] = 0;
   out_853953707448176894[166] = 0;
   out_853953707448176894[167] = 0;
   out_853953707448176894[168] = 0;
   out_853953707448176894[169] = 0;
   out_853953707448176894[170] = 0;
   out_853953707448176894[171] = 1;
   out_853953707448176894[172] = 0;
   out_853953707448176894[173] = 0;
   out_853953707448176894[174] = 0;
   out_853953707448176894[175] = 0;
   out_853953707448176894[176] = 0;
   out_853953707448176894[177] = 0;
   out_853953707448176894[178] = 0;
   out_853953707448176894[179] = 0;
   out_853953707448176894[180] = 0;
   out_853953707448176894[181] = 0;
   out_853953707448176894[182] = 0;
   out_853953707448176894[183] = 0;
   out_853953707448176894[184] = 0;
   out_853953707448176894[185] = 0;
   out_853953707448176894[186] = 0;
   out_853953707448176894[187] = 0;
   out_853953707448176894[188] = 0;
   out_853953707448176894[189] = 0;
   out_853953707448176894[190] = 1;
   out_853953707448176894[191] = 0;
   out_853953707448176894[192] = 0;
   out_853953707448176894[193] = 0;
   out_853953707448176894[194] = 0;
   out_853953707448176894[195] = 0;
   out_853953707448176894[196] = 0;
   out_853953707448176894[197] = 0;
   out_853953707448176894[198] = 0;
   out_853953707448176894[199] = 0;
   out_853953707448176894[200] = 0;
   out_853953707448176894[201] = 0;
   out_853953707448176894[202] = 0;
   out_853953707448176894[203] = 0;
   out_853953707448176894[204] = 0;
   out_853953707448176894[205] = 0;
   out_853953707448176894[206] = 0;
   out_853953707448176894[207] = 0;
   out_853953707448176894[208] = 0;
   out_853953707448176894[209] = 1;
   out_853953707448176894[210] = 0;
   out_853953707448176894[211] = 0;
   out_853953707448176894[212] = 0;
   out_853953707448176894[213] = 0;
   out_853953707448176894[214] = 0;
   out_853953707448176894[215] = 0;
   out_853953707448176894[216] = 0;
   out_853953707448176894[217] = 0;
   out_853953707448176894[218] = 0;
   out_853953707448176894[219] = 0;
   out_853953707448176894[220] = 0;
   out_853953707448176894[221] = 0;
   out_853953707448176894[222] = 0;
   out_853953707448176894[223] = 0;
   out_853953707448176894[224] = 0;
   out_853953707448176894[225] = 0;
   out_853953707448176894[226] = 0;
   out_853953707448176894[227] = 0;
   out_853953707448176894[228] = 1;
   out_853953707448176894[229] = 0;
   out_853953707448176894[230] = 0;
   out_853953707448176894[231] = 0;
   out_853953707448176894[232] = 0;
   out_853953707448176894[233] = 0;
   out_853953707448176894[234] = 0;
   out_853953707448176894[235] = 0;
   out_853953707448176894[236] = 0;
   out_853953707448176894[237] = 0;
   out_853953707448176894[238] = 0;
   out_853953707448176894[239] = 0;
   out_853953707448176894[240] = 0;
   out_853953707448176894[241] = 0;
   out_853953707448176894[242] = 0;
   out_853953707448176894[243] = 0;
   out_853953707448176894[244] = 0;
   out_853953707448176894[245] = 0;
   out_853953707448176894[246] = 0;
   out_853953707448176894[247] = 1;
   out_853953707448176894[248] = 0;
   out_853953707448176894[249] = 0;
   out_853953707448176894[250] = 0;
   out_853953707448176894[251] = 0;
   out_853953707448176894[252] = 0;
   out_853953707448176894[253] = 0;
   out_853953707448176894[254] = 0;
   out_853953707448176894[255] = 0;
   out_853953707448176894[256] = 0;
   out_853953707448176894[257] = 0;
   out_853953707448176894[258] = 0;
   out_853953707448176894[259] = 0;
   out_853953707448176894[260] = 0;
   out_853953707448176894[261] = 0;
   out_853953707448176894[262] = 0;
   out_853953707448176894[263] = 0;
   out_853953707448176894[264] = 0;
   out_853953707448176894[265] = 0;
   out_853953707448176894[266] = 1;
   out_853953707448176894[267] = 0;
   out_853953707448176894[268] = 0;
   out_853953707448176894[269] = 0;
   out_853953707448176894[270] = 0;
   out_853953707448176894[271] = 0;
   out_853953707448176894[272] = 0;
   out_853953707448176894[273] = 0;
   out_853953707448176894[274] = 0;
   out_853953707448176894[275] = 0;
   out_853953707448176894[276] = 0;
   out_853953707448176894[277] = 0;
   out_853953707448176894[278] = 0;
   out_853953707448176894[279] = 0;
   out_853953707448176894[280] = 0;
   out_853953707448176894[281] = 0;
   out_853953707448176894[282] = 0;
   out_853953707448176894[283] = 0;
   out_853953707448176894[284] = 0;
   out_853953707448176894[285] = 1;
   out_853953707448176894[286] = 0;
   out_853953707448176894[287] = 0;
   out_853953707448176894[288] = 0;
   out_853953707448176894[289] = 0;
   out_853953707448176894[290] = 0;
   out_853953707448176894[291] = 0;
   out_853953707448176894[292] = 0;
   out_853953707448176894[293] = 0;
   out_853953707448176894[294] = 0;
   out_853953707448176894[295] = 0;
   out_853953707448176894[296] = 0;
   out_853953707448176894[297] = 0;
   out_853953707448176894[298] = 0;
   out_853953707448176894[299] = 0;
   out_853953707448176894[300] = 0;
   out_853953707448176894[301] = 0;
   out_853953707448176894[302] = 0;
   out_853953707448176894[303] = 0;
   out_853953707448176894[304] = 1;
   out_853953707448176894[305] = 0;
   out_853953707448176894[306] = 0;
   out_853953707448176894[307] = 0;
   out_853953707448176894[308] = 0;
   out_853953707448176894[309] = 0;
   out_853953707448176894[310] = 0;
   out_853953707448176894[311] = 0;
   out_853953707448176894[312] = 0;
   out_853953707448176894[313] = 0;
   out_853953707448176894[314] = 0;
   out_853953707448176894[315] = 0;
   out_853953707448176894[316] = 0;
   out_853953707448176894[317] = 0;
   out_853953707448176894[318] = 0;
   out_853953707448176894[319] = 0;
   out_853953707448176894[320] = 0;
   out_853953707448176894[321] = 0;
   out_853953707448176894[322] = 0;
   out_853953707448176894[323] = 1;
}
void h_4(double *state, double *unused, double *out_4183473660625043839) {
   out_4183473660625043839[0] = state[6] + state[9];
   out_4183473660625043839[1] = state[7] + state[10];
   out_4183473660625043839[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_8745371835873163266) {
   out_8745371835873163266[0] = 0;
   out_8745371835873163266[1] = 0;
   out_8745371835873163266[2] = 0;
   out_8745371835873163266[3] = 0;
   out_8745371835873163266[4] = 0;
   out_8745371835873163266[5] = 0;
   out_8745371835873163266[6] = 1;
   out_8745371835873163266[7] = 0;
   out_8745371835873163266[8] = 0;
   out_8745371835873163266[9] = 1;
   out_8745371835873163266[10] = 0;
   out_8745371835873163266[11] = 0;
   out_8745371835873163266[12] = 0;
   out_8745371835873163266[13] = 0;
   out_8745371835873163266[14] = 0;
   out_8745371835873163266[15] = 0;
   out_8745371835873163266[16] = 0;
   out_8745371835873163266[17] = 0;
   out_8745371835873163266[18] = 0;
   out_8745371835873163266[19] = 0;
   out_8745371835873163266[20] = 0;
   out_8745371835873163266[21] = 0;
   out_8745371835873163266[22] = 0;
   out_8745371835873163266[23] = 0;
   out_8745371835873163266[24] = 0;
   out_8745371835873163266[25] = 1;
   out_8745371835873163266[26] = 0;
   out_8745371835873163266[27] = 0;
   out_8745371835873163266[28] = 1;
   out_8745371835873163266[29] = 0;
   out_8745371835873163266[30] = 0;
   out_8745371835873163266[31] = 0;
   out_8745371835873163266[32] = 0;
   out_8745371835873163266[33] = 0;
   out_8745371835873163266[34] = 0;
   out_8745371835873163266[35] = 0;
   out_8745371835873163266[36] = 0;
   out_8745371835873163266[37] = 0;
   out_8745371835873163266[38] = 0;
   out_8745371835873163266[39] = 0;
   out_8745371835873163266[40] = 0;
   out_8745371835873163266[41] = 0;
   out_8745371835873163266[42] = 0;
   out_8745371835873163266[43] = 0;
   out_8745371835873163266[44] = 1;
   out_8745371835873163266[45] = 0;
   out_8745371835873163266[46] = 0;
   out_8745371835873163266[47] = 1;
   out_8745371835873163266[48] = 0;
   out_8745371835873163266[49] = 0;
   out_8745371835873163266[50] = 0;
   out_8745371835873163266[51] = 0;
   out_8745371835873163266[52] = 0;
   out_8745371835873163266[53] = 0;
}
void h_10(double *state, double *unused, double *out_638079796201012561) {
   out_638079796201012561[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_638079796201012561[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_638079796201012561[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3338619363719351940) {
   out_3338619363719351940[0] = 0;
   out_3338619363719351940[1] = 9.8100000000000005*cos(state[1]);
   out_3338619363719351940[2] = 0;
   out_3338619363719351940[3] = 0;
   out_3338619363719351940[4] = -state[8];
   out_3338619363719351940[5] = state[7];
   out_3338619363719351940[6] = 0;
   out_3338619363719351940[7] = state[5];
   out_3338619363719351940[8] = -state[4];
   out_3338619363719351940[9] = 0;
   out_3338619363719351940[10] = 0;
   out_3338619363719351940[11] = 0;
   out_3338619363719351940[12] = 1;
   out_3338619363719351940[13] = 0;
   out_3338619363719351940[14] = 0;
   out_3338619363719351940[15] = 1;
   out_3338619363719351940[16] = 0;
   out_3338619363719351940[17] = 0;
   out_3338619363719351940[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3338619363719351940[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3338619363719351940[20] = 0;
   out_3338619363719351940[21] = state[8];
   out_3338619363719351940[22] = 0;
   out_3338619363719351940[23] = -state[6];
   out_3338619363719351940[24] = -state[5];
   out_3338619363719351940[25] = 0;
   out_3338619363719351940[26] = state[3];
   out_3338619363719351940[27] = 0;
   out_3338619363719351940[28] = 0;
   out_3338619363719351940[29] = 0;
   out_3338619363719351940[30] = 0;
   out_3338619363719351940[31] = 1;
   out_3338619363719351940[32] = 0;
   out_3338619363719351940[33] = 0;
   out_3338619363719351940[34] = 1;
   out_3338619363719351940[35] = 0;
   out_3338619363719351940[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3338619363719351940[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3338619363719351940[38] = 0;
   out_3338619363719351940[39] = -state[7];
   out_3338619363719351940[40] = state[6];
   out_3338619363719351940[41] = 0;
   out_3338619363719351940[42] = state[4];
   out_3338619363719351940[43] = -state[3];
   out_3338619363719351940[44] = 0;
   out_3338619363719351940[45] = 0;
   out_3338619363719351940[46] = 0;
   out_3338619363719351940[47] = 0;
   out_3338619363719351940[48] = 0;
   out_3338619363719351940[49] = 0;
   out_3338619363719351940[50] = 1;
   out_3338619363719351940[51] = 0;
   out_3338619363719351940[52] = 0;
   out_3338619363719351940[53] = 1;
}
void h_13(double *state, double *unused, double *out_672204314443848005) {
   out_672204314443848005[0] = state[3];
   out_672204314443848005[1] = state[4];
   out_672204314443848005[2] = state[5];
}
void H_13(double *state, double *unused, double *out_6489098412504055549) {
   out_6489098412504055549[0] = 0;
   out_6489098412504055549[1] = 0;
   out_6489098412504055549[2] = 0;
   out_6489098412504055549[3] = 1;
   out_6489098412504055549[4] = 0;
   out_6489098412504055549[5] = 0;
   out_6489098412504055549[6] = 0;
   out_6489098412504055549[7] = 0;
   out_6489098412504055549[8] = 0;
   out_6489098412504055549[9] = 0;
   out_6489098412504055549[10] = 0;
   out_6489098412504055549[11] = 0;
   out_6489098412504055549[12] = 0;
   out_6489098412504055549[13] = 0;
   out_6489098412504055549[14] = 0;
   out_6489098412504055549[15] = 0;
   out_6489098412504055549[16] = 0;
   out_6489098412504055549[17] = 0;
   out_6489098412504055549[18] = 0;
   out_6489098412504055549[19] = 0;
   out_6489098412504055549[20] = 0;
   out_6489098412504055549[21] = 0;
   out_6489098412504055549[22] = 1;
   out_6489098412504055549[23] = 0;
   out_6489098412504055549[24] = 0;
   out_6489098412504055549[25] = 0;
   out_6489098412504055549[26] = 0;
   out_6489098412504055549[27] = 0;
   out_6489098412504055549[28] = 0;
   out_6489098412504055549[29] = 0;
   out_6489098412504055549[30] = 0;
   out_6489098412504055549[31] = 0;
   out_6489098412504055549[32] = 0;
   out_6489098412504055549[33] = 0;
   out_6489098412504055549[34] = 0;
   out_6489098412504055549[35] = 0;
   out_6489098412504055549[36] = 0;
   out_6489098412504055549[37] = 0;
   out_6489098412504055549[38] = 0;
   out_6489098412504055549[39] = 0;
   out_6489098412504055549[40] = 0;
   out_6489098412504055549[41] = 1;
   out_6489098412504055549[42] = 0;
   out_6489098412504055549[43] = 0;
   out_6489098412504055549[44] = 0;
   out_6489098412504055549[45] = 0;
   out_6489098412504055549[46] = 0;
   out_6489098412504055549[47] = 0;
   out_6489098412504055549[48] = 0;
   out_6489098412504055549[49] = 0;
   out_6489098412504055549[50] = 0;
   out_6489098412504055549[51] = 0;
   out_6489098412504055549[52] = 0;
   out_6489098412504055549[53] = 0;
}
void h_14(double *state, double *unused, double *out_951178958321836501) {
   out_951178958321836501[0] = state[6];
   out_951178958321836501[1] = state[7];
   out_951178958321836501[2] = state[8];
}
void H_14(double *state, double *unused, double *out_5738131381496903821) {
   out_5738131381496903821[0] = 0;
   out_5738131381496903821[1] = 0;
   out_5738131381496903821[2] = 0;
   out_5738131381496903821[3] = 0;
   out_5738131381496903821[4] = 0;
   out_5738131381496903821[5] = 0;
   out_5738131381496903821[6] = 1;
   out_5738131381496903821[7] = 0;
   out_5738131381496903821[8] = 0;
   out_5738131381496903821[9] = 0;
   out_5738131381496903821[10] = 0;
   out_5738131381496903821[11] = 0;
   out_5738131381496903821[12] = 0;
   out_5738131381496903821[13] = 0;
   out_5738131381496903821[14] = 0;
   out_5738131381496903821[15] = 0;
   out_5738131381496903821[16] = 0;
   out_5738131381496903821[17] = 0;
   out_5738131381496903821[18] = 0;
   out_5738131381496903821[19] = 0;
   out_5738131381496903821[20] = 0;
   out_5738131381496903821[21] = 0;
   out_5738131381496903821[22] = 0;
   out_5738131381496903821[23] = 0;
   out_5738131381496903821[24] = 0;
   out_5738131381496903821[25] = 1;
   out_5738131381496903821[26] = 0;
   out_5738131381496903821[27] = 0;
   out_5738131381496903821[28] = 0;
   out_5738131381496903821[29] = 0;
   out_5738131381496903821[30] = 0;
   out_5738131381496903821[31] = 0;
   out_5738131381496903821[32] = 0;
   out_5738131381496903821[33] = 0;
   out_5738131381496903821[34] = 0;
   out_5738131381496903821[35] = 0;
   out_5738131381496903821[36] = 0;
   out_5738131381496903821[37] = 0;
   out_5738131381496903821[38] = 0;
   out_5738131381496903821[39] = 0;
   out_5738131381496903821[40] = 0;
   out_5738131381496903821[41] = 0;
   out_5738131381496903821[42] = 0;
   out_5738131381496903821[43] = 0;
   out_5738131381496903821[44] = 1;
   out_5738131381496903821[45] = 0;
   out_5738131381496903821[46] = 0;
   out_5738131381496903821[47] = 0;
   out_5738131381496903821[48] = 0;
   out_5738131381496903821[49] = 0;
   out_5738131381496903821[50] = 0;
   out_5738131381496903821[51] = 0;
   out_5738131381496903821[52] = 0;
   out_5738131381496903821[53] = 0;
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

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_4814816550392172101) {
  err_fun(nom_x, delta_x, out_4814816550392172101);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6466588547708167171) {
  inv_err_fun(nom_x, true_x, out_6466588547708167171);
}
void pose_H_mod_fun(double *state, double *out_6289018716856289817) {
  H_mod_fun(state, out_6289018716856289817);
}
void pose_f_fun(double *state, double dt, double *out_2810608996408053875) {
  f_fun(state,  dt, out_2810608996408053875);
}
void pose_F_fun(double *state, double dt, double *out_853953707448176894) {
  F_fun(state,  dt, out_853953707448176894);
}
void pose_h_4(double *state, double *unused, double *out_4183473660625043839) {
  h_4(state, unused, out_4183473660625043839);
}
void pose_H_4(double *state, double *unused, double *out_8745371835873163266) {
  H_4(state, unused, out_8745371835873163266);
}
void pose_h_10(double *state, double *unused, double *out_638079796201012561) {
  h_10(state, unused, out_638079796201012561);
}
void pose_H_10(double *state, double *unused, double *out_3338619363719351940) {
  H_10(state, unused, out_3338619363719351940);
}
void pose_h_13(double *state, double *unused, double *out_672204314443848005) {
  h_13(state, unused, out_672204314443848005);
}
void pose_H_13(double *state, double *unused, double *out_6489098412504055549) {
  H_13(state, unused, out_6489098412504055549);
}
void pose_h_14(double *state, double *unused, double *out_951178958321836501) {
  h_14(state, unused, out_951178958321836501);
}
void pose_H_14(double *state, double *unused, double *out_5738131381496903821) {
  H_14(state, unused, out_5738131381496903821);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
