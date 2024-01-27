/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 */

/* Instructions to Students:

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  long Funct(long arg1, long arg2, ...) {
      // brief description of how your implementation works
      long var1 = Expr1;
      ...
      long varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. (Long) integer constants 0 through 255 (0xFFL), inclusive. You are
      not allowed to use big constants such as 0xffffffffL.
  2. Function arguments and local variables (no global variables).
  3. Local variables of type int and long
  4. Unary integer operations ! ~
     - Their arguments can have types int or long
     - Note that ! always returns int, even if the argument is long
  5. Binary integer operations & ^ | + << >>
     - Their arguments can have types int or long
  6. Casting from int to long and from long to int

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting other than between int and long.
  7. Use any data type other than int or long.  This implies that you
     cannot use arrays, structs, or unions.

  You may assume that your machine:
  1. Uses 2s complement representations for int and long.
  2. Data type int is 32 bits, long is 64.
  3. Performs right shifts arithmetically.
  4. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31 (int) or 63 (long)

EXAMPLES OF ACCEPTABLE CODING STYLE:
  //
  // pow2plus1 - returns 2^x + 1, where 0 <= x <= 63
  //
  long pow2plus1(long x) {
     // exploit ability of shifts to compute powers of 2
     // Note that the 'L' indicates a long constant
     return (1L << x) + 1L;
  }

  //
  // pow2plus4 - returns 2^x + 4, where 0 <= x <= 63
  //
  long pow2plus4(long x) {
     // exploit ability of shifts to compute powers of 2
     long result = (1L << x);
     result += 4L;
     return result;
  }

NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

CAUTION:
  Do not add an #include of <stdio.h> (or any other C library header)
  to this file.  C library headers almost always contain constructs
  that dlc does not understand.  For debugging, you can use printf,
  which is declared for you just below.  It is normally bad practice
  to declare C library functions by hand, but in this case it's less
  trouble than any alternative.

  dlc will consider each call to printf to be a violation of the
  coding style (function calls, after all, are not allowed) so you
  must remove all your debugging printf's again before submitting your
  code or testing it with dlc or the BDD checker.  */

extern int printf(const char *, ...);

/* Edit the functions below.  Good luck!  */
// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4L, 5L) = 1L
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
long bitXor(long x, long y) {
    // XOR meant to find the different bit between two variables, but we could only use &
    // use & to get the same bits and then use ~ to convert them and then we will get the different bits
    // At last use & to get the 
    long res = ~(x & y) & (~((~x) & (~y)));
    return res;
}
/*
 * tmin - return minimum two's complement long integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
long tmin(void) {
    // smallest long in bits looks like 1 at the leftmost bit abd the rest are 0s
    // Therefore left shift 1 by 63
    long res = 1L << 63;
    return res;
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
long isTmax(long x) {
    // transform every number to 0 or 1 -> use !
    // XOR checks for difference -> same will return 0
    // use !0 to output 1 and all else will output 0
    long res = !(x ^ ( ~(1L << 63)));
    return res;
}
// 2
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 63 (most significant)
 *   Examples: allOddBits(0xFFFFFFFDFFFFFFFDL) = 0L,
 *             allOddBits(0xAAAAAAAAAAAAAAAAL) = 1L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 14
 *   Rating: 2
 */
long allOddBits(long x) {
    // right shift x by one and XOR with x to create -1
    // and then plus one to make -1 to 0
    long res = !((x ^ ((x >> 1) ^ (1L << 63))) + 1L);
    return res;
}
/*
 * negate - return -x
 *   Example: negate(1L) = -1L.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
long negate(long x) {
    long res = (~x) + 1L;
    return res;
}
// 3
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4L,5L) = 4L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
// check if it is 0 
long conditional(long x, long y, long z) {
    // not 2 -> 0
    // use ((!x) + (~0L)) and (~(!x) + 1L) becomes 1 or 0 at anytime
    long res = (y & ((!x) + (~0L))) | (z & (~(!x) + 1L));
    return res;
}
/*
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 63
 *   Examples:
 *      rotateLeft(0x8765432187654321L,4L) = 0x7654321876543218L
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
long rotateLeft(long x, long n) {
    long mask = (1L << 63) >> n;
    long shift_bits = x & mask;
    // right shift by 63-n
    // to check if the n is 0, if not create a mask for shift bits 
    long shift_mask = (((1L << n) + (~0)) & ((!n) + (~0L))) | (0 & (~(!n) + 1L));

    shift_bits = (shift_bits >> (64L + ((~n) + 1L))) & shift_mask;
    long res = (x << n) + shift_bits;
    return res;
    return 2;
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4L,5L) = 1L.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
long isLessOrEqual(long x, long y) {
    // check the leftmost bit to see if it is 1
    long negative_check = 1L << 63;
    long diff = y + ((~x) + 1L);
    long res = !((diff & negative_check) >> 63);
    return res;
}
// 4
/*
 * allAsciiDigits - return 1 if each byte b in x satisfies
 *   0x30 <= b <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: allAsciiDigits(0x3031323536373839L) = 1L.
 *            allAsciiDigits(0x4031323536373839L) = 0L.
 *            allAsciiDigits(0x0031323536373839L) = 0L.
 *   Legal ops: ! ~ & ^ | << >>
 *   Max ops: 30
 *   Rating: 4
 */
// two mask gen one from other
long allAsciiDigits(long x) {
    return 2; 
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5L) = 0L, bitParity(7L) = 1L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 22
 *   Rating: 4
 */ 
long bitParity(long x) {
    // the least significant bit will be discarded because of XOR and right shift,
    // at last the answer will be stored at the rightmost bit
    // so we end up using &1 to get the rightmost bit
    x ^= x >> 32;
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 1;
}
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3L) = 0L, logicalNeg(0L) = 1L
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
// two complemnet 0, ~0 all 0
long logicalNeg(long x) {
    // the OR will let the left most bit(most significant) turns to 1 all the time
    // right shift the one to the least significant bit and the value will become -1 always
    long res = ((x | (~x) + 1L) >> 63) + 1L;
    return res;
}
// float
/*
 * floatIsLess - Compute f < g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
int floatIsLess(unsigned uf, unsigned ug) {
    return 2;
    // compare sign
    // 
}
/*
 * floatScale1d2 - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
// minus one to the exp part
// if exponent is 0 -> right shift by 1
// if exponent is all 1's => inf
// if exponent is all 1's and frac not 0 => Nan
unsigned floatScale1d2(unsigned uf) {
    unsigned sign_mask = 1u<<31;
    unsigned sign = uf & sign_mask;

    unsigned exp_mask = 255u << 23;
    unsigned exp = (uf & exp_mask)>>23;

    unsigned frac_mask = (1u << 23) - 1u;
    unsigned frac = uf & frac_mask;

    if (exp == 0u) { // denormal
        if (frac == 3u) { // round up for 011
            frac = 1u;
        } else {
            frac >>= 1;
        }
    }
    else if (exp == 1u) { // norm to denorm
        frac = (frac >> 1) | (1u << 22);
        exp = 0u;
    } 
    else if (exp == exp_mask) { // special 
        return uf;
    }
    else { // norm
        exp -= 1u;
    }
    return sign + (exp << 23) + frac;
}
/*
 * floatUnsigned2Float - Return bit-level equivalent of expression (float) u
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatUnsigned2Float(unsigned u) {
    unsigned sign_mask = 1u << 31;
    unsigned sign = u & sign_mask;

    unsigned exp_mask = 255u << 23;
    unsigned exp = (u & exp_mask) >> 23;

    unsigned frac_mask = (1u << 23) - 1u;
    unsigned frac = u & frac_mask;

    return sign + (exp << 23) + frac;
}
