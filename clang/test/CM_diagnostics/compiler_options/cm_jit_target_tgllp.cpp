#include <cm/cm.h>

_GENX_MAIN_
void test() {
}


#define STRING2(x) #x
#define STRING(x) STRING2(x)

#ifdef CM_GENX
#pragma message ( "CM_GENX defined with value " STRING(CM_GENX) )
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
#warning CM_GEN9 defined
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

#ifdef CM_GEN11LP
#warning CM_GEN11LP defined
#endif

#ifdef CM_GEN12
#warning CM_GEN12 defined
#endif



// We test a number of different ways to specify a tgl jit target option.
// All are equivalent, and should produce the same results, so we only need
// one set of CHECK values for all of these tests.
// We check the expected Gen variant macros are defined (and no others), and
// that the Finalizer is called with the expected platform option.
// We also check that the expected files are generated by deleting them,
// which also leaves things tidy for the next test.

// XFAIL: *
// RUN: %cmc -mCM_printfargs -mCM_old_asm_name -mdump_asm -march=GEN12LP %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -mCM_printfargs -mCM_old_asm_name -mdump_asm -march=TGLLP %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat


// CHECK: cm_jit_target_tgllp.cpp(12,9):  warning: CM_GENX defined with value 1250 [-W#pragma-messages]
// CHECK: 2 warnings generated.
// CHECK: -platform TGLLP
