/* { dg-do compile { target { powerpc*-*-* } } } */
/* { dg-skip-if "do not override -mcpu" { powerpc*-*-* } { "-mcpu=*" } { "-mcpu=power9" } } */
/* { dg-require-effective-target powerpc_p9vector_ok } */
/* { dg-options "-mcpu=power9" } */

#include <altivec.h>

int
test_any_equal_or_zero (vector signed char *arg1_p, vector signed char *arg2_p)
{
  vector signed char arg_1 = *arg1_p;
  vector signed char arg_2 = *arg2_p;

  return vec_any_eqz (arg_1, arg_2);
}

/* { dg-final { scan-assembler "vcmpnezb." } } */
