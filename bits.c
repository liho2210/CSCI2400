/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/*
 * Total: 25 pts
 */
/* 
 * 1-pt puzzles 
 */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) 
{
    // DeMorgan's Law
    return ~(~x | ~y);
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) 
{
    // logical conjunction
    // x xor y = (x or y) and ~(x & y)
    // DeMorgan's Law
    // (x or y) = ~(~(x or y)) = ~(~x & ~y)
    return (~(~x & ~y) & ~(x & y));
}
/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) 
{
    // logical negation
    // !0 = 1
    // !(x!=0) = 0
    return !(x);
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) 
{
    // in scope of 32 bits
    // new variable equals input shifted 16 bits to the left
    // results in lower 16 bits being all 0's
    int temp = x << 16;
    
    // shift 16 bits back to the right
    // results in higher 16 bits being all 1's
    temp = temp >> 16;
    
    // if new variable is equal to original input after the shift then it can be represented as a 16 bit number
    // bitwise xor will return 0 if the numbers are equal
    // bang operator to return 1/true if the number can fit, and 0/false if not
    return !(temp ^ x);
}
/* 
 * 2-pt puzzles
 */
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) 
{
    // no subtraction so add max n value to negative value of n
    // flip bits of n and add 1 to create a two's complement signed integer that equals -n
    int temp = 32 + (~n+1);
        
    // similar to fitsShort we shift the input left and then back right by n bits
    // when compared to the original input the xor comparison will return 0 if the input can fit
    // bang operator to return 1/true if the number can fit, and 0/false if not
    return !(x^((x << temp) >> temp));
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) 
{
    // we need to multiply n by 8 so that we can bitwise shift to the correct byte
    // set variable to equal n with a bitwise shift of 3 to the left (ie n*8)
    int temp = n << 3;
    
    // shift input right by proper number of bits
    // compare result and 0xFF, or 1111 1111, to isolate the least significant byte
    return ((x >> temp)& 0xFF);
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) 
{
    // xor comparison to yeild a 0 if x and y are equal
    // double bang operator two reduce any other answer to 1
    // if x xor y = 0, !0 = 1 and !1 = 0
    // if x xor y = (S != 0), !S = 0 and !0 = 1
    return !!(x ^ y);
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) 
{
    // right shift input by 31 bits to place signed bit in LSB place
    // or comparison with double negated input to yield correct return value
    // if x = 0 then after the shift we have all 0's
    // !!0 = 0 so the or comparison will result in 0
    // if x > 0 then after the shift we have all 0's
    // !!x will result in 1 so the or comparison will return 1
    // if x < 0 then after the shift we have all 1's
    // !!x will result in 1 again but the or comparison will result in 31 1's and a 0 in LSB = -2???
    int temp = (x >> 31);
    return (temp | !!x);
}
/* 
 * 3-pt puzzles 
 */
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) 
{    
    // variables to track sign of x and y and to hold later value for comparison
    int sign_x, sign_y, temp;
    
    // shift both x and y 31 bits to right resulting in sign bit in the LSB place
    // double bang operator to account for any 1's in the leading bits
    sign_x = !!(x >> 31);
    sign_y = !!(y >> 31);
    
    // xor comparison of x and y signs with logical negation
    // if sign_x = sign_y then result will be !0 = 1
    // if sign_x != sign_y then result will be !n = 0
    temp = (!(sign_x ^ sign_y));
    
    // flip bits of y and to x then right shift sum 31 bits and compare to 1
    // if y is signed and x is not then the result will be a one in the LSB place
    // doube bang to negate possible leading 1's
    // temp var is now result of temp bits compared to the LSB from the previous sum
    // if y < x then temp would be 0 so 0 & 0 = 0
    // if y >= x then temp would be 1 so 1 & 1 = 1
    temp = temp & !!((x + ~y) >> 31);
    
    // finally we return temp or negated y sign and x sign
    return temp | ((!sign_y) & sign_x);
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) 
{
    // *******
    //
    return (x >> n) & ~(((1 << 31) >> n) << 1);
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) 
{
    // *******
    // 
    int a = ~(~0 << n);
    int b = 33 + ~n;
    b = (x >> b);
    b = a & b;
    return b + (x << n);
}
/*
 * 4-pt puzzles
 */
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value (Tmax), and when negative overflow occurs,
 *          it returns minimum negative value (Tmin)
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) 
{
    // if x and y have different signs than the sign of thier sum then the sum is overflow
    // Tmax should be 32 bits of 1's Tmin should be all 1's with a 0 in the signed bit
    // we add the values to find sum 
    // xor comparison between each value and the sum
    // compare the two answers and right shift to place the signed bit in LSB
    // overflow var now represents the sign of the overflow
    // compare overflow with 31 or 11111 and shift sum by that value
    // add back the overflow shifted 31 bits left and return
    int sum = (x+y);
    int overflow = ((sum^x)&(sum^y)) >> 31;
    sum = (sum >> (overflow & 31)) + (overflow << 31);
    return sum;
}
/*
 * Extra credit
 */
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) 
{
    // *******
    // uf is NaN when exp is 0xff and frac is not 0.get abs by uf&0x7fffffff.
    unsigned temp = (uf & 0x7fffffff) ^ 0x7f800000;  
    if((0 < temp) && (temp <= 0x007fffff)) 
    {
        return uf;  
    }
    else
    {
        return uf & 0x7fffffff;
    }  
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  return 2;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  return 2;
}
