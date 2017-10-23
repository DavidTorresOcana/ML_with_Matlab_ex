/* Include files */

#include "blascompat32.h"
#include "Reconocedor_numero_sfun.h"
#include "c2_Reconocedor_numero.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Reconocedor_numero_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[4] = { "nargin", "nargout", "RGB",
  "BN" };

/* Function Declarations */
static void initialize_c2_Reconocedor_numero
  (SFc2_Reconocedor_numeroInstanceStruct *chartInstance);
static void initialize_params_c2_Reconocedor_numero
  (SFc2_Reconocedor_numeroInstanceStruct *chartInstance);
static void enable_c2_Reconocedor_numero(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance);
static void disable_c2_Reconocedor_numero(SFc2_Reconocedor_numeroInstanceStruct *
  chartInstance);
static void c2_update_debugger_state_c2_Reconocedor_numero
  (SFc2_Reconocedor_numeroInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_Reconocedor_numero
  (SFc2_Reconocedor_numeroInstanceStruct *chartInstance);
static void set_sim_state_c2_Reconocedor_numero
  (SFc2_Reconocedor_numeroInstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_Reconocedor_numero(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance);
static void sf_c2_Reconocedor_numero(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance);
static void initSimStructsc2_Reconocedor_numero
  (SFc2_Reconocedor_numeroInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c2_BN, const char_T *c2_identifier, real32_T
  c2_y[307200]);
static void c2_b_emlrt_marshallIn(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real32_T c2_y[307200]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_Reconocedor_numero, const
  char_T *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_Reconocedor_numero
  (SFc2_Reconocedor_numeroInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_Reconocedor_numero = 0U;
}

static void initialize_params_c2_Reconocedor_numero
  (SFc2_Reconocedor_numeroInstanceStruct *chartInstance)
{
}

static void enable_c2_Reconocedor_numero(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_Reconocedor_numero(SFc2_Reconocedor_numeroInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_Reconocedor_numero
  (SFc2_Reconocedor_numeroInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_Reconocedor_numero
  (SFc2_Reconocedor_numeroInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  static real32_T c2_u[307200];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real32_T (*c2_BN)[307200];
  c2_BN = (real32_T (*)[307200])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  for (c2_i0 = 0; c2_i0 < 307200; c2_i0++) {
    c2_u[c2_i0] = (*c2_BN)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 1, 0U, 1U, 0U, 2, 480, 640));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_Reconocedor_numero;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_Reconocedor_numero
  (SFc2_Reconocedor_numeroInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  static real32_T c2_fv0[307200];
  int32_T c2_i1;
  real32_T (*c2_BN)[307200];
  c2_BN = (real32_T (*)[307200])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "BN",
                      c2_fv0);
  for (c2_i1 = 0; c2_i1 < 307200; c2_i1++) {
    (*c2_BN)[c2_i1] = c2_fv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_Reconocedor_numero = c2_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_Reconocedor_numero");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_Reconocedor_numero(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_Reconocedor_numero(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance)
{
}

static void sf_c2_Reconocedor_numero(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  static real32_T c2_RGB[921600];
  uint32_T c2_debug_family_var_map[4];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  static real32_T c2_BN[307200];
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  static real32_T c2_A[307200];
  int32_T c2_i8;
  int32_T c2_i9;
  real32_T (*c2_b_BN)[307200];
  real32_T (*c2_b_RGB)[921600];
  c2_b_BN = (real32_T (*)[307200])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_RGB = (real32_T (*)[921600])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i2 = 0; c2_i2 < 921600; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_b_RGB)[c2_i2], 0U);
  }

  for (c2_i3 = 0; c2_i3 < 307200; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_b_BN)[c2_i3], 1U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i4 = 0; c2_i4 < 921600; c2_i4++) {
    c2_RGB[c2_i4] = (*c2_b_RGB)[c2_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 0U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 1U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_RGB, 2U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_BN, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_i5 = 0;
  for (c2_i6 = 0; c2_i6 < 640; c2_i6++) {
    for (c2_i7 = 0; c2_i7 < 480; c2_i7++) {
      c2_A[c2_i7 + c2_i5] = (c2_RGB[c2_i7 + c2_i5] + c2_RGB[(c2_i7 + c2_i5) +
        307200]) + c2_RGB[(c2_i7 + c2_i5) + 614400];
    }

    c2_i5 += 480;
  }

  for (c2_i8 = 0; c2_i8 < 307200; c2_i8++) {
    c2_BN[c2_i8] = c2_A[c2_i8] / 3.0F;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -3);
  sf_debug_symbol_scope_pop();
  for (c2_i9 = 0; c2_i9 < 307200; c2_i9++) {
    (*c2_b_BN)[c2_i9] = c2_BN[c2_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  sf_debug_check_for_state_inconsistency(_Reconocedor_numeroMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_Reconocedor_numero
  (SFc2_Reconocedor_numeroInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  static real32_T c2_b_inData[307200];
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  static real32_T c2_u[307200];
  const mxArray *c2_y = NULL;
  SFc2_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc2_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i10 = 0;
  for (c2_i11 = 0; c2_i11 < 640; c2_i11++) {
    for (c2_i12 = 0; c2_i12 < 480; c2_i12++) {
      c2_b_inData[c2_i12 + c2_i10] = (*(real32_T (*)[307200])c2_inData)[c2_i12 +
        c2_i10];
    }

    c2_i10 += 480;
  }

  c2_i13 = 0;
  for (c2_i14 = 0; c2_i14 < 640; c2_i14++) {
    for (c2_i15 = 0; c2_i15 < 480; c2_i15++) {
      c2_u[c2_i15 + c2_i13] = c2_b_inData[c2_i15 + c2_i13];
    }

    c2_i13 += 480;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 1, 0U, 1U, 0U, 2, 480, 640));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c2_BN, const char_T *c2_identifier, real32_T
  c2_y[307200])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_BN), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_BN);
}

static void c2_b_emlrt_marshallIn(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real32_T c2_y[307200])
{
  static real32_T c2_fv1[307200];
  int32_T c2_i16;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_fv1, 1, 1, 0U, 1, 0U, 2, 480,
                640);
  for (c2_i16 = 0; c2_i16 < 307200; c2_i16++) {
    c2_y[c2_i16] = c2_fv1[c2_i16];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_BN;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  static real32_T c2_y[307200];
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  SFc2_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc2_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c2_BN = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_BN), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_BN);
  c2_i17 = 0;
  for (c2_i18 = 0; c2_i18 < 640; c2_i18++) {
    for (c2_i19 = 0; c2_i19 < 480; c2_i19++) {
      (*(real32_T (*)[307200])c2_outData)[c2_i19 + c2_i17] = c2_y[c2_i19 +
        c2_i17];
    }

    c2_i17 += 480;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  static real32_T c2_b_inData[921600];
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  static real32_T c2_u[921600];
  const mxArray *c2_y = NULL;
  SFc2_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc2_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i20 = 0;
  for (c2_i21 = 0; c2_i21 < 3; c2_i21++) {
    c2_i22 = 0;
    for (c2_i23 = 0; c2_i23 < 640; c2_i23++) {
      for (c2_i24 = 0; c2_i24 < 480; c2_i24++) {
        c2_b_inData[(c2_i24 + c2_i22) + c2_i20] = (*(real32_T (*)[921600])
          c2_inData)[(c2_i24 + c2_i22) + c2_i20];
      }

      c2_i22 += 480;
    }

    c2_i20 += 307200;
  }

  c2_i25 = 0;
  for (c2_i26 = 0; c2_i26 < 3; c2_i26++) {
    c2_i27 = 0;
    for (c2_i28 = 0; c2_i28 < 640; c2_i28++) {
      for (c2_i29 = 0; c2_i29 < 480; c2_i29++) {
        c2_u[(c2_i29 + c2_i27) + c2_i25] = c2_b_inData[(c2_i29 + c2_i27) +
          c2_i25];
      }

      c2_i27 += 480;
    }

    c2_i25 += 307200;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 1, 0U, 1U, 0U, 3, 480, 640, 3));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc2_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc2_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_Reconocedor_numero_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[3];
  c2_ResolvedFunctionInfo (*c2_b_info)[3];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i30;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[3])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "mrdivide";
  (*c2_b_info)[0].dominantType = "single";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[0].fileTimeLo = 2117098240U;
  (*c2_b_info)[0].fileTimeHi = 30130935U;
  (*c2_b_info)[0].mFileTimeLo = 3573034496U;
  (*c2_b_info)[0].mFileTimeHi = 30114299U;
  (*c2_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[1].name = "rdivide";
  (*c2_b_info)[1].dominantType = "single";
  (*c2_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[1].fileTimeLo = 1847391744U;
  (*c2_b_info)[1].fileTimeHi = 30108011U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[2].name = "eml_div";
  (*c2_b_info)[2].dominantType = "single";
  (*c2_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c2_b_info)[2].fileTimeLo = 387391744U;
  (*c2_b_info)[2].fileTimeHi = 30108011U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 3));
  for (c2_i30 = 0; c2_i30 < 3; c2_i30++) {
    c2_r0 = &c2_info[c2_i30];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i30);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i30);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i30);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i30);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i30);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i30);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i30);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i30);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc2_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i31;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i31, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i31;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc2_Reconocedor_numeroInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_Reconocedor_numero, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_Reconocedor_numero), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_Reconocedor_numero);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_Reconocedor_numeroInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_Reconocedor_numero_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4115846878U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3788495348U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(230129529U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1560026494U);
}

mxArray *sf_c2_Reconocedor_numero_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1117659117U);
    pr[1] = (double)(1012602794U);
    pr[2] = (double)(1120277705U);
    pr[3] = (double)(1111615371U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_Reconocedor_numero(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"BN\",},{M[8],M[0],T\"is_active_c2_Reconocedor_numero\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_Reconocedor_numero_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_Reconocedor_numeroInstanceStruct *chartInstance;
    chartInstance = (SFc2_Reconocedor_numeroInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Reconocedor_numeroMachineNumber_,
           2,
           1,
           1,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"RGB");
          _SFD_SET_DATA_PROPS(1,2,0,1,"BN");
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
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,78);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 480;
          dimVector[1]= 640;
          dimVector[2]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_SINGLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 480;
          dimVector[1]= 640;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          real32_T (*c2_RGB)[921600];
          real32_T (*c2_BN)[307200];
          c2_BN = (real32_T (*)[307200])ssGetOutputPortSignal(chartInstance->S,
            1);
          c2_RGB = (real32_T (*)[921600])ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_RGB);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_BN);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_Reconocedor_numeroMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_Reconocedor_numero(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_Reconocedor_numeroInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_Reconocedor_numero((SFc2_Reconocedor_numeroInstanceStruct*)
    chartInstanceVar);
  initialize_c2_Reconocedor_numero((SFc2_Reconocedor_numeroInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_Reconocedor_numero(void *chartInstanceVar)
{
  enable_c2_Reconocedor_numero((SFc2_Reconocedor_numeroInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_Reconocedor_numero(void *chartInstanceVar)
{
  disable_c2_Reconocedor_numero((SFc2_Reconocedor_numeroInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_Reconocedor_numero(void *chartInstanceVar)
{
  sf_c2_Reconocedor_numero((SFc2_Reconocedor_numeroInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_Reconocedor_numero(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_Reconocedor_numero
    ((SFc2_Reconocedor_numeroInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Reconocedor_numero();/* state var info */
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

extern void sf_internal_set_sim_state_c2_Reconocedor_numero(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Reconocedor_numero();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_Reconocedor_numero((SFc2_Reconocedor_numeroInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_Reconocedor_numero(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_Reconocedor_numero(S);
}

static void sf_opaque_set_sim_state_c2_Reconocedor_numero(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_Reconocedor_numero(S, st);
}

static void sf_opaque_terminate_c2_Reconocedor_numero(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_Reconocedor_numeroInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_Reconocedor_numero((SFc2_Reconocedor_numeroInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_Reconocedor_numero((SFc2_Reconocedor_numeroInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Reconocedor_numero(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_Reconocedor_numero
      ((SFc2_Reconocedor_numeroInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_Reconocedor_numero(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"Reconocedor_numero","Reconocedor_numero",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"Reconocedor_numero",
                "Reconocedor_numero",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"Reconocedor_numero",
      "Reconocedor_numero",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Reconocedor_numero",
        "Reconocedor_numero",2,1);
      sf_mark_chart_reusable_outputs(S,"Reconocedor_numero","Reconocedor_numero",
        2,1);
    }

    sf_set_rtw_dwork_info(S,"Reconocedor_numero","Reconocedor_numero",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(309529235U));
  ssSetChecksum1(S,(2181550015U));
  ssSetChecksum2(S,(2885293111U));
  ssSetChecksum3(S,(2839617997U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_Reconocedor_numero(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Reconocedor_numero", "Reconocedor_numero",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Reconocedor_numero(SimStruct *S)
{
  SFc2_Reconocedor_numeroInstanceStruct *chartInstance;
  chartInstance = (SFc2_Reconocedor_numeroInstanceStruct *)malloc(sizeof
    (SFc2_Reconocedor_numeroInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_Reconocedor_numeroInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_Reconocedor_numero;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_Reconocedor_numero;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_Reconocedor_numero;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_Reconocedor_numero;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_Reconocedor_numero;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_Reconocedor_numero;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_Reconocedor_numero;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_Reconocedor_numero;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_Reconocedor_numero;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_Reconocedor_numero;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_Reconocedor_numero;
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

void c2_Reconocedor_numero_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Reconocedor_numero(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Reconocedor_numero(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Reconocedor_numero(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_Reconocedor_numero_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
