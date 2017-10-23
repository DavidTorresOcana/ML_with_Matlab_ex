/* Include files */

#include "blascompat32.h"
#include "Reconocedor_numero_sfun.h"
#include "c1_Reconocedor_numero.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Reconocedor_numero_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[15] = { "y", "x", "X2", "X",
  "probabilidad", "numero", "nargin", "nargout", "BN", "RGB", "Theta2", "Theta3",
  "Theta1", "Imagen", "Resultado" };

static const char * c1_b_debug_family_names[4] = { "nargin", "nargout", "z", "g"
};

static const char * c1_c_debug_family_names[4] = { "nargin", "nargout", "z", "g"
};

static const char * c1_d_debug_family_names[12] = { "num_labels", "h1", "h2",
  "h3", "nargin", "nargout", "Theta1", "Theta2", "Theta3", "X", "prob", "p" };

/* Function Declarations */
static void initialize_c1_Reconocedor_numero
  (SFc1_Reconocedor_numeroInstanceStruct *chartInstance);
static void initialize_params_c1_Reconocedor_numero
  (SFc1_Reconocedor_numeroInstanceStruct *chartInstance);
static void enable_c1_Reconocedor_numero(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance);
static void disable_c1_Reconocedor_numero(SFc1_Reconocedor_numeroInstanceStruct *
  chartInstance);
static void c1_update_debugger_state_c1_Reconocedor_numero
  (SFc1_Reconocedor_numeroInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_Reconocedor_numero
  (SFc1_Reconocedor_numeroInstanceStruct *chartInstance);
static void set_sim_state_c1_Reconocedor_numero
  (SFc1_Reconocedor_numeroInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_Reconocedor_numero(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance);
static void sf_c1_Reconocedor_numero(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance);
static void initSimStructsc1_Reconocedor_numero
  (SFc1_Reconocedor_numeroInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_Resultado, const char_T *c1_identifier,
  real32_T c1_y[2]);
static void c1_b_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[2]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_Imagen, const char_T *c1_identifier,
  real32_T c1_y[921600]);
static void c1_d_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[921600]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[10025]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_f_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[260]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_g_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[650]);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_h_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real32_T c1_i_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_j_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[400]);
static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_k_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[400]);
static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_l_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[25]);
static void c1_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_m_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[10]);
static void c1_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[15]);
static void c1_predict(SFc1_Reconocedor_numeroInstanceStruct *chartInstance,
  real_T c1_b_Theta1[10025], real_T c1_b_Theta2[650], real_T c1_b_Theta3[260],
  real32_T c1_X[400], real32_T *c1_prob, real_T *c1_p);
static void c1_sigmoid(SFc1_Reconocedor_numeroInstanceStruct *chartInstance,
  real32_T c1_z[25], real32_T c1_g[25]);
static const mxArray *c1_m_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_n_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_o_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_Reconocedor_numero, const
  char_T *c1_identifier);
static uint8_T c1_p_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_Reconocedor_numero
  (SFc1_Reconocedor_numeroInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_Reconocedor_numero = 0U;
}

static void initialize_params_c1_Reconocedor_numero
  (SFc1_Reconocedor_numeroInstanceStruct *chartInstance)
{
  real_T c1_dv0[650];
  int32_T c1_i0;
  real_T c1_dv1[260];
  int32_T c1_i1;
  real_T c1_dv2[10025];
  int32_T c1_i2;
  sf_set_error_prefix_string(
    "Error evaluating data 'Theta2' in the parent workspace.\n");
  sf_mex_import_named("Theta2", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      c1_dv0, 0, 0, 0U, 1, 0U, 2, 25, 26);
  for (c1_i0 = 0; c1_i0 < 650; c1_i0++) {
    chartInstance->c1_Theta2[c1_i0] = c1_dv0[c1_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'Theta3' in the parent workspace.\n");
  sf_mex_import_named("Theta3", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      c1_dv1, 0, 0, 0U, 1, 0U, 2, 10, 26);
  for (c1_i1 = 0; c1_i1 < 260; c1_i1++) {
    chartInstance->c1_Theta3[c1_i1] = c1_dv1[c1_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'Theta1' in the parent workspace.\n");
  sf_mex_import_named("Theta1", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c1_dv2, 0, 0, 0U, 1, 0U, 2, 25, 401);
  for (c1_i2 = 0; c1_i2 < 10025; c1_i2++) {
    chartInstance->c1_Theta1[c1_i2] = c1_dv2[c1_i2];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c1_Reconocedor_numero(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_Reconocedor_numero(SFc1_Reconocedor_numeroInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_Reconocedor_numero
  (SFc1_Reconocedor_numeroInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_Reconocedor_numero
  (SFc1_Reconocedor_numeroInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i3;
  static real32_T c1_u[921600];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i4;
  real32_T c1_b_u[2];
  const mxArray *c1_c_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real32_T (*c1_Resultado)[2];
  real32_T (*c1_Imagen)[921600];
  c1_Resultado = (real32_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Imagen = (real32_T (*)[921600])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(3));
  for (c1_i3 = 0; c1_i3 < 921600; c1_i3++) {
    c1_u[c1_i3] = (*c1_Imagen)[c1_i3];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 1, 0U, 1U, 0U, 3, 480, 640, 3));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
    c1_b_u[c1_i4] = (*c1_Resultado)[c1_i4];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 1, 0U, 1U, 0U, 2, 1, 2));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_Reconocedor_numero;
  c1_c_u = c1_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_Reconocedor_numero
  (SFc1_Reconocedor_numeroInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  static real32_T c1_fv0[921600];
  int32_T c1_i5;
  real32_T c1_fv1[2];
  int32_T c1_i6;
  real32_T (*c1_Imagen)[921600];
  real32_T (*c1_Resultado)[2];
  c1_Resultado = (real32_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Imagen = (real32_T (*)[921600])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                        "Imagen", c1_fv0);
  for (c1_i5 = 0; c1_i5 < 921600; c1_i5++) {
    (*c1_Imagen)[c1_i5] = c1_fv0[c1_i5];
  }

  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                      "Resultado", c1_fv1);
  for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
    (*c1_Resultado)[c1_i6] = c1_fv1[c1_i6];
  }

  chartInstance->c1_is_active_c1_Reconocedor_numero = c1_o_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
     "is_active_c1_Reconocedor_numero");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_Reconocedor_numero(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_Reconocedor_numero(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance)
{
}

static void sf_c1_Reconocedor_numero(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance)
{
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  static real32_T c1_BN[307200];
  int32_T c1_i15;
  static real32_T c1_RGB[921600];
  int32_T c1_i16;
  real_T c1_b_Theta2[650];
  int32_T c1_i17;
  real_T c1_b_Theta3[260];
  int32_T c1_i18;
  static real_T c1_b_Theta1[10025];
  uint32_T c1_debug_family_var_map[15];
  real_T c1_y;
  real_T c1_x;
  real32_T c1_X2[400];
  real32_T c1_X[400];
  real32_T c1_probabilidad;
  real_T c1_numero;
  real_T c1_nargin = 5.0;
  real_T c1_nargout = 2.0;
  static real32_T c1_Imagen[921600];
  real32_T c1_Resultado[2];
  int32_T c1_i19;
  real_T c1_b_y;
  real_T c1_b_x;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  real_T c1_c_Theta1[10025];
  int32_T c1_i26;
  real_T c1_c_Theta2[650];
  int32_T c1_i27;
  real_T c1_c_Theta3[260];
  int32_T c1_i28;
  real32_T c1_b_X[400];
  real_T c1_b_numero;
  real32_T c1_b_probabilidad;
  int32_T c1_i29;
  int32_T c1_i30;
  real32_T (*c1_b_Imagen)[921600];
  real32_T (*c1_b_Resultado)[2];
  real32_T (*c1_b_RGB)[921600];
  real32_T (*c1_b_BN)[307200];
  c1_b_Resultado = (real32_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_Imagen = (real32_T (*)[921600])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_RGB = (real32_T (*)[921600])ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_BN = (real32_T (*)[307200])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i7 = 0; c1_i7 < 307200; c1_i7++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c1_b_BN)[c1_i7], 0U);
  }

  for (c1_i8 = 0; c1_i8 < 921600; c1_i8++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c1_b_RGB)[c1_i8], 1U);
  }

  for (c1_i9 = 0; c1_i9 < 921600; c1_i9++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c1_b_Imagen)[c1_i9], 2U);
  }

  for (c1_i10 = 0; c1_i10 < 2; c1_i10++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c1_b_Resultado)[c1_i10], 3U);
  }

  for (c1_i11 = 0; c1_i11 < 650; c1_i11++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_Theta2[c1_i11], 4U);
  }

  for (c1_i12 = 0; c1_i12 < 260; c1_i12++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_Theta3[c1_i12], 5U);
  }

  for (c1_i13 = 0; c1_i13 < 10025; c1_i13++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_Theta1[c1_i13], 6U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i14 = 0; c1_i14 < 307200; c1_i14++) {
    c1_BN[c1_i14] = (*c1_b_BN)[c1_i14];
  }

  for (c1_i15 = 0; c1_i15 < 921600; c1_i15++) {
    c1_RGB[c1_i15] = (*c1_b_RGB)[c1_i15];
  }

  for (c1_i16 = 0; c1_i16 < 650; c1_i16++) {
    c1_b_Theta2[c1_i16] = chartInstance->c1_Theta2[c1_i16];
  }

  for (c1_i17 = 0; c1_i17 < 260; c1_i17++) {
    c1_b_Theta3[c1_i17] = chartInstance->c1_Theta3[c1_i17];
  }

  for (c1_i18 = 0; c1_i18 < 10025; c1_i18++) {
    c1_b_Theta1[c1_i18] = chartInstance->c1_Theta1[c1_i18];
  }

  sf_debug_symbol_scope_push_eml(0U, 15U, 15U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_y, 0U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_x, 1U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_X2, 2U, c1_j_sf_marshallOut,
    c1_i_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_X, 3U, c1_i_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_probabilidad, 4U,
    c1_h_sf_marshallOut, c1_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_numero, 5U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 6U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 7U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_BN, 8U, c1_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_RGB, 9U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_b_Theta2, 10U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_Theta3, 11U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_Theta1, 12U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Imagen, 13U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Resultado, 14U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  for (c1_i19 = 0; c1_i19 < 921600; c1_i19++) {
    c1_Imagen[c1_i19] = c1_RGB[c1_i19];
  }

  c1_y = 310.0;
  c1_b_y = 310.0;
  while (c1_b_y <= 329.0) {
    c1_y = c1_b_y;
    CV_EML_FOR(0, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
    c1_Imagen[614629 + 480 * (_SFD_EML_ARRAY_BOUNDS_CHECK("Imagen", (int32_T)
      _SFD_INTEGER_CHECK("y", c1_y), 1, 640, 2, 0) - 1)] = 250.0F;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
    c1_Imagen[614649 + 480 * (_SFD_EML_ARRAY_BOUNDS_CHECK("Imagen", (int32_T)
      _SFD_INTEGER_CHECK("y", c1_y), 1, 640, 2, 0) - 1)] = 250.0F;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
    c1_Imagen[229 + 480 * (_SFD_EML_ARRAY_BOUNDS_CHECK("Imagen", (int32_T)
      _SFD_INTEGER_CHECK("y", c1_y), 1, 640, 2, 0) - 1)] = 0.0F;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
    c1_Imagen[249 + 480 * (_SFD_EML_ARRAY_BOUNDS_CHECK("Imagen", (int32_T)
      _SFD_INTEGER_CHECK("y", c1_y), 1, 640, 2, 0) - 1)] = 0.0F;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
    c1_Imagen[307429 + 480 * (_SFD_EML_ARRAY_BOUNDS_CHECK("Imagen", (int32_T)
      _SFD_INTEGER_CHECK("y", c1_y), 1, 640, 2, 0) - 1)] = 0.0F;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
    c1_Imagen[307449 + 480 * (_SFD_EML_ARRAY_BOUNDS_CHECK("Imagen", (int32_T)
      _SFD_INTEGER_CHECK("y", c1_y), 1, 640, 2, 0) - 1)] = 0.0F;
    c1_b_y++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_EML_FOR(0, 0, 0);
  c1_x = 230.0;
  c1_b_x = 230.0;
  while (c1_b_x <= 249.0) {
    c1_x = c1_b_x;
    CV_EML_FOR(0, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
    c1_Imagen[_SFD_EML_ARRAY_BOUNDS_CHECK("Imagen", (int32_T)_SFD_INTEGER_CHECK(
      "x", c1_x), 1, 480, 1, 0) + 762719] = 250.0F;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
    c1_Imagen[_SFD_EML_ARRAY_BOUNDS_CHECK("Imagen", (int32_T)_SFD_INTEGER_CHECK(
      "x", c1_x), 1, 480, 1, 0) + 772319] = 250.0F;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
    c1_Imagen[_SFD_EML_ARRAY_BOUNDS_CHECK("Imagen", (int32_T)_SFD_INTEGER_CHECK(
      "x", c1_x), 1, 480, 1, 0) + 455519] = 0.0F;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
    c1_Imagen[_SFD_EML_ARRAY_BOUNDS_CHECK("Imagen", (int32_T)_SFD_INTEGER_CHECK(
      "x", c1_x), 1, 480, 1, 0) + 465119] = 0.0F;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
    c1_Imagen[_SFD_EML_ARRAY_BOUNDS_CHECK("Imagen", (int32_T)_SFD_INTEGER_CHECK(
      "x", c1_x), 1, 480, 1, 0) + 148319] = 0.0F;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
    c1_Imagen[_SFD_EML_ARRAY_BOUNDS_CHECK("Imagen", (int32_T)_SFD_INTEGER_CHECK(
      "x", c1_x), 1, 480, 1, 0) + 157919] = 0.0F;
    c1_b_x++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
  c1_i20 = 0;
  c1_i21 = 0;
  for (c1_i22 = 0; c1_i22 < 20; c1_i22++) {
    for (c1_i23 = 0; c1_i23 < 20; c1_i23++) {
      c1_X2[c1_i23 + c1_i20] = c1_BN[(c1_i23 + c1_i21) + 110229];
    }

    c1_i20 += 20;
    c1_i21 += 480;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  for (c1_i24 = 0; c1_i24 < 400; c1_i24++) {
    c1_X[c1_i24] = c1_X2[c1_i24];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  for (c1_i25 = 0; c1_i25 < 10025; c1_i25++) {
    c1_c_Theta1[c1_i25] = c1_b_Theta1[c1_i25];
  }

  for (c1_i26 = 0; c1_i26 < 650; c1_i26++) {
    c1_c_Theta2[c1_i26] = c1_b_Theta2[c1_i26];
  }

  for (c1_i27 = 0; c1_i27 < 260; c1_i27++) {
    c1_c_Theta3[c1_i27] = c1_b_Theta3[c1_i27];
  }

  for (c1_i28 = 0; c1_i28 < 400; c1_i28++) {
    c1_b_X[c1_i28] = c1_X[c1_i28];
  }

  c1_predict(chartInstance, c1_c_Theta1, c1_c_Theta2, c1_c_Theta3, c1_b_X,
             &c1_b_probabilidad, &c1_b_numero);
  c1_probabilidad = c1_b_probabilidad;
  c1_numero = c1_b_numero;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
  if (CV_EML_IF(0, 0, (real_T)c1_probabilidad < 0.85)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
    c1_numero = rtNaN;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
  c1_Resultado[0] = (real32_T)c1_numero;
  c1_Resultado[1] = c1_probabilidad;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -31);
  sf_debug_symbol_scope_pop();
  for (c1_i29 = 0; c1_i29 < 921600; c1_i29++) {
    (*c1_b_Imagen)[c1_i29] = c1_Imagen[c1_i29];
  }

  for (c1_i30 = 0; c1_i30 < 2; c1_i30++) {
    (*c1_b_Resultado)[c1_i30] = c1_Resultado[c1_i30];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  sf_debug_check_for_state_inconsistency(_Reconocedor_numeroMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_Reconocedor_numero
  (SFc1_Reconocedor_numeroInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i31;
  real32_T c1_b_inData[2];
  int32_T c1_i32;
  real32_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i31 = 0; c1_i31 < 2; c1_i31++) {
    c1_b_inData[c1_i31] = (*(real32_T (*)[2])c1_inData)[c1_i31];
  }

  for (c1_i32 = 0; c1_i32 < 2; c1_i32++) {
    c1_u[c1_i32] = c1_b_inData[c1_i32];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 1, 0U, 1U, 0U, 2, 1, 2));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_Resultado, const char_T *c1_identifier,
  real32_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Resultado), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_Resultado);
}

static void c1_b_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[2])
{
  real32_T c1_fv2[2];
  int32_T c1_i33;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_fv2, 1, 1, 0U, 1, 0U, 2, 1, 2);
  for (c1_i33 = 0; c1_i33 < 2; c1_i33++) {
    c1_y[c1_i33] = c1_fv2[c1_i33];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Resultado;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real32_T c1_y[2];
  int32_T c1_i34;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_Resultado = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Resultado), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_Resultado);
  for (c1_i34 = 0; c1_i34 < 2; c1_i34++) {
    (*(real32_T (*)[2])c1_outData)[c1_i34] = c1_y[c1_i34];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  static real32_T c1_b_inData[921600];
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  static real32_T c1_u[921600];
  const mxArray *c1_y = NULL;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i35 = 0;
  for (c1_i36 = 0; c1_i36 < 3; c1_i36++) {
    c1_i37 = 0;
    for (c1_i38 = 0; c1_i38 < 640; c1_i38++) {
      for (c1_i39 = 0; c1_i39 < 480; c1_i39++) {
        c1_b_inData[(c1_i39 + c1_i37) + c1_i35] = (*(real32_T (*)[921600])
          c1_inData)[(c1_i39 + c1_i37) + c1_i35];
      }

      c1_i37 += 480;
    }

    c1_i35 += 307200;
  }

  c1_i40 = 0;
  for (c1_i41 = 0; c1_i41 < 3; c1_i41++) {
    c1_i42 = 0;
    for (c1_i43 = 0; c1_i43 < 640; c1_i43++) {
      for (c1_i44 = 0; c1_i44 < 480; c1_i44++) {
        c1_u[(c1_i44 + c1_i42) + c1_i40] = c1_b_inData[(c1_i44 + c1_i42) +
          c1_i40];
      }

      c1_i42 += 480;
    }

    c1_i40 += 307200;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 1, 0U, 1U, 0U, 3, 480, 640, 3));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_Imagen, const char_T *c1_identifier,
  real32_T c1_y[921600])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Imagen), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Imagen);
}

static void c1_d_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[921600])
{
  static real32_T c1_fv3[921600];
  int32_T c1_i45;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_fv3, 1, 1, 0U, 1, 0U, 3, 480,
                640, 3);
  for (c1_i45 = 0; c1_i45 < 921600; c1_i45++) {
    c1_y[c1_i45] = c1_fv3[c1_i45];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Imagen;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  static real32_T c1_y[921600];
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i50;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_Imagen = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Imagen), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Imagen);
  c1_i46 = 0;
  for (c1_i47 = 0; c1_i47 < 3; c1_i47++) {
    c1_i48 = 0;
    for (c1_i49 = 0; c1_i49 < 640; c1_i49++) {
      for (c1_i50 = 0; c1_i50 < 480; c1_i50++) {
        (*(real32_T (*)[921600])c1_outData)[(c1_i50 + c1_i48) + c1_i46] = c1_y
          [(c1_i50 + c1_i48) + c1_i46];
      }

      c1_i48 += 480;
    }

    c1_i46 += 307200;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  real_T c1_b_inData[10025];
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  real_T c1_u[10025];
  const mxArray *c1_y = NULL;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i51 = 0;
  for (c1_i52 = 0; c1_i52 < 401; c1_i52++) {
    for (c1_i53 = 0; c1_i53 < 25; c1_i53++) {
      c1_b_inData[c1_i53 + c1_i51] = (*(real_T (*)[10025])c1_inData)[c1_i53 +
        c1_i51];
    }

    c1_i51 += 25;
  }

  c1_i54 = 0;
  for (c1_i55 = 0; c1_i55 < 401; c1_i55++) {
    for (c1_i56 = 0; c1_i56 < 25; c1_i56++) {
      c1_u[c1_i56 + c1_i54] = c1_b_inData[c1_i56 + c1_i54];
    }

    c1_i54 += 25;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 25, 401));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[10025])
{
  real_T c1_dv3[10025];
  int32_T c1_i57;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv3, 1, 0, 0U, 1, 0U, 2, 25,
                401);
  for (c1_i57 = 0; c1_i57 < 10025; c1_i57++) {
    c1_y[c1_i57] = c1_dv3[c1_i57];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_Theta1;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[10025];
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_i60;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_b_Theta1 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Theta1), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_Theta1);
  c1_i58 = 0;
  for (c1_i59 = 0; c1_i59 < 401; c1_i59++) {
    for (c1_i60 = 0; c1_i60 < 25; c1_i60++) {
      (*(real_T (*)[10025])c1_outData)[c1_i60 + c1_i58] = c1_y[c1_i60 + c1_i58];
    }

    c1_i58 += 25;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  real_T c1_b_inData[260];
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  real_T c1_u[260];
  const mxArray *c1_y = NULL;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i61 = 0;
  for (c1_i62 = 0; c1_i62 < 26; c1_i62++) {
    for (c1_i63 = 0; c1_i63 < 10; c1_i63++) {
      c1_b_inData[c1_i63 + c1_i61] = (*(real_T (*)[260])c1_inData)[c1_i63 +
        c1_i61];
    }

    c1_i61 += 10;
  }

  c1_i64 = 0;
  for (c1_i65 = 0; c1_i65 < 26; c1_i65++) {
    for (c1_i66 = 0; c1_i66 < 10; c1_i66++) {
      c1_u[c1_i66 + c1_i64] = c1_b_inData[c1_i66 + c1_i64];
    }

    c1_i64 += 10;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 10, 26));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_f_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[260])
{
  real_T c1_dv4[260];
  int32_T c1_i67;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv4, 1, 0, 0U, 1, 0U, 2, 10,
                26);
  for (c1_i67 = 0; c1_i67 < 260; c1_i67++) {
    c1_y[c1_i67] = c1_dv4[c1_i67];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_Theta3;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[260];
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i70;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_b_Theta3 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Theta3), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_Theta3);
  c1_i68 = 0;
  for (c1_i69 = 0; c1_i69 < 26; c1_i69++) {
    for (c1_i70 = 0; c1_i70 < 10; c1_i70++) {
      (*(real_T (*)[260])c1_outData)[c1_i70 + c1_i68] = c1_y[c1_i70 + c1_i68];
    }

    c1_i68 += 10;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  real_T c1_b_inData[650];
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  real_T c1_u[650];
  const mxArray *c1_y = NULL;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i71 = 0;
  for (c1_i72 = 0; c1_i72 < 26; c1_i72++) {
    for (c1_i73 = 0; c1_i73 < 25; c1_i73++) {
      c1_b_inData[c1_i73 + c1_i71] = (*(real_T (*)[650])c1_inData)[c1_i73 +
        c1_i71];
    }

    c1_i71 += 25;
  }

  c1_i74 = 0;
  for (c1_i75 = 0; c1_i75 < 26; c1_i75++) {
    for (c1_i76 = 0; c1_i76 < 25; c1_i76++) {
      c1_u[c1_i76 + c1_i74] = c1_b_inData[c1_i76 + c1_i74];
    }

    c1_i74 += 25;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 25, 26));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_g_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[650])
{
  real_T c1_dv5[650];
  int32_T c1_i77;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv5, 1, 0, 0U, 1, 0U, 2, 25,
                26);
  for (c1_i77 = 0; c1_i77 < 650; c1_i77++) {
    c1_y[c1_i77] = c1_dv5[c1_i77];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_Theta2;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[650];
  int32_T c1_i78;
  int32_T c1_i79;
  int32_T c1_i80;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_b_Theta2 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Theta2), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_Theta2);
  c1_i78 = 0;
  for (c1_i79 = 0; c1_i79 < 26; c1_i79++) {
    for (c1_i80 = 0; c1_i80 < 25; c1_i80++) {
      (*(real_T (*)[650])c1_outData)[c1_i80 + c1_i78] = c1_y[c1_i80 + c1_i78];
    }

    c1_i78 += 25;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i81;
  int32_T c1_i82;
  int32_T c1_i83;
  static real32_T c1_b_inData[307200];
  int32_T c1_i84;
  int32_T c1_i85;
  int32_T c1_i86;
  static real32_T c1_u[307200];
  const mxArray *c1_y = NULL;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i81 = 0;
  for (c1_i82 = 0; c1_i82 < 640; c1_i82++) {
    for (c1_i83 = 0; c1_i83 < 480; c1_i83++) {
      c1_b_inData[c1_i83 + c1_i81] = (*(real32_T (*)[307200])c1_inData)[c1_i83 +
        c1_i81];
    }

    c1_i81 += 480;
  }

  c1_i84 = 0;
  for (c1_i85 = 0; c1_i85 < 640; c1_i85++) {
    for (c1_i86 = 0; c1_i86 < 480; c1_i86++) {
      c1_u[c1_i86 + c1_i84] = c1_b_inData[c1_i86 + c1_i84];
    }

    c1_i84 += 480;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 1, 0U, 1U, 0U, 2, 480, 640));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static real_T c1_h_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 1, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static real32_T c1_i_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real32_T c1_y;
  real32_T c1_f0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_f0, 1, 1, 0U, 0, 0U, 0);
  c1_y = c1_f0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_probabilidad;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real32_T c1_y;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_probabilidad = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_probabilidad),
    &c1_thisId);
  sf_mex_destroy(&c1_probabilidad);
  *(real32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i87;
  real32_T c1_b_inData[400];
  int32_T c1_i88;
  real32_T c1_u[400];
  const mxArray *c1_y = NULL;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i87 = 0; c1_i87 < 400; c1_i87++) {
    c1_b_inData[c1_i87] = (*(real32_T (*)[400])c1_inData)[c1_i87];
  }

  for (c1_i88 = 0; c1_i88 < 400; c1_i88++) {
    c1_u[c1_i88] = c1_b_inData[c1_i88];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 1, 0U, 1U, 0U, 2, 1, 400));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_j_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[400])
{
  real32_T c1_fv4[400];
  int32_T c1_i89;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_fv4, 1, 1, 0U, 1, 0U, 2, 1,
                400);
  for (c1_i89 = 0; c1_i89 < 400; c1_i89++) {
    c1_y[c1_i89] = c1_fv4[c1_i89];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_X;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real32_T c1_y[400];
  int32_T c1_i90;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_X = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_X), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_X);
  for (c1_i90 = 0; c1_i90 < 400; c1_i90++) {
    (*(real32_T (*)[400])c1_outData)[c1_i90] = c1_y[c1_i90];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i91;
  int32_T c1_i92;
  int32_T c1_i93;
  real32_T c1_b_inData[400];
  int32_T c1_i94;
  int32_T c1_i95;
  int32_T c1_i96;
  real32_T c1_u[400];
  const mxArray *c1_y = NULL;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i91 = 0;
  for (c1_i92 = 0; c1_i92 < 20; c1_i92++) {
    for (c1_i93 = 0; c1_i93 < 20; c1_i93++) {
      c1_b_inData[c1_i93 + c1_i91] = (*(real32_T (*)[400])c1_inData)[c1_i93 +
        c1_i91];
    }

    c1_i91 += 20;
  }

  c1_i94 = 0;
  for (c1_i95 = 0; c1_i95 < 20; c1_i95++) {
    for (c1_i96 = 0; c1_i96 < 20; c1_i96++) {
      c1_u[c1_i96 + c1_i94] = c1_b_inData[c1_i96 + c1_i94];
    }

    c1_i94 += 20;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 1, 0U, 1U, 0U, 2, 20, 20));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_k_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[400])
{
  real32_T c1_fv5[400];
  int32_T c1_i97;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_fv5, 1, 1, 0U, 1, 0U, 2, 20,
                20);
  for (c1_i97 = 0; c1_i97 < 400; c1_i97++) {
    c1_y[c1_i97] = c1_fv5[c1_i97];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_X2;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real32_T c1_y[400];
  int32_T c1_i98;
  int32_T c1_i99;
  int32_T c1_i100;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_X2 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_X2), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_X2);
  c1_i98 = 0;
  for (c1_i99 = 0; c1_i99 < 20; c1_i99++) {
    for (c1_i100 = 0; c1_i100 < 20; c1_i100++) {
      (*(real32_T (*)[400])c1_outData)[c1_i100 + c1_i98] = c1_y[c1_i100 + c1_i98];
    }

    c1_i98 += 20;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i101;
  real32_T c1_b_inData[25];
  int32_T c1_i102;
  real32_T c1_u[25];
  const mxArray *c1_y = NULL;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i101 = 0; c1_i101 < 25; c1_i101++) {
    c1_b_inData[c1_i101] = (*(real32_T (*)[25])c1_inData)[c1_i101];
  }

  for (c1_i102 = 0; c1_i102 < 25; c1_i102++) {
    c1_u[c1_i102] = c1_b_inData[c1_i102];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 1, 0U, 1U, 0U, 2, 1, 25));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_l_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[25])
{
  real32_T c1_fv6[25];
  int32_T c1_i103;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_fv6, 1, 1, 0U, 1, 0U, 2, 1, 25);
  for (c1_i103 = 0; c1_i103 < 25; c1_i103++) {
    c1_y[c1_i103] = c1_fv6[c1_i103];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_g;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real32_T c1_y[25];
  int32_T c1_i104;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_g = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_g), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_g);
  for (c1_i104 = 0; c1_i104 < 25; c1_i104++) {
    (*(real32_T (*)[25])c1_outData)[c1_i104] = c1_y[c1_i104];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i105;
  real32_T c1_b_inData[10];
  int32_T c1_i106;
  real32_T c1_u[10];
  const mxArray *c1_y = NULL;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i105 = 0; c1_i105 < 10; c1_i105++) {
    c1_b_inData[c1_i105] = (*(real32_T (*)[10])c1_inData)[c1_i105];
  }

  for (c1_i106 = 0; c1_i106 < 10; c1_i106++) {
    c1_u[c1_i106] = c1_b_inData[c1_i106];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 1, 0U, 1U, 0U, 2, 1, 10));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_m_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[10])
{
  real32_T c1_fv7[10];
  int32_T c1_i107;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_fv7, 1, 1, 0U, 1, 0U, 2, 1, 10);
  for (c1_i107 = 0; c1_i107 < 10; c1_i107++) {
    c1_y[c1_i107] = c1_fv7[c1_i107];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_g;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real32_T c1_y[10];
  int32_T c1_i108;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_g = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_g), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_g);
  for (c1_i108 = 0; c1_i108 < 10; c1_i108++) {
    (*(real32_T (*)[10])c1_outData)[c1_i108] = c1_y[c1_i108];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_Reconocedor_numero_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[15];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i109;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 15));
  for (c1_i109 = 0; c1_i109 < 15; c1_i109++) {
    c1_r0 = &c1_info[c1_i109];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i109);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i109);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i109);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i109);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i109);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i109);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i109);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i109);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[15])
{
  c1_info[0].context = "";
  c1_info[0].name = "mrdivide";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[0].fileTimeLo = 2117098240U;
  c1_info[0].fileTimeHi = 30130935U;
  c1_info[0].mFileTimeLo = 3573034496U;
  c1_info[0].mFileTimeHi = 30114299U;
  c1_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[1].name = "rdivide";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[1].fileTimeLo = 1847391744U;
  c1_info[1].fileTimeHi = 30108011U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[2].name = "eml_div";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[2].fileTimeLo = 387391744U;
  c1_info[2].fileTimeHi = 30108011U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "";
  c1_info[3].name = "mtimes";
  c1_info[3].dominantType = "single";
  c1_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[3].fileTimeLo = 3573034496U;
  c1_info[3].fileTimeHi = 30114299U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context = "";
  c1_info[4].name = "exp";
  c1_info[4].dominantType = "single";
  c1_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c1_info[4].fileTimeLo = 807391744U;
  c1_info[4].fileTimeHi = 30108011U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c1_info[5].name = "eml_scalar_exp";
  c1_info[5].dominantType = "single";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c1_info[5].fileTimeLo = 667391744U;
  c1_info[5].fileTimeHi = 30108011U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context = "";
  c1_info[6].name = "max";
  c1_info[6].dominantType = "single";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c1_info[6].fileTimeLo = 347391744U;
  c1_info[6].fileTimeHi = 30108011U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c1_info[7].name = "eml_min_or_max";
  c1_info[7].dominantType = "single";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[7].fileTimeLo = 1287391744U;
  c1_info[7].fileTimeHi = 30108011U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[8].name = "eml_assert_valid_dim";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c1_info[8].fileTimeLo = 347391744U;
  c1_info[8].fileTimeHi = 30108011U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c1_info[9].name = "eml_scalar_floor";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[9].fileTimeLo = 667391744U;
  c1_info[9].fileTimeHi = 30108011U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c1_info[10].name = "eml_index_class";
  c1_info[10].dominantType = "";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[10].fileTimeLo = 1187391744U;
  c1_info[10].fileTimeHi = 30108011U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c1_info[11].name = "intmax";
  c1_info[11].dominantType = "char";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[11].fileTimeLo = 967391744U;
  c1_info[11].fileTimeHi = 30108011U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[12].name = "eml_scalar_eg";
  c1_info[12].dominantType = "single";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[12].fileTimeLo = 1367391744U;
  c1_info[12].fileTimeHi = 30108011U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c1_info[13].name = "isnan";
  c1_info[13].dominantType = "single";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[13].fileTimeLo = 1007391744U;
  c1_info[13].fileTimeHi = 30108011U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c1_info[14].name = "eml_index_plus";
  c1_info[14].dominantType = "int32";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[14].fileTimeLo = 1187391744U;
  c1_info[14].fileTimeHi = 30108011U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
}

static void c1_predict(SFc1_Reconocedor_numeroInstanceStruct *chartInstance,
  real_T c1_b_Theta1[10025], real_T c1_b_Theta2[650], real_T c1_b_Theta3[260],
  real32_T c1_X[400], real32_T *c1_prob, real_T *c1_p)
{
  uint32_T c1_debug_family_var_map[12];
  real_T c1_num_labels;
  real32_T c1_h1[25];
  real32_T c1_h2[25];
  real32_T c1_h3[10];
  real_T c1_nargin = 4.0;
  real_T c1_nargout = 2.0;
  real32_T c1_a[401];
  int32_T c1_i110;
  int32_T c1_i111;
  int32_T c1_i112;
  int32_T c1_i113;
  int32_T c1_i114;
  real_T c1_b[10025];
  int32_T c1_i115;
  int32_T c1_i116;
  real32_T c1_y[25];
  int32_T c1_i117;
  int32_T c1_i118;
  real32_T c1_b_y[25];
  real32_T c1_fv8[25];
  int32_T c1_i119;
  real32_T c1_b_a[26];
  int32_T c1_i120;
  int32_T c1_i121;
  int32_T c1_i122;
  int32_T c1_i123;
  int32_T c1_i124;
  real_T c1_b_b[650];
  int32_T c1_i125;
  int32_T c1_i126;
  int32_T c1_i127;
  int32_T c1_i128;
  real32_T c1_c_y[25];
  real32_T c1_fv9[25];
  int32_T c1_i129;
  int32_T c1_i130;
  int32_T c1_i131;
  int32_T c1_i132;
  int32_T c1_i133;
  int32_T c1_i134;
  real_T c1_c_b[260];
  int32_T c1_i135;
  int32_T c1_i136;
  real32_T c1_d_y[10];
  int32_T c1_i137;
  int32_T c1_i138;
  real32_T c1_z[10];
  uint32_T c1_b_debug_family_var_map[4];
  real_T c1_b_nargin = 1.0;
  real_T c1_b_nargout = 1.0;
  int32_T c1_i139;
  real_T c1_k;
  real_T c1_b_k;
  real32_T c1_x;
  real32_T c1_b_x;
  int32_T c1_i140;
  int32_T c1_i141;
  int32_T c1_i142;
  real32_T c1_mtmp;
  int32_T c1_itmp;
  int32_T c1_ix;
  real32_T c1_c_x;
  boolean_T c1_d_b;
  boolean_T c1_searchingForNonNaN;
  int32_T c1_c_k;
  int32_T c1_d_k;
  int32_T c1_c_a;
  real32_T c1_d_x;
  boolean_T c1_e_b;
  int32_T c1_d_a;
  int32_T c1_i143;
  int32_T c1_b_ix;
  real32_T c1_b_mtmp;
  int32_T c1_b_itmp;
  real32_T c1_maxval;
  real_T c1_indx;
  real32_T c1_b_prob;
  real_T c1_b_p;
  boolean_T guard1 = FALSE;
  boolean_T exitg1;
  sf_debug_symbol_scope_push_eml(0U, 12U, 12U, c1_d_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_num_labels, 0U,
    c1_g_sf_marshallOut, c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_h1, 1U, c1_k_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_h2, 2U, c1_k_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_h3, 3U, c1_l_sf_marshallOut,
    c1_k_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 4U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 5U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_Theta1, 6U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_Theta2, 7U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_Theta3, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_X, 9U, c1_i_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_prob, 10U, c1_h_sf_marshallOut,
    c1_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_p, 11U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 41);
  c1_num_labels = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
  c1_a[0] = 1.0F;
  for (c1_i110 = 0; c1_i110 < 400; c1_i110++) {
    c1_a[c1_i110 + 1] = c1_X[c1_i110];
  }

  c1_i111 = 0;
  for (c1_i112 = 0; c1_i112 < 25; c1_i112++) {
    c1_i113 = 0;
    for (c1_i114 = 0; c1_i114 < 401; c1_i114++) {
      c1_b[c1_i114 + c1_i111] = c1_b_Theta1[c1_i113 + c1_i112];
      c1_i113 += 25;
    }

    c1_i111 += 401;
  }

  c1_i115 = 0;
  for (c1_i116 = 0; c1_i116 < 25; c1_i116++) {
    c1_y[c1_i116] = 0.0F;
    for (c1_i117 = 0; c1_i117 < 401; c1_i117++) {
      c1_y[c1_i116] += c1_a[c1_i117] * (real32_T)c1_b[c1_i117 + c1_i115];
    }

    c1_i115 += 401;
  }

  for (c1_i118 = 0; c1_i118 < 25; c1_i118++) {
    c1_b_y[c1_i118] = c1_y[c1_i118];
  }

  c1_sigmoid(chartInstance, c1_b_y, c1_fv8);
  for (c1_i119 = 0; c1_i119 < 25; c1_i119++) {
    c1_h1[c1_i119] = c1_fv8[c1_i119];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 46);
  c1_b_a[0] = 1.0F;
  for (c1_i120 = 0; c1_i120 < 25; c1_i120++) {
    c1_b_a[c1_i120 + 1] = c1_h1[c1_i120];
  }

  c1_i121 = 0;
  for (c1_i122 = 0; c1_i122 < 25; c1_i122++) {
    c1_i123 = 0;
    for (c1_i124 = 0; c1_i124 < 26; c1_i124++) {
      c1_b_b[c1_i124 + c1_i121] = c1_b_Theta2[c1_i123 + c1_i122];
      c1_i123 += 25;
    }

    c1_i121 += 26;
  }

  c1_i125 = 0;
  for (c1_i126 = 0; c1_i126 < 25; c1_i126++) {
    c1_y[c1_i126] = 0.0F;
    for (c1_i127 = 0; c1_i127 < 26; c1_i127++) {
      c1_y[c1_i126] += c1_b_a[c1_i127] * (real32_T)c1_b_b[c1_i127 + c1_i125];
    }

    c1_i125 += 26;
  }

  for (c1_i128 = 0; c1_i128 < 25; c1_i128++) {
    c1_c_y[c1_i128] = c1_y[c1_i128];
  }

  c1_sigmoid(chartInstance, c1_c_y, c1_fv9);
  for (c1_i129 = 0; c1_i129 < 25; c1_i129++) {
    c1_h2[c1_i129] = c1_fv9[c1_i129];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 47);
  c1_b_a[0] = 1.0F;
  for (c1_i130 = 0; c1_i130 < 25; c1_i130++) {
    c1_b_a[c1_i130 + 1] = c1_h2[c1_i130];
  }

  c1_i131 = 0;
  for (c1_i132 = 0; c1_i132 < 10; c1_i132++) {
    c1_i133 = 0;
    for (c1_i134 = 0; c1_i134 < 26; c1_i134++) {
      c1_c_b[c1_i134 + c1_i131] = c1_b_Theta3[c1_i133 + c1_i132];
      c1_i133 += 10;
    }

    c1_i131 += 26;
  }

  c1_i135 = 0;
  for (c1_i136 = 0; c1_i136 < 10; c1_i136++) {
    c1_d_y[c1_i136] = 0.0F;
    for (c1_i137 = 0; c1_i137 < 26; c1_i137++) {
      c1_d_y[c1_i136] += c1_b_a[c1_i137] * (real32_T)c1_c_b[c1_i137 + c1_i135];
    }

    c1_i135 += 26;
  }

  for (c1_i138 = 0; c1_i138 < 10; c1_i138++) {
    c1_z[c1_i138] = c1_d_y[c1_i138];
  }

  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c1_c_debug_family_names,
    c1_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_b_nargin, 0U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_b_nargout, 1U,
    c1_g_sf_marshallOut, c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_z, 2U, c1_l_sf_marshallOut,
    c1_k_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_h3, 3U, c1_l_sf_marshallOut,
    c1_k_sf_marshallIn);
  CV_EML_FCN(0, 2);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 59);
  for (c1_i139 = 0; c1_i139 < 10; c1_i139++) {
    c1_d_y[c1_i139] = -c1_z[c1_i139];
  }

  for (c1_k = 1.0; c1_k <= 10.0; c1_k++) {
    c1_b_k = c1_k;
    c1_x = c1_d_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c1_b_k), 1, 10, 1, 0) - 1];
    c1_b_x = c1_x;
    c1_b_x = muSingleScalarExp(c1_b_x);
    c1_d_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c1_b_k), 1, 10, 1, 0) - 1] = c1_b_x;
  }

  for (c1_i140 = 0; c1_i140 < 10; c1_i140++) {
    c1_d_y[c1_i140]++;
  }

  for (c1_i141 = 0; c1_i141 < 10; c1_i141++) {
    c1_h3[c1_i141] = 1.0F / c1_d_y[c1_i141];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -59);
  sf_debug_symbol_scope_pop();
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 48);
  for (c1_i142 = 0; c1_i142 < 10; c1_i142++) {
    c1_d_y[c1_i142] = c1_h3[c1_i142];
  }

  c1_mtmp = c1_d_y[0];
  c1_itmp = 1;
  c1_ix = 1;
  c1_c_x = c1_mtmp;
  c1_d_b = muSingleScalarIsNaN(c1_c_x);
  guard1 = FALSE;
  if (c1_d_b) {
    c1_searchingForNonNaN = TRUE;
    c1_c_k = 2;
    exitg1 = 0U;
    while ((exitg1 == 0U) && (c1_c_k < 11)) {
      c1_d_k = c1_c_k;
      c1_c_a = c1_ix + 1;
      c1_ix = c1_c_a;
      c1_d_x = c1_d_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_ix), 1, 10, 1, 0) - 1];
      c1_e_b = muSingleScalarIsNaN(c1_d_x);
      if (!c1_e_b) {
        c1_mtmp = c1_d_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_ix), 1, 10, 1, 0) - 1];
        c1_itmp = c1_d_k;
        c1_searchingForNonNaN = FALSE;
        exitg1 = 1U;
      } else {
        c1_c_k++;
      }
    }

    if (c1_searchingForNonNaN) {
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c1_d_a = c1_itmp + 1;
    c1_i143 = c1_d_a;
    for (c1_b_ix = c1_i143; c1_b_ix < 11; c1_b_ix++) {
      c1_ix = c1_b_ix;
      if (c1_d_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_ix), 1, 10, 1, 0) - 1] > c1_mtmp) {
        c1_mtmp = c1_d_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_ix), 1, 10, 1, 0) - 1];
        c1_itmp = c1_ix;
      }
    }
  }

  c1_b_mtmp = c1_mtmp;
  c1_b_itmp = c1_itmp;
  c1_maxval = c1_b_mtmp;
  c1_indx = (real_T)c1_b_itmp;
  c1_b_prob = c1_maxval;
  c1_b_p = c1_indx;
  *c1_prob = c1_b_prob;
  *c1_p = c1_b_p;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -48);
  sf_debug_symbol_scope_pop();
}

static void c1_sigmoid(SFc1_Reconocedor_numeroInstanceStruct *chartInstance,
  real32_T c1_z[25], real32_T c1_g[25])
{
  uint32_T c1_debug_family_var_map[4];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i144;
  real32_T c1_x[25];
  real_T c1_k;
  real_T c1_b_k;
  real32_T c1_b_x;
  real32_T c1_c_x;
  int32_T c1_i145;
  int32_T c1_i146;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c1_b_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 0U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 1U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_z, 2U, c1_k_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_g, 3U, c1_k_sf_marshallOut,
    c1_j_sf_marshallIn);
  CV_EML_FCN(0, 2);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 59);
  for (c1_i144 = 0; c1_i144 < 25; c1_i144++) {
    c1_x[c1_i144] = -c1_z[c1_i144];
  }

  for (c1_k = 1.0; c1_k <= 25.0; c1_k++) {
    c1_b_k = c1_k;
    c1_b_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c1_b_k), 1, 25, 1, 0) - 1];
    c1_c_x = c1_b_x;
    c1_c_x = muSingleScalarExp(c1_c_x);
    c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k),
      1, 25, 1, 0) - 1] = c1_c_x;
  }

  for (c1_i145 = 0; c1_i145 < 25; c1_i145++) {
    c1_x[c1_i145]++;
  }

  for (c1_i146 = 0; c1_i146 < 25; c1_i146++) {
    c1_g[c1_i146] = 1.0F / c1_x[c1_i146];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -59);
  sf_debug_symbol_scope_pop();
}

static const mxArray *c1_m_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static int32_T c1_n_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i147;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i147, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i147;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_o_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_Reconocedor_numero, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_Reconocedor_numero), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_Reconocedor_numero);
  return c1_y;
}

static uint8_T c1_p_emlrt_marshallIn(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_Reconocedor_numeroInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_Reconocedor_numero_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(191205555U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2370823997U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2749909011U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2749344828U);
}

mxArray *sf_c1_Reconocedor_numero_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3343904336U);
    pr[1] = (double)(1790805206U);
    pr[2] = (double)(3292337290U);
    pr[3] = (double)(2245340416U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(480);
      pr[1] = (double)(640);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(480);
      pr[1] = (double)(640);
      pr[2] = (double)(3);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(25);
      pr[1] = (double)(401);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(25);
      pr[1] = (double)(26);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(26);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(480);
      pr[1] = (double)(640);
      pr[2] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(2);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_Reconocedor_numero(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[8],T\"Imagen\",},{M[1],M[9],T\"Resultado\",},{M[8],M[0],T\"is_active_c1_Reconocedor_numero\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Reconocedor_numero_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
    chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Reconocedor_numeroMachineNumber_,
           1,
           1,
           1,
           7,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_Reconocedor_numeroMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_Reconocedor_numeroMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_Reconocedor_numeroMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"BN");
          _SFD_SET_DATA_PROPS(1,1,1,0,"RGB");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Imagen");
          _SFD_SET_DATA_PROPS(3,2,0,1,"Resultado");
          _SFD_SET_DATA_PROPS(4,10,0,0,"Theta2");
          _SFD_SET_DATA_PROPS(5,10,0,0,"Theta3");
          _SFD_SET_DATA_PROPS(6,10,0,0,"Theta1");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,3,1,0,0,2,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,831);
        _SFD_CV_INIT_EML_FCN(0,1,"predict",833,-1,1402);
        _SFD_CV_INIT_EML_FCN(0,2,"sigmoid",1404,-1,1540);
        _SFD_CV_INIT_EML_IF(0,0,729,749,-1,769);
        _SFD_CV_INIT_EML_FOR(0,0,129,152,329);
        _SFD_CV_INIT_EML_FOR(0,1,330,353,528);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 480;
          dimVector[1]= 640;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 480;
          dimVector[1]= 640;
          dimVector[2]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 480;
          dimVector[1]= 640;
          dimVector[2]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_SINGLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)
            c1_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 25;
          dimVector[1]= 26;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)
            c1_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 10;
          dimVector[1]= 26;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 25;
          dimVector[1]= 401;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)
            c1_c_sf_marshallIn);
        }

        {
          real32_T (*c1_BN)[307200];
          real32_T (*c1_RGB)[921600];
          real32_T (*c1_Imagen)[921600];
          real32_T (*c1_Resultado)[2];
          c1_Resultado = (real32_T (*)[2])ssGetOutputPortSignal(chartInstance->S,
            2);
          c1_Imagen = (real32_T (*)[921600])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c1_RGB = (real32_T (*)[921600])ssGetInputPortSignal(chartInstance->S,
            1);
          c1_BN = (real32_T (*)[307200])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_BN);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_RGB);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_Imagen);
          _SFD_SET_DATA_VALUE_PTR(3U, *c1_Resultado);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c1_Theta2);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c1_Theta3);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c1_Theta1);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_Reconocedor_numeroMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_Reconocedor_numero(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_Reconocedor_numeroInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_Reconocedor_numero((SFc1_Reconocedor_numeroInstanceStruct*)
    chartInstanceVar);
  initialize_c1_Reconocedor_numero((SFc1_Reconocedor_numeroInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_Reconocedor_numero(void *chartInstanceVar)
{
  enable_c1_Reconocedor_numero((SFc1_Reconocedor_numeroInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_Reconocedor_numero(void *chartInstanceVar)
{
  disable_c1_Reconocedor_numero((SFc1_Reconocedor_numeroInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_Reconocedor_numero(void *chartInstanceVar)
{
  sf_c1_Reconocedor_numero((SFc1_Reconocedor_numeroInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_Reconocedor_numero(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_Reconocedor_numero
    ((SFc1_Reconocedor_numeroInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_Reconocedor_numero();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_Reconocedor_numero(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_Reconocedor_numero();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_Reconocedor_numero((SFc1_Reconocedor_numeroInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_Reconocedor_numero(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_Reconocedor_numero(S);
}

static void sf_opaque_set_sim_state_c1_Reconocedor_numero(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_Reconocedor_numero(S, st);
}

static void sf_opaque_terminate_c1_Reconocedor_numero(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_Reconocedor_numeroInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_Reconocedor_numero((SFc1_Reconocedor_numeroInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_Reconocedor_numero((SFc1_Reconocedor_numeroInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Reconocedor_numero(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_Reconocedor_numero
      ((SFc1_Reconocedor_numeroInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_Reconocedor_numero(SimStruct *S)
{
  /* Actual parameters from chart:
     Theta1 Theta2 Theta3
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Theta1*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for Theta2*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for Theta3*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"Reconocedor_numero","Reconocedor_numero",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"Reconocedor_numero",
                "Reconocedor_numero",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"Reconocedor_numero",
      "Reconocedor_numero",1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Reconocedor_numero",
        "Reconocedor_numero",1,2);
      sf_mark_chart_reusable_outputs(S,"Reconocedor_numero","Reconocedor_numero",
        1,2);
    }

    sf_set_rtw_dwork_info(S,"Reconocedor_numero","Reconocedor_numero",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2509475574U));
  ssSetChecksum1(S,(1254780231U));
  ssSetChecksum2(S,(1662024775U));
  ssSetChecksum3(S,(1805459445U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_Reconocedor_numero(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Reconocedor_numero", "Reconocedor_numero",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_Reconocedor_numero(SimStruct *S)
{
  SFc1_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc1_Reconocedor_numeroInstanceStruct *)malloc(sizeof
    (SFc1_Reconocedor_numeroInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_Reconocedor_numeroInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_Reconocedor_numero;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_Reconocedor_numero;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_Reconocedor_numero;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_Reconocedor_numero;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_Reconocedor_numero;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_Reconocedor_numero;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_Reconocedor_numero;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_Reconocedor_numero;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Reconocedor_numero;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_Reconocedor_numero;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_Reconocedor_numero;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_Reconocedor_numero_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Reconocedor_numero(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Reconocedor_numero(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Reconocedor_numero(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Reconocedor_numero_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
