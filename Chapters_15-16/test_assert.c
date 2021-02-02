//
// Created by ulysses on 6/1/17.
//
#include<stdio.h>
#include<limits.h>
_Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");
int main(void)
{
    puts("char is 16 bits.");
    return 0;
}
/*
 * The assert() expression is a run-time check. C11 adds a feature, the _Static_assert declaration,
 * that does a compile-time check. So, assert() can cause a running program to abort,
 * while _Static_assert() can cause a program not to compile. The latter takes two arguments.
 * The first is a constant integer expression, and the second is a string. If the first expression
 * evaluates to 0 (or _False), the compiler displays the string and does not compile the program.
 *
*/