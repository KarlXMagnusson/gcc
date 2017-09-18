/* { dg-do compile { target { powerpc*-*-* } } } */
/* { dg-skip-if "do not override -mcpu" { powerpc*-*-* } { "-mcpu=*" } { "-mcpu=power9" } } */
/* { dg-require-effective-target lp64 } */
/* { dg-require-effective-target powerpc_p9vector_ok } */
/* { dg-options "-mcpu=power9" } */

/* This test should succeed only on 64-bit configurations.  */
#include <altivec.h>

__ieee128
insert_exponent (unsigned __int128 *significand_p,
		 unsigned long long int *exponent_p)
{
  unsigned __int128 significand = *significand_p;
  unsigned long long int exponent = *exponent_p;

  return scalar_insert_exp (significand, exponent);
}

/* { dg-final { scan-assembler "xsiexpqp" } } */
