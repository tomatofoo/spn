/*
    MIT License

    Copyright (c) 2026 Tomatofu

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#ifndef INCLUDE_SPN_H
#define INCLUDE_SPN_H

#if !(defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L)
SPN_H_REQUIRES_ATLEAST_C99
#endif

#ifdef SPN_H_IMPLEMENTATION


/* includes */
#include <stdbool.h>
#include <stdlib.h>

#ifndef SPN_NO_LIBM
#include <math.h>
#endif

#ifdef SPN_THREADS_H
#include <threads.h>
#endif

/* macro settings */
#ifndef SPN_FPT
#define SPN_FPT double
#endif

/* libc functions */
#ifndef SPN_LIBC_PREFIX /* e.g. SDL_ to use SDL_stdinc.h */
#define SPN_LIBC_PREFIX
#endif

#ifndef spn_malloc
#define spn_malloc(size) SPN_LIBC_PREFIX##malloc(size)
#endif
#ifndef spn_free
#define spn_free(mem) SPN_LIBC_PREFIX##free(mem)
#endif

#ifndef spn_sin
#define spn_sin(x) SPN_LIBC_PREFIX##sin(x)
#endif
#ifndef spn_cos
#define spn_cos(x) SPN_LIBC_PREFIX##cos(x)
#endif


/* api */
typedef struct spn_vec2 {
    SPN_FPT x;
    SPN_FPT y;
} spn_vec2;

typedef struct spn_vec3 {
    SPN_FPT x;
    SPN_FPT y;
    SPN_FPT z;
} spn_vec3;


#endif /* SPN_H_IMPLEMENTATION */
#endif /* INCLUDE_SPN_H */

