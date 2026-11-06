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
SPN_H_REQUIRES_ATLEAST_C99 /* define to override */
#endif

/* macro settings */
#ifndef SPN_FPT
#define SPN_FPT double
#endif

/* includes */
#include <stdbool.h>

/* structs */
typedef struct spn_vec2 {
    SPN_FPT x;
    SPN_FPT y;
} spn_vec2;

typedef struct spn_spn_vec3 {
    SPN_FPT x;
    SPN_FPT y;
    SPN_FPT z;
} spn_spn_vec3;


/* function prototypes */
bool spn_vec2_iszero(spn_vec2 vec);
SPN_FPT spn_vec2_mag(spn_vec2 vec);
SPN_FPT spn_vec2_mag_sq(spn_vec2 vec);
SPN_FPT spn_vec2_angle(spn_vec2 vec);
SPN_FPT spn_vec2_angle_deg(spn_vec2 vec);
spn_vec2 spn_vec2_unit(spn_vec2 vec);
void spn_vec2_unit_ip(spn_vec2 *vec);
spn_vec2 spn_vec2_proj(spn_vec2 term1, spn_vec2 term2);
void spn_vec2_proj_ip(spn_vec2 *term1, spn_vec2 term2);
spn_vec2 spn_vec2_add(spn_vec2 addend1, spn_vec2 addend2);
void spn_vec2_add_ip(spn_vec2 *addend1, spn_vec2 addend2);
spn_vec2 spn_vec2_sub(spn_vec2 minuend, spn_vec2 subtrahend);
void spn_vec2_sub_ip(spn_vec2 *minuend, spn_vec2 subtrahend);
spn_vec2 spn_vec2_mul(spn_vec2 multiplicand, SPN_FPT multiplier);
void spn_vec2_mul_ip(spn_vec2 *multiplicand, SPN_FPT multiplier);
spn_vec2 spn_vec2_div(spn_vec2 dividend, SPN_FPT divisor);
void spn_vec2_div_ip(spn_vec2 *dividend, SPN_FPT divisor);
spn_vec2 spn_vec2_scale(spn_vec2 vec, SPN_FPT mag);
void spn_vec2_scale_ip(spn_vec2 *vec, SPN_FPT mag);
spn_vec2 spn_vec2_lerp(spn_vec2 term1, spn_vec2 term2, SPN_FPT t);
void spn_vec2_lerp_ip(spn_vec2 *term1, spn_vec2 term2, SPN_FPT t);
spn_vec2 spn_vec2_mov(spn_vec2 term1, spn_vec2 term2, SPN_FPT disp);
void spn_vec2_mov_ip(spn_vec2 *term1, spn_vec2 term2, SPN_FPT disp);
spn_vec2 spn_vec2_rot(spn_vec2 vec, SPN_FPT angle);
void spn_vec2_rot_ip(spn_vec2 *vec, SPN_FPT angle);
spn_vec2 spn_vec2_rot_deg(spn_vec2 vec, SPN_FPT angle);
void spn_vec2_rot_deg_ip(spn_vec2 *vec, SPN_FPT angle);
SPN_FPT spn_vec2_dot(spn_vec2 term1, spn_vec2 term2);
SPN_FPT spn_vec2_cross(spn_vec2 term1, spn_vec2 term2);
SPN_FPT spn_vec2_dist(spn_vec2 term1, spn_vec2 term2);
SPN_FPT spn_vec2_dist_sq(spn_vec2 term1, spn_vec2 term2);
SPN_FPT spn_vec2_angle_to(spn_vec2 term1, spn_vec2 term2);

bool spn_vec3_iszero(spn_vec3 vec);
SPN_FPT spn_vec3_mag(spn_vec3 vec);
SPN_FPT spn_vec3_mag_sq(spn_vec3 vec);
SPN_FPT spn_vec3_angle_x(spn_vec3 vec);
SPN_FPT spn_vec3_angle_x_deg(spn_vec3 vec);
SPN_FPT spn_vec3_angle_y(spn_vec3 vec);
SPN_FPT spn_vec3_angle_y_deg(spn_vec3 vec);
SPN_FPT spn_vec3_angle_z(spn_vec3 vec);
SPN_FPT spn_vec3_angle_z_deg(spn_vec3 vec);
spn_vec3 spn_vec3_unit(spn_vec3 vec);
void spn_vec3_unit_ip(spn_vec3 *vec);
spn_vec3 spn_vec3_proj(spn_vec3 term1, spn_vec3 term2);
void spn_vec3_proj_ip(spn_vec3 *term1, spn_vec3 term2);
spn_vec3 spn_vec3_add(spn_vec3 addend1, spn_vec3 addend2);
void spn_vec3_add_ip(spn_vec3 *addend1, spn_vec3 addend2);
spn_vec3 spn_vec3_sub(spn_vec3 minuend, spn_vec3 subtrahend);
void spn_vec3_sub_ip(spn_vec3 *minuend, spn_vec3 subtrahend);
spn_vec3 spn_vec3_mul(spn_vec3 multiplicand, SPN_FPT multiplier);
void spn_vec3_mul_ip(spn_vec3 *multiplicand, SPN_FPT multiplier);
spn_vec3 spn_vec3_div(spn_vec3 dividend, SPN_FPT divisor);
void spn_vec3_div_ip(spn_vec3 *dividend, SPN_FPT divisor);
spn_vec3 spn_vec3_scale(spn_vec3 vec, SPN_FPT mag);
void spn_vec3_scale_ip(spn_vec3 *vec, SPN_FPT mag);
spn_vec3 spn_vec3_lerp(spn_vec3 term1, spn_vec3 term2, SPN_FPT t);
void spn_vec3_lerp_ip(spn_vec3 *term1, spn_vec3 term2, SPN_FPT t);
spn_vec3 spn_vec3_mov(spn_vec3 term1, spn_vec3 term2, SPN_FPT disp);
void spn_vec3_mov_ip(spn_vec3 *term1, spn_vec3 term2, SPN_FPT disp);
spn_vec3 spn_vec3_rot_x(spn_vec3 vec, SPN_FPT angle);
void spn_vec3_rot_x_ip(spn_vec3 *vec, SPN_FPT angle);
spn_vec3 spn_vec3_rot_x_deg(spn_vec3 vec, SPN_FPT angle);
void spn_vec3_rot_x_deg_ip(spn_vec3 *vec, SPN_FPT angle);
spn_vec3 spn_vec3_rot_y(spn_vec3 vec, SPN_FPT angle);
void spn_vec3_rot_y_ip(spn_vec3 *vec, SPN_FPT angle);
spn_vec3 spn_vec3_rot_y_deg(spn_vec3 vec, SPN_FPT angle);
void spn_vec3_rot_y_deg_ip(spn_vec3 *vec, SPN_FPT angle);
spn_vec3 spn_vec3_rot_z(spn_vec3 vec, SPN_FPT angle);
void spn_vec3_rot_z_ip(spn_vec3 *vec, SPN_FPT angle);
spn_vec3 spn_vec3_rot_z_deg(spn_vec3 vec, SPN_FPT angle);
void spn_vec3_rot_z_deg_ip(spn_vec3 *vec, SPN_FPT angle);
spn_vec3 spn_vec3_cross(spn_vec3 term1, spn_vec3 term2);
void spn_vec3_cross_dest(spn_vec3 term1, spn_vec3 term2, spn_vec3 *dest);
SPN_FPT spn_vec3_dot(spn_vec3 term1, spn_vec3 term2);
SPN_FPT spn_vec3_dist(spn_vec3 term1, spn_vec3 term2);
SPN_FPT spn_vec3_dist_sq(spn_vec3 term1, spn_vec3 term2);
SPN_FPT spn_vec3_angle_to(spn_vec3 term1, spn_vec3 term2);


#ifdef SPN_H_IMPLEMENTATION


/* includes */
#include <stdlib.h>
#include <tgmath.h>

#ifdef SPN_THREADS_H
#include <threads.h>
#endif

/* macro settings */
#ifndef SPN_DEF
#ifdef SPN_STATIC
#define SPN_DEF static
#elif defined(__cplusplus)
#define SPN_DEF extern "C"
#else
#define SPN_DEF extern
#endif //
#ifndef SPN_EPSILON
#define SPN_EPSILON 0.000001f
#endif
#ifndef SPN_PI
#define SPN_PI 3.14159265358979323846
#endif
#ifndef SPN_LIBC_PREFIX /* e.g. SDL_ to use SDL_stdinc.h */
#define SPN_LIBC_PREFIX
#endif

/* libc stuff */
#ifndef spn_malloc
#define spn_malloc(size) SPN_LIBC_PREFIX##malloc(size)
#endif
#ifndef spn_free
#define spn_free(mem) SPN_LIBC_PREFIX##free(mem)
#endif

#ifndef spn_sqrt
#define spn_sqrt(x) SPN_LIBC_PREFIX##sqrt(x)
#endif
#ifndef spn_hypot
#define spn_hypot(x, y) SPN_LIBC_PREFIX##hypot(x, y)
#endif
#ifndef spn_sin
#define spn_sin(x) SPN_LIBC_PREFIX##sin(x)
#endif
#ifndef spn_cos
#define spn_cos(x) SPN_LIBC_PREFIX##cos(x)
#endif
#ifndef spn_acos
#define spn_acos(x) SPN_LIBC_PREFIX##acos(x)
#endif
#ifndef spn_atan2
#define spn_atan2(y, x) SPN_LIBC_PREFIX##atan2(y, x)
#endif

/* other macros */
#define spn_d2r(x) (x * SPN_PI / 180.0f)
#define spn_r2d(x) (x * 180.0f / SPN_PI)


/* api */
bool spn_vec2_iszero(spn_vec2 vec) {
    return (
        vec.x < SPN_EPSILON && vec.x > -SPN_EPSILON
        && vec.y < SPN_EPSILON && vec.y > -SPN_EPSILON
    );
}

SPN_FPT spn_vec2_mag(spn_vec2 vec) {
    return spn_hypot(vec.x, vec.y);
}

SPN_FPT spn_vec2_mag_sq(spn_vec2 vec) {
    return spn_vec2_dot(vec, vec);
}

SPN_FPT spn_vec2_angle(spn_vec2 vec) {
    return spn_atan2(vec.y, vec.x);
}

SPN_FPT spn_vec2_angle_deg(spn_vec2 vec) {
    return spn_r2d(spn_vec2_angle(vec));
}

spn_vec2 spn_vec2_unit(spn_vec2 vec) {
    SPN_FPT mag = spn_vec2_mag(vec);
    return (spn_vec2) {vec.x / mag, vec.y / mag};
}

void spn_vec2_unit_ip(spn_vec2 *vec) {
    SPN_FPT mag = spn_vec2_mag(*vec);
    vec->x /= mag;
    vec->y /= mag;
}

spn_vec2 spn_vec2_proj(spn_vec2 term1, spn_vec2 term2) {
    return spn_vec2_mul(
        term2, spn_vec2_dot(term1, term2) / spn_vec2_dot(term2, term2)
    );
}

void spn_vec2_proj_ip(spn_vec2 *term1, spn_vec2 term2) {
    SPN_FPT mult = spn_vec2_dot(*term1, term2) / spn_vec2_dot(term2, term2);
    term1->x *= mult;
    term1->y *= mult;
}

spn_vec2 spn_vec2_add(spn_vec2 addend1, spn_vec2 addend2) {
    return (spn_vec2) {addend1.x + addend2.x, addend1.y + addend2.y};
}

void spn_vec2_add_ip(spn_vec2 *addend1, spn_vec2 addend2) {
    addend1->x += addend2.x;
    addend1->y += addend2.y;
}

spn_vec2 spn_vec2_sub(spn_vec2 minuend, spn_vec2 subtrahend) {
    return (spn_vec2) {minuend.x - subtrahend.x, minuend.y - subtrahend.y};
}

void spn_vec2_sub_ip(spn_vec2 *minuend, spn_vec2 subtrahend) {
    minuend->x -= subtrahend.x;
    minuend->y -= subtrahend.y;
}

spn_vec2 spn_vec2_mul(spn_vec2 multiplicand, SPN_FPT multiplier) {
    return (spn_vec2) {
        multiplicand.x * multiplier, multiplicand.y * multiplier
    };
}

void spn_vec2_mul_ip(spn_vec2 *multiplicand, SPN_FPT multiplier) {
    multiplicand->x *= multiplier;
    multiplicand->y *= multiplier;
}

spn_vec2 spn_vec2_div(spn_vec2 dividend, SPN_FPT divisor) {
    return (spn_vec2) {dividend.x / divisor, dividend.y / divisor};
}

void spn_vec2_div_ip(spn_vec2 *dividend, SPN_FPT divisor) {
    dividend->x /= divisor;
    dividend->y /= divisor;
}

spn_vec2 spn_vec2_scale(spn_vec2 vec, SPN_FPT mag) {
    SPN_FPT mult = mag / spn_vec2_mag(vec);
    return (spn_vec2) {vec.x * mult, vec.y * mult};
}

void spn_vec2_scale_ip(spn_vec2 *vec, SPN_FPT mag) {
    SPN_FPT mult = mag / spn_vec2_mag(*vec);
    vec->x *= mult;
    vec->y *= mult;
}

spn_vec2 spn_vec2_lerp(spn_vec2 term1, spn_vec2 term2, SPN_FPT t) {
    return (spn_vec2) {
        term1.x + (term2.x - term1.x) * t,
        term1.y + (term2.y - term1.y) * t,
    };
}

void spn_vec2_lerp_ip(spn_vec2 *term1, spn_vec2 term2, SPN_FPT t) {
    term1->x += (term2.x - term1->x) * t;
    term1->y += (term2.y - term1->y) * t;
}

spn_vec2 spn_vec2_mov(spn_vec2 term1, spn_vec2 term2, SPN_FPT disp) {
    SPN_FPT t = disp / spn_vec2_dist(term1, term2);
    return spn_vec2_lerp(term1, term2, t);
}

void spn_vec2_mov_ip(spn_vec2 *term1, spn_vec2 term2, SPN_FPT disp) {
    SPN_FPT t = disp / spn_vec2_dist(*term1, term2);
    spn_vec2_lerp_ip(term1, term2, t);
}

spn_vec2 spn_vec2_rot(spn_vec2 vec, SPN_FPT angle) {
    SPN_FPT cosine = spn_cos(angle);
    SPN_FPT sine = spn_sin(angle);
    return (spn_vec2) {
        vec.x * cosine - vec.y * sine,
        vec.x * sine + vec.y * cosine,
    };
}

void spn_vec2_rot_ip(spn_vec2 *vec, SPN_FPT angle) {
    SPN_FPT cosine = spn_cos(angle);
    SPN_FPT sine = spn_sin(angle);
    SPN_FPT x = vec->x;
    SPN_FPT y = vec->y;
    vec->x = x * cosine - y * sine;
    vec->y = x * sine + y * cosine;
}

spn_vec2 spn_vec2_rot_deg(spn_vec2 vec, SPN_FPT angle) {
    return spn_vec2_rot(vec, spn_d2r(angle));
}

void spn_vec2_rot_deg_ip(spn_vec2 *vec, SPN_FPT angle) {
    spn_vec2_rot_ip(vec, spn_d2r(angle));
}

SPN_FPT spn_vec2_dot(spn_vec2 term1, spn_vec2 term2) {
    return term1.x * term2.x + term1.y * term2.y;
}

SPN_FPT spn_vec2_cross(spn_vec2 term1, spn_vec2 term2) {
    return term1.x * term2.y - term1.y * term2.x;
}

SPN_FPT spn_vec2_dist(spn_vec2 term1, spn_vec2 term2) {
    return hypot(term2.x - term1.x, term2.y - term1.y);
}

SPN_FPT spn_vec2_dist_sq(spn_vec2 term1, spn_vec2 term2) {
    SPN_FPT x = term2.x - term1.x;
    SPN_FPT y = term2.y - term1.y;
    return x * x + y * y;
}

SPN_FPT spn_vec2_angle_to(spn_vec2 term1, spn_vec2 term2) {
    return spn_acos(
        spn_vec2_dot(term1, term2)
        / (spn_vec2_mag(term1) * spn_vec2_mag(term2))
    );
}


bool spn_vec3_iszero(spn_vec3 vec) {
    return (
        vec.x < SPN_EPSILON && vec.x > -SPN_EPSILON
        && vec.y < SPN_EPSILON && vec.y > -SPN_EPSILON
        && vec.z < SPN_EPSILON && vec.z > -SPN_EPSILON
    );
}

SPN_FPT spn_vec3_mag(spn_vec3 vec) {
    return spn_sqrt(spn_vec3_mag_sq(vec));
}

SPN_FPT spn_vec3_mag_sq(spn_vec3 vec) {
    return spn_vec3_dot(vec, vec);
}

SPN_FPT spn_vec3_angle_x(spn_vec3 vec) {
    return spn_atan2(vec.y, vec.z);
}

SPN_FPT spn_vec3_angle_x_deg(spn_vec3 vec) {
    return spn_r2d(spn_vec3_angle_x(vec));
}

SPN_FPT spn_vec3_angle_y(spn_vec3 vec) {
    return spn_atan2(vec.z, vec.x);
}

SPN_FPT spn_vec3_angle_y_deg(spn_vec3 vec) {
    return spn_r2d(spn_vec3_angle_y(vec));
}

SPN_FPT spn_vec3_angle_z(spn_vec3 vec) {
    return spn_atan2(vec.y, vec.x);
}

SPN_FPT spn_vec3_angle_z_deg(spn_vec3 vec) {
    return spn_r2d(spn_vec3_angle_z(vec));
}

spn_vec3 spn_vec3_unit(spn_vec3 vec) {
    SPN_FPT mag = spn_vec3_mag(vec);
    return (spn_vec3) {vec.x / mag, vec.y / mag, vec.z / mag};
}

void spn_vec3_unit_ip(spn_vec3 *vec) {
    SPN_FPT mag = spn_vec3_mag(*vec);
    vec->x /= mag;
    vec->y /= mag;
    vec->z /= mag;
}

spn_vec3 spn_vec3_proj(spn_vec3 term1, spn_vec3 term2) {
    return spn_vec3_mul(
        term2, spn_vec3_dot(term1, term2) / spn_vec3_dot(term2, term2)
    );
}

void spn_vec3_proj_ip(spn_vec3 *term1, spn_vec3 term2) {
    SPN_FPT mult = spn_vec3_dot(*term1, term2) / spn_vec3_dot(term2, term2);
    term1->x *= mult;
    term1->y *= mult;
    term1->z *= mult;
}

spn_vec3 spn_vec3_add(spn_vec3 addend1, spn_vec3 addend2) {
    return (spn_vec3) {
        addend1.x + addend2.x, addend1.y + addend2.y, addend1.z + addend2.z,
    };
}

void spn_vec3_add_ip(spn_vec3 *addend1, spn_vec3 addend2) {
    addend1->x += addend2.x;
    addend1->y += addend2.y;
    addend1->z += addend2.z;
}

spn_vec3 spn_vec3_sub(spn_vec3 minuend, spn_vec3 subtrahend) {
    return (spn_vec3) {
        minuend.x - subtrahend.x,
        minuend.y - subtrahend.y,
        minuend.z - subtrahend.z,
    };
}

void spn_vec3_sub_ip(spn_vec3 *minuend, spn_vec3 subtrahend) {
    minuend->x -= subtrahend.x;
    minuend->y -= subtrahend.y;
    minuend->z -= subtrahend.z;
}

spn_vec3 spn_vec3_mul(spn_vec3 multiplicand, SPN_FPT multiplier) {
    return (spn_vec3) {
        multiplicand.x * multiplier,
        multiplicand.y * multiplier,
        multiplicand.z * multiplier,
    };
}

void spn_vec3_mul_ip(spn_vec3 *multiplicand, SPN_FPT multiplier) {
    multiplicand->x *= multiplier;
    multiplicand->y *= multiplier;
    multiplicand->z *= multiplier;
}

spn_vec3 spn_vec3_div(spn_vec3 dividend, SPN_FPT divisor) {
    return (spn_vec3) {
        dividend.x / divisor, dividend.y / divisor, dividend.z / divisor,
    };
}

void spn_vec3_div_ip(spn_vec3 *dividend, SPN_FPT divisor) {
    dividend->x /= divisor;
    dividend->y /= divisor;
    dividend->z /= divisor;
}

spn_vec3 spn_vec3_scale(spn_vec3 vec, SPN_FPT mag) {
    SPN_FPT mult = mag / spn_vec3_mag(vec);
    return (spn_vec3) {vec.x * mult, vec.y * mult, vec.z * mult};
}

void spn_vec3_scale_ip(spn_vec3 *vec, SPN_FPT mag) {
    SPN_FPT mult = mag / spn_vec3_mag(*vec);
    vec->x *= mult;
    vec->y *= mult;
    vec->z *= mult;
}

spn_vec3 spn_vec3_lerp(spn_vec3 term1, spn_vec3 term2, SPN_FPT t) {
    return (spn_vec3) {
        term1.x + (term2.x - term1.x) * t,
        term1.y + (term2.y - term1.y) * t,
        term1.z + (term2.z - term1.z) * t,
    };
}

void spn_vec3_lerp_ip(spn_vec3 *term1, spn_vec3 term2, SPN_FPT t) {
    term1->x += (term2.x - term1->x) * t;
    term1->y += (term2.y - term1->y) * t;
    term1->z += (term2.z - term1->z) * t;
}

spn_vec3 spn_vec3_mov(spn_vec3 term1, spn_vec3 term2, SPN_FPT disp) {
    SPN_FPT t = disp / spn_vec3_dist(term1, term2);
    return spn_vec3_lerp(term1, term2, t);
}

void spn_vec3_mov_ip(spn_vec3 *term1, spn_vec3 term2, SPN_FPT disp) {
    SPN_FPT t = disp / spn_vec3_dist(*term1, term2);
    spn_vec3_lerp_ip(term1, term2, t);
}

spn_vec3 spn_vec3_rot_x(spn_vec3 vec, SPN_FPT angle) {
    SPN_FPT cosine = spn_cos(angle);
    SPN_FPT sine = spn_sin(angle);
    return (spn_vec3) {
        vec.x, vec.y * cosine - vec.z * sine, vec.y * sine + vec.z * cosine,
    };
}

void spn_vec3_rot_x_ip(spn_vec3 *vec, SPN_FPT angle) {
    SPN_FPT cosine = spn_cos(angle);
    SPN_FPT sine = spn_sin(angle);
    SPN_FPT y = vec->y;
    SPN_FPT z = vec->z;
    vec->y = y * cosine - z * sine;
    vec->z = y * sine + z * cosine;
}

spn_vec3 spn_vec3_rot_x_deg(spn_vec3 vec, SPN_FPT angle) {
    return spn_vec3_rot_x(vec, spn_d2r(angle));
}

void spn_vec3_rot_x_deg_ip(spn_vec3 *vec, SPN_FPT angle) {
    spn_vec3_rot_x_ip(vec, spn_d2r(angle));
}

spn_vec3 spn_vec3_rot_y(spn_vec3 vec, SPN_FPT angle) {
    SPN_FPT cosine = spn_cos(angle);
    SPN_FPT sine = spn_sin(angle);
    return (spn_vec3) {
        vec.x * cosine + vec.z * sine, vec.y, -vec.x * sine + vec.z * cosine,
    };
}

void spn_vec3_rot_y_ip(spn_vec3 *vec, SPN_FPT angle) {
    SPN_FPT cosine = spn_cos(angle);
    SPN_FPT sine = spn_sin(angle);
    SPN_FPT x = vec->x;
    SPN_FPT z = vec->z;
    vec->x = x * cosine + z * sine;
    vec->z = -x * sine + z * cosine;
}

spn_vec3 spn_vec3_rot_y_deg(spn_vec3 vec, SPN_FPT angle) {
    return spn_vec3_rot_y(vec, spn_d2r(angle));
}

void spn_vec3_rot_y_deg_ip(spn_vec3 *vec, SPN_FPT angle) {
    spn_vec3_rot_y_ip(vec, spn_d2r(angle));
}

spn_vec3 spn_vec3_rot_z(spn_vec3 vec, SPN_FPT angle) {
    SPN_FPT cosine = spn_cos(angle);
    SPN_FPT sine = spn_sin(angle);
    return (spn_vec3) {
        vec.x * cosine - vec.y * sine, vec.x * sine + vec.y * cosine, vec.z,
    };
}

void spn_vec3_rot_z_ip(spn_vec3 *vec, SPN_FPT angle) {
    SPN_FPT cosine = spn_cos(angle);
    SPN_FPT sine = spn_sin(angle);
    SPN_FPT x = vec->x;
    SPN_FPT y = vec->y;
    vec->x = x * cosine - y * sine;
    vec->y = x * sine + y * cosine;
}

spn_vec3 spn_vec3_rot_z_deg(spn_vec3 vec, SPN_FPT angle) {
    return spn_vec3_rot_z(vec, spn_d2r(angle));
}

void spn_vec3_rot_z_deg_ip(spn_vec3 *vec, SPN_FPT angle) {
    spn_vec3_rot_z_ip(vec, spn_d2r(angle));
}

spn_vec3 spn_vec3_cross(spn_vec3 term1, spn_vec3 term2) {
    return (spn_vec3) {
        term1.y * term2.z - term1.z * term2.y,
        term1.z * term2.x - term1.x * term2.z,
        term1.x * term2.y - term1.y * term2.x,
    };
}

void spn_vec3_cross_dest(spn_vec3 term1, spn_vec3 term2, spn_vec3 *dest) {
    dest->x = term1.y * term2.z - term1.z * term2.y;
    dest->y = term1.z * term2.x - term1.x * term2.z;
    dest->z = term1.x * term2.y - term1.y * term2.x;
}

SPN_FPT spn_vec3_dot(spn_vec3 term1, spn_vec3 term2) {
    return term1.x * term2.x + term1.y * term2.y + term1.z * term2.z;
}

SPN_FPT spn_vec3_dist(spn_vec3 term1, spn_vec3 term2) {
    return spn_sqrt(spn_vec3_dist_sq(term1, term2));
}

SPN_FPT spn_vec3_dist_sq(spn_vec3 term1, spn_vec3 term2) {
    SPN_FPT x = term2.x - term1.x;
    SPN_FPT y = term2.y - term1.y;
    SPN_FPT z = term2.z - term1.z;
    return x * x + y * y + z * z;
}

SPN_FPT spn_vec3_angle_to(spn_vec3 term1, spn_vec3 term2) {
    return spn_acos(
        spn_vec3_dot(term1, term2)
        / (spn_vec3_mag(term1) * spn_vec3_mag(term2))
    );
}


#endif /* SPN_H_IMPLEMENTATION */
#endif /* INCLUDE_SPN_H */

