/* Testing Code */

#include <limits.h>
#include <math.h>

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
    union {
        unsigned u;
        float f;
    } a;
    a.u = u;
    return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
    union {
        unsigned u;
        float f;
    } a;
    a.f = f;
    return a.u;
}
//1
long test_bitXor(long x, long y)
{
  return x^y;
}
long test_tmin(void) {
  return 0x8000000000000000L;
}
long test_isTmax(long x) {
    return x == 0x7FFFFFFFFFFFFFFFL;
}
//2
long test_allOddBits(long x) {
  int i;
  for (i = 1; i < 64; i+=2)
      if ((x & (1L<<i)) == 0)
          return 0L;
  return 1L;
}
long test_negate(long x) {
  return -x;
}
//3
long test_conditional(long x, long y, long z)
{
  return x?y:z;
}
long test_rotateLeft(long x, long n) {
  unsigned long u = (unsigned long) x;
  long i;
  for (i = 0; i < n; i++) {
      unsigned long msb = u >> 63;
      unsigned long rest = u << 1;
      u = rest | msb;
  }
  return (long) u;
}
long test_isLessOrEqual(long x, long y)
{
    return (long) (x <= y);
}
//4
long test_allAsciiDigits(long x) {
    int i;
    long ok = 1;
    for (i = 0; i < 64; i+=8) {
        long b = (x >> i) & 0xFF;
        ok = ok && (0x30 <= b) && (b <= 0x39);
    }
    return ok;
}
long test_bitParity(long x) {
  long result = 0;
  int i;
  for (i = 0; i < 64; i++)
    result ^= (x >> i) & 0x1L;
  return result;
}
long test_logicalNeg(long x)
{
  return !x;
}
//float
int test_floatIsLess(unsigned uf, unsigned ug) {
    float f = u2f(uf);
    float g = u2f(ug);
    return f < g;
}
unsigned test_floatScale1d2(unsigned uf) {
  float f = u2f(uf);
  float hf = 0.5*f;
  if (isnan(f))
    return uf;
  else
    return f2u(hf);
}
unsigned test_floatUnsigned2Float(unsigned u) {
    float f = (float) u;
    return f2u(f);
}
