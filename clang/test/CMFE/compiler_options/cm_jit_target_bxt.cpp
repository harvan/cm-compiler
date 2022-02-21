/*========================== begin_copyright_notice ============================

Copyright (C) 2015-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#include <cm/cm.h>

_GENX_MAIN_
void test() {
}

#define STRING2(x) #x
#define STRING(x) STRING2(x)

#ifdef CM_GENX
#pragma message ( "CM_GENX defined with value " STRING(CM_GENX) ) // expected-warning{{CM_GENX defined with value 920}}
#else
#warning CM_GENX not defined
#endif

#ifdef CM_GEN7_5
#warning CM_GEN7_5 defined
#endif

#ifdef CM_GEN8
#warning CM_GEN8 defined
#endif

#ifdef CM_GEN8_5
#warning CM_GEN8_5 defined
#endif

#ifdef CM_GEN9
#warning CM_GEN9 defined // expected-warning{{CM_GEN9 defined}}
#endif

#ifdef CM_GEN9_5
#warning CM_GEN9_5 defined
#endif

#ifdef CM_GEN10
#warning CM_GEN10 defined
#endif

#ifdef CM_GEN10_5
#warning CM_GEN10_5 defined
#endif

#ifdef CM_GEN11
#warning CM_GEN11 defined
#endif

// We test a number of different ways to specify a BXT jit target option.
// All are equivalent, and should produce the same results, so we only need
// one set of CHECK values for all of these tests.
// We check the expected Gen variant macros are defined (and no others), and
// that the Finalizer is called with the expected platform option.
// We also check that the expected files are generated by deleting them, 
// which also leaves things tidy for the next test.

// RUN: %cmc -emit-llvm -Qxcm_jit_target=bxt -Xclang -verify -Xclang -verify-ignore-unexpected -- %s

// RUN: %cmc -emit-llvm -Qxcm_jit_target:bxt -Xclang -verify -Xclang -verify-ignore-unexpected -- %s

// RUN: %cmc -emit-llvm -Qxcm_jit_targetbxt -Xclang -verify -Xclang -verify-ignore-unexpected -- %s

// RUN: %cmc -emit-llvm -Qxcm_jit_target=gen9lp -Xclang -verify -Xclang -verify-ignore-unexpected -- %s

// RUN: %cmc -emit-llvm -Qxcm_jit_target=GEN9LP -Xclang -verify -Xclang -verify-ignore-unexpected -- %s

// RUN: %cmc -emit-llvm /Qxcm_jit_target=BXT -Xclang -verify -Xclang -verify-ignore-unexpected -- %s

// RUN: %cmc -emit-llvm /Qxcm_jit_target:bxT -Xclang -verify -Xclang -verify-ignore-unexpected -- %s

// RUN: %cmc -emit-llvm /Qxcm_jit_targetBxt -Xclang -verify -Xclang -verify-ignore-unexpected -- %s

// RUN: %cmc -emit-llvm /Qxcm_jit_targetbXt -Xclang -verify -Xclang -verify-ignore-unexpected -- %s

// RUN: %cmc -emit-llvm -Qxcm_jit_target -mcpu=BXT -Xclang -verify -Xclang -verify-ignore-unexpected -- %s

// RUN: %cmc -emit-llvm -Qxcm_jit_target -mcpu=gEN9lP -Xclang -verify -Xclang -verify-ignore-unexpected -- %s

// RUN: %cmc -emit-llvm -march=Bxt -Qxcm_jit_target -Xclang -verify -Xclang -verify-ignore-unexpected -- %s

// RUN: %cmc -emit-llvm -Qxcm_jit_target -march=Gen9LP -Xclang -verify -Xclang -verify-ignore-unexpected -- %s

