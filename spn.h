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
#include <stddef.h>
#include <stdbool.h>

/* structs */
typedef struct spn_vec2 {
    SPN_FPT x;
    SPN_FPT y;
} spn_vec2;

typedef struct spn_vec3 {
    SPN_FPT x;
    SPN_FPT y;
    SPN_FPT z;
} spn_vec3;

typedef enum spn_obj2_type {
    SPN_OBJ2_NULL,
    SPN_OBJ2_POLY,
    SPN_OBJ2_PILL,
    SPN_OBJ2_ELLIPSE,
} spn_obj2_type;

typedef struct spn_obj2_data_poly {
    spn_vec2 *vertices;
    size_t nvertices;
} spn_obj2_data_poly;

typedef struct spn_obj2_data_pill {
    SPN_FPT radius;
    SPN_FPT length;
} spn_obj2_data_pill;

typedef struct spn_obj2_data_ellipse {
    SPN_FPT width;
    SPN_FPT height;
} spn_obj2_data_ellipse;

typedef union spn_obj2_data {
    spn_obj2_data_poly poly;
    spn_obj2_data_pill pill;
    spn_obj2_data_ellipse ellipse;
} spn_obj2_data;

typedef struct spn_obj2 {
    spn_obj2_type type;
    spn_vec2 pos;
    spn_vec2 vel;
    SPN_FPT rot;
    SPN_FPT rvel;
    spn_obj2_data data; 
} spn_obj2;

typedef enum spn_obj3_type {
    SPN_OBJ3_NULL,
    SPN_OBJ3_POLY,
    SPN_OBJ3_PILL,
} spn_obj3_type;

typedef struct spn_obj3_data_poly {
    spn_vec3 *vertices;
    size_t nvertices;
} spn_obj3_data_poly;

typedef struct spn_obj3_data_pill {
    SPN_FPT radius;
    SPN_FPT length;
} spn_obj3_data_pill;

typedef union spn_obj3_data {
    spn_obj3_data_poly poly;
    spn_obj3_data_pill pill;
} spn_obj3_data;

typedef struct spn_obj3 {
    spn_obj3_type type;
    spn_vec3 pos;
    spn_vec3 vel;
    spn_vec3 rot;
    spn_vec3 rvel;
    spn_obj3_data data; 
} spn_obj3;

/* macro settings */
#ifndef SPN_DEF
#ifdef SPN_STATIC
#define SPN_DEF static
#elif defined(__cplusplus)
#define SPN_DEF extern "C"
#else
#define SPN_DEF extern
#endif
#endif

/* function prototypes */
SPN_DEF bool spn_vec2_iszero(spn_vec2 vec);
SPN_DEF SPN_FPT spn_vec2_mag(spn_vec2 vec);
SPN_DEF SPN_FPT spn_vec2_mag_sq(spn_vec2 vec);
SPN_DEF SPN_FPT spn_vec2_angle(spn_vec2 vec);
SPN_DEF SPN_FPT spn_vec2_angle_deg(spn_vec2 vec);
SPN_DEF spn_vec2 spn_vec2_unit(spn_vec2 vec);
SPN_DEF void spn_vec2_unit_ip(spn_vec2 *vec);
SPN_DEF sspn_vec2 spn_vec2_proj(spn_vec2 term1, spn_vec2 term2);
SPN_DEF void spn_vec2_proj_ip(spn_vec2 *term1, spn_vec2 term2);
SPN_DEF spn_vec2 spn_vec2_add(spn_vec2 addend1, spn_vec2 addend2);
SPN_DEF void spn_vec2_add_ip(spn_vec2 *addend1, spn_vec2 addend2);
SPN_DEF spn_vec2 spn_vec2_sub(spn_vec2 minuend, spn_vec2 subtrahend);
SPN_DEF void spn_vec2_sub_ip(spn_vec2 *minuend, spn_vec2 subtrahend);
SPN_DEF spn_vec2 spn_vec2_mul(spn_vec2 multiplicand, SPN_FPT multiplier);
SPN_DEF void spn_vec2_mul_ip(spn_vec2 *multiplicand, SPN_FPT multiplier);
SPN_DEF spn_vec2 spn_vec2_div(spn_vec2 dividend, SPN_FPT divisor);
SPN_DEF void spn_vec2_div_ip(spn_vec2 *dividend, SPN_FPT divisor);
SPN_DEF spn_vec2 spn_vec2_scale(spn_vec2 vec, SPN_FPT mag);
SPN_DEF void spn_vec2_scale_ip(spn_vec2 *vec, SPN_FPT mag);
SPN_DEF spn_vec2 spn_vec2_lerp(spn_vec2 term1, spn_vec2 term2, SPN_FPT t);
SPN_DEF void spn_vec2_lerp_ip(spn_vec2 *term1, spn_vec2 term2, SPN_FPT t);
SPN_DEF spn_vec2 spn_vec2_mov(spn_vec2 term1, spn_vec2 term2, SPN_FPT disp);
SPN_DEF void spn_vec2_mov_ip(spn_vec2 *term1, spn_vec2 term2, SPN_FPT disp);
SPN_DEF spn_vec2 spn_vec2_rot(spn_vec2 vec, SPN_FPT angle);
SPN_DEF void spn_vec2_rot_ip(spn_vec2 *vec, SPN_FPT angle);
SPN_DEF spn_vec2 spn_vec2_rot_deg(spn_vec2 vec, SPN_FPT angle);
SPN_DEF void spn_vec2_rot_deg_ip(spn_vec2 *vec, SPN_FPT angle);
SPN_DEF SPN_FPT spn_vec2_dot(spn_vec2 term1, spn_vec2 term2);
SPN_DEF SPN_FPT spn_vec2_cross(spn_vec2 term1, spn_vec2 term2);
SPN_DEF SPN_FPT spn_vec2_dist(spn_vec2 term1, spn_vec2 term2);
SPN_DEF SPN_FPT spn_vec2_dist_sq(spn_vec2 term1, spn_vec2 term2);
SPN_DEF SPN_FPT spn_vec2_angle_to(spn_vec2 term1, spn_vec2 term2);

SPN_DEF bool spn_vec3_iszero(spn_vec3 vec);
SPN_DEF SPN_FPT spn_vec3_mag(spn_vec3 vec);
SPN_DEF SPN_FPT spn_vec3_mag_sq(spn_vec3 vec);
SPN_DEF SPN_FPT spn_vec3_angle_x(spn_vec3 vec);
SPN_DEF SPN_FPT spn_vec3_angle_x_deg(spn_vec3 vec);
SPN_DEF SPN_FPT spn_vec3_angle_y(spn_vec3 vec);
SPN_DEF SPN_FPT spn_vec3_angle_y_deg(spn_vec3 vec);
SPN_DEF SPN_FPT spn_vec3_angle_z(spn_vec3 vec);
SPN_DEF SPN_FPT spn_vec3_angle_z_deg(spn_vec3 vec);
SPN_DEF spn_vec3 spn_vec3_unit(spn_vec3 vec);
SPN_DEF void spn_vec3_unit_ip(spn_vec3 *vec);
SPN_DEF spn_vec3 spn_vec3_proj(spn_vec3 term1, spn_vec3 term2);
SPN_DEF void spn_vec3_proj_ip(spn_vec3 *term1, spn_vec3 term2);
SPN_DEF spn_vec3 spn_vec3_add(spn_vec3 addend1, spn_vec3 addend2);
SPN_DEF void spn_vec3_add_ip(spn_vec3 *addend1, spn_vec3 addend2);
SPN_DEF spn_vec3 spn_vec3_sub(spn_vec3 minuend, spn_vec3 subtrahend);
SPN_DEF void spn_vec3_sub_ip(spn_vec3 *minuend, spn_vec3 subtrahend);
SPN_DEF spn_vec3 spn_vec3_mul(spn_vec3 multiplicand, SPN_FPT multiplier);
SPN_DEF void spn_vec3_mul_ip(spn_vec3 *multiplicand, SPN_FPT multiplier);
SPN_DEF spn_vec3 spn_vec3_div(spn_vec3 dividend, SPN_FPT divisor);
SPN_DEF void spn_vec3_div_ip(spn_vec3 *dividend, SPN_FPT divisor);
SPN_DEF spn_vec3 spn_vec3_scale(spn_vec3 vec, SPN_FPT mag);
SPN_DEF void spn_vec3_scale_ip(spn_vec3 *vec, SPN_FPT mag);
SPN_DEF spn_vec3 spn_vec3_lerp(spn_vec3 term1, spn_vec3 term2, SPN_FPT t);
SPN_DEF void spn_vec3_lerp_ip(spn_vec3 *term1, spn_vec3 term2, SPN_FPT t);
SPN_DEF spn_vec3 spn_vec3_mov(spn_vec3 term1, spn_vec3 term2, SPN_FPT disp);
SPN_DEF void spn_vec3_mov_ip(spn_vec3 *term1, spn_vec3 term2, SPN_FPT disp);
SPN_DEF spn_vec3 spn_vec3_rot_x(spn_vec3 vec, SPN_FPT angle);
SPN_DEF void spn_vec3_rot_x_ip(spn_vec3 *vec, SPN_FPT angle);
SPN_DEF spn_vec3 spn_vec3_rot_x_deg(spn_vec3 vec, SPN_FPT angle);
SPN_DEF void spn_vec3_rot_x_deg_ip(spn_vec3 *vec, SPN_FPT angle);
SPN_DEF spn_vec3 spn_vec3_rot_y(spn_vec3 vec, SPN_FPT angle);
SPN_DEF void spn_vec3_rot_y_ip(spn_vec3 *vec, SPN_FPT angle);
SPN_DEF spn_vec3 spn_vec3_rot_y_deg(spn_vec3 vec, SPN_FPT angle);
SPN_DEF void spn_vec3_rot_y_deg_ip(spn_vec3 *vec, SPN_FPT angle);
SPN_DEF spn_vec3 spn_vec3_rot_z(spn_vec3 vec, SPN_FPT angle);
SPN_DEF void spn_vec3_rot_z_ip(spn_vec3 *vec, SPN_FPT angle);
SPN_DEF spn_vec3 spn_vec3_rot_z_deg(spn_vec3 vec, SPN_FPT angle);
SPN_DEF void spn_vec3_rot_z_deg_ip(spn_vec3 *vec, SPN_FPT angle);
SPN_DEF spn_vec3 spn_vec3_cross(spn_vec3 term1, spn_vec3 term2);
SPN_DEF void spn_vec3_cross_dest(spn_vec3 term1, spn_vec3 term2, spn_vec3 *dest);
SPN_DEF SPN_FPT spn_vec3_dot(spn_vec3 term1, spn_vec3 term2);
SPN_DEF SPN_FPT spn_vec3_dist(spn_vec3 term1, spn_vec3 term2);
SPN_DEF SPN_FPT spn_vec3_dist_sq(spn_vec3 term1, spn_vec3 term2);
SPN_DEF SPN_FPT spn_vec3_angle_to(spn_vec3 term1, spn_vec3 term2);

SPN_DEF spn_obj2 spn_obj2_poly_create(size_t nvertices, ...);

#ifdef SPN_H_IMPLEMENTATION


/* includes */
#include <stdlib.h>
#include <stdarg.h>
#include <tgmath.h>

#ifdef SPN_THREADS_H
#include <threads.h>
#endif

/* utility macros needed below */
#define spn_cat(a, b) a##b
#define SPN_IS_FLOAT_float 1
#define spn_type_is_float(x) spn_cat(SPN_IS_FLOAT_, x)

/* macro settings */
#ifndef SPN_EPSILON
#define SPN_EPSILON 0.000001f
#endif
#ifndef SPN_PI
#if spn_is_float(SPN_FPT)
#define SPN_PI 3.14159265358979323846f
#else
#define SPN_PI 3.14159265358979323846
#endif
#endif //
#ifndef spn_libc_name /* e.g. SDL_malloc */
#define spn_libc_name(name) name
#endif

/* libc stuff */
#ifndef spn_malloc
#define spn_malloc(size) spn_libc_name(malloc)(size)
#endif
#ifndef spn_free
#define spn_free(mem) spn_libc_name(free)(mem)
#endif

#ifndef spn_sqrt
#define spn_sqrt(x) spn_libc_name(sqrt)(x)
#endif
#ifndef spn_hypot
#define spn_hypot(x, y) spn_libc_name(hypot)(x, y)
#endif
#ifndef spn_sin
#define spn_sin(x) spn_libc_name(sin)(x)
#endif
#ifndef spn_cos
#define spn_cos(x) spn_libc_name(cos)(x)
#endif
#ifndef spn_acos
#define spn_acos(x) spn_libc_name(acos)(x)
#endif
#ifndef spn_atan2
#define spn_atan2(y, x) spn_libc_name(atan2)(y, x)
#endif

/* property suffixes */
#define spn_nvertices(obj) obj.data.poly.nvertices
#define spn_vertices(obj) obj.data.poly.vertices
#define spn_radius(obj) obj.data.pill.radius
#define spn_length(obj) obj.data.pill.length
#define spn_width(obj) obj.data.ellipse.width
#define spn_height(obj) obj.data.ellipse.height
#define SPN_NVERTICES spn_nvertices()
#define SPN_VERTICES spn_vertices()
#define SPN_RADIUS spn_radius()
#define SPN_LENGTH spn_length()
#define SPN_WIDTH spn_width()
#define SPN_HEIGHT spn_height()

/* other macros */
#define spn_unused(...) (void)(__VA_ARGS__)
#define spn_d2r(x) (x * SPN_PI / 180.0f)
#define spn_r2d(x) (x * 180.0f / SPN_PI)


/* api */
SPN_DEF bool spn_vec2_iszero(spn_vec2 vec) {
    return (
        vec.x < SPN_EPSILON && vec.x > -SPN_EPSILON
        && vec.y < SPN_EPSILON && vec.y > -SPN_EPSILON
    );
}

SPN_DEF SPN_FPT spn_vec2_mag(spn_vec2 vec) {
    return spn_hypot(vec.x, vec.y);
}

SPN_DEF SPN_FPT spn_vec2_mag_sq(spn_vec2 vec) {
    return spn_vec2_dot(vec, vec);
}

SPN_DEF SPN_FPT spn_vec2_angle(spn_vec2 vec) {
    return spn_atan2(vec.y, vec.x);
}

SPN_DEF SPN_FPT spn_vec2_angle_deg(spn_vec2 vec) {
    return spn_r2d(spn_vec2_angle(vec));
}

SPN_DEF spn_vec2 spn_vec2_unit(spn_vec2 vec) {
    SPN_FPT mag = spn_vec2_mag(vec);
    return (spn_vec2) {vec.x / mag, vec.y / mag};
}

SPN_DEF void spn_vec2_unit_ip(spn_vec2 *vec) {
    SPN_FPT mag = spn_vec2_mag(*vec);
    vec->x /= mag;
    vec->y /= mag;
}

SPN_DEF spn_vec2 spn_vec2_proj(spn_vec2 term1, spn_vec2 term2) {
    return spn_vec2_mul(
        term2, spn_vec2_dot(term1, term2) / spn_vec2_dot(term2, term2)
    );
}

SPN_DEF void spn_vec2_proj_ip(spn_vec2 *term1, spn_vec2 term2) {
    SPN_FPT mult = spn_vec2_dot(*term1, term2) / spn_vec2_dot(term2, term2);
    term1->x *= mult;
    term1->y *= mult;
}

SPN_DEF spn_vec2 spn_vec2_add(spn_vec2 addend1, spn_vec2 addend2) {
    return (spn_vec2) {addend1.x + addend2.x, addend1.y + addend2.y};
}

SPN_DEF void spn_vec2_add_ip(spn_vec2 *addend1, spn_vec2 addend2) {
    addend1->x += addend2.x;
    addend1->y += addend2.y;
}

SPN_DEF spn_vec2 spn_vec2_sub(spn_vec2 minuend, spn_vec2 subtrahend) {
    return (spn_vec2) {minuend.x - subtrahend.x, minuend.y - subtrahend.y};
}

SPN_DEF void spn_vec2_sub_ip(spn_vec2 *minuend, spn_vec2 subtrahend) {
    minuend->x -= subtrahend.x;
    minuend->y -= subtrahend.y;
}

SPN_DEF spn_vec2 spn_vec2_mul(spn_vec2 multiplicand, SPN_FPT multiplier) {
    return (spn_vec2) {
        multiplicand.x * multiplier, multiplicand.y * multiplier
    };
}

SPN_DEF void spn_vec2_mul_ip(spn_vec2 *multiplicand, SPN_FPT multiplier) {
    multiplicand->x *= multiplier;
    multiplicand->y *= multiplier;
}

SPN_DEF spn_vec2 spn_vec2_div(spn_vec2 dividend, SPN_FPT divisor) {
    return (spn_vec2) {dividend.x / divisor, dividend.y / divisor};
}

SPN_DEF void spn_vec2_div_ip(spn_vec2 *dividend, SPN_FPT divisor) {
    dividend->x /= divisor;
    dividend->y /= divisor;
}

SPN_DEF spn_vec2 spn_vec2_scale(spn_vec2 vec, SPN_FPT mag) {
    SPN_FPT mult = mag / spn_vec2_mag(vec);
    return (spn_vec2) {vec.x * mult, vec.y * mult};
}

SPN_DEF void spn_vec2_scale_ip(spn_vec2 *vec, SPN_FPT mag) {
    SPN_FPT mult = mag / spn_vec2_mag(*vec);
    vec->x *= mult;
    vec->y *= mult;
}

SPN_DEF spn_vec2 spn_vec2_lerp(spn_vec2 term1, spn_vec2 term2, SPN_FPT t) {
    return (spn_vec2) {
        term1.x + (term2.x - term1.x) * t,
        term1.y + (term2.y - term1.y) * t,
    };
}

SPN_DEF void spn_vec2_lerp_ip(spn_vec2 *term1, spn_vec2 term2, SPN_FPT t) {
    term1->x += (term2.x - term1->x) * t;
    term1->y += (term2.y - term1->y) * t;
}

SPN_DEF spn_vec2 spn_vec2_mov(spn_vec2 term1, spn_vec2 term2, SPN_FPT disp) {
    SPN_FPT t = disp / spn_vec2_dist(term1, term2);
    return spn_vec2_lerp(term1, term2, t);
}

SPN_DEF void spn_vec2_mov_ip(spn_vec2 *term1, spn_vec2 term2, SPN_FPT disp) {
    SPN_FPT t = disp / spn_vec2_dist(*term1, term2);
    spn_vec2_lerp_ip(term1, term2, t);
}

SPN_DEF spn_vec2 spn_vec2_rot(spn_vec2 vec, SPN_FPT angle) {
    SPN_FPT cosine = spn_cos(angle);
    SPN_FPT sine = spn_sin(angle);
    return (spn_vec2) {
        vec.x * cosine - vec.y * sine,
        vec.x * sine + vec.y * cosine,
    };
}

SPN_DEF void spn_vec2_rot_ip(spn_vec2 *vec, SPN_FPT angle) {
    SPN_FPT cosine = spn_cos(angle);
    SPN_FPT sine = spn_sin(angle);
    SPN_FPT x = vec->x;
    SPN_FPT y = vec->y;
    vec->x = x * cosine - y * sine;
    vec->y = x * sine + y * cosine;
}

SPN_DEF spn_vec2 spn_vec2_rot_deg(spn_vec2 vec, SPN_FPT angle) {
    return spn_vec2_rot(vec, spn_d2r(angle));
}

SPN_DEF void spn_vec2_rot_deg_ip(spn_vec2 *vec, SPN_FPT angle) {
    spn_vec2_rot_ip(vec, spn_d2r(angle));
}

SPN_DEF SPN_FPT spn_vec2_dot(spn_vec2 term1, spn_vec2 term2) {
    return term1.x * term2.x + term1.y * term2.y;
}

SPN_DEF SPN_FPT spn_vec2_cross(spn_vec2 term1, spn_vec2 term2) {
    return term1.x * term2.y - term1.y * term2.x;
}

SPN_DEF SPN_FPT spn_vec2_dist(spn_vec2 term1, spn_vec2 term2) {
    return spn_hypot(term2.x - term1.x, term2.y - term1.y);
}

SPN_DEF SPN_FPT spn_vec2_dist_sq(spn_vec2 term1, spn_vec2 term2) {
    SPN_FPT x = term2.x - term1.x;
    SPN_FPT y = term2.y - term1.y;
    return x * x + y * y;
}

SPN_DEF SPN_FPT spn_vec2_angle_to(spn_vec2 term1, spn_vec2 term2) {
    return spn_acos(
        spn_vec2_dot(term1, term2)
        / (spn_vec2_mag(term1) * spn_vec2_mag(term2))
    );
}


SPN_DEF bool spn_vec3_iszero(spn_vec3 vec) {
    return (
        vec.x < SPN_EPSILON && vec.x > -SPN_EPSILON
        && vec.y < SPN_EPSILON && vec.y > -SPN_EPSILON
        && vec.z < SPN_EPSILON && vec.z > -SPN_EPSILON
    );
}

SPN_DEF SPN_FPT spn_vec3_mag(spn_vec3 vec) {
    return spn_sqrt(spn_vec3_mag_sq(vec));
}

SPN_DEF SPN_FPT spn_vec3_mag_sq(spn_vec3 vec) {
    return spn_vec3_dot(vec, vec);
}

SPN_DEF SPN_FPT spn_vec3_angle_x(spn_vec3 vec) {
    return spn_atan2(vec.y, vec.z);
}

SPN_DEF SPN_FPT spn_vec3_angle_x_deg(spn_vec3 vec) {
    return spn_r2d(spn_vec3_angle_x(vec));
}

SPN_DEF SPN_FPT spn_vec3_angle_y(spn_vec3 vec) {
    return spn_atan2(vec.z, vec.x);
}

SPN_DEF SPN_FPT spn_vec3_angle_y_deg(spn_vec3 vec) {
    return spn_r2d(spn_vec3_angle_y(vec));
}

SPN_DEF SPN_FPT spn_vec3_angle_z(spn_vec3 vec) {
    return spn_atan2(vec.y, vec.x);
}

SPN_DEF SPN_FPT spn_vec3_angle_z_deg(spn_vec3 vec) {
    return spn_r2d(spn_vec3_angle_z(vec));
}

SPN_DEF spn_vec3 spn_vec3_unit(spn_vec3 vec) {
    SPN_FPT mag = spn_vec3_mag(vec);
    return (spn_vec3) {vec.x / mag, vec.y / mag, vec.z / mag};
}

SPN_DEF void spn_vec3_unit_ip(spn_vec3 *vec) {
    SPN_FPT mag = spn_vec3_mag(*vec);
    vec->x /= mag;
    vec->y /= mag;
    vec->z /= mag;
}

SPN_DEF spn_vec3 spn_vec3_proj(spn_vec3 term1, spn_vec3 term2) {
    return spn_vec3_mul(
        term2, spn_vec3_dot(term1, term2) / spn_vec3_dot(term2, term2)
    );
}

SPN_DEF void spn_vec3_proj_ip(spn_vec3 *term1, spn_vec3 term2) {
    SPN_FPT mult = spn_vec3_dot(*term1, term2) / spn_vec3_dot(term2, term2);
    term1->x *= mult;
    term1->y *= mult;
    term1->z *= mult;
}

SPN_DEF spn_vec3 spn_vec3_add(spn_vec3 addend1, spn_vec3 addend2) {
    return (spn_vec3) {
        addend1.x + addend2.x, addend1.y + addend2.y, addend1.z + addend2.z,
    };
}

SPN_DEF void spn_vec3_add_ip(spn_vec3 *addend1, spn_vec3 addend2) {
    addend1->x += addend2.x;
    addend1->y += addend2.y;
    addend1->z += addend2.z;
}

SPN_DEF spn_vec3 spn_vec3_sub(spn_vec3 minuend, spn_vec3 subtrahend) {
    return (spn_vec3) {
        minuend.x - subtrahend.x,
        minuend.y - subtrahend.y,
        minuend.z - subtrahend.z,
    };
}

SPN_DEF void spn_vec3_sub_ip(spn_vec3 *minuend, spn_vec3 subtrahend) {
    minuend->x -= subtrahend.x;
    minuend->y -= subtrahend.y;
    minuend->z -= subtrahend.z;
}

SPN_DEF spn_vec3 spn_vec3_mul(spn_vec3 multiplicand, SPN_FPT multiplier) {
    return (spn_vec3) {
        multiplicand.x * multiplier,
        multiplicand.y * multiplier,
        multiplicand.z * multiplier,
    };
}

SPN_DEF void spn_vec3_mul_ip(spn_vec3 *multiplicand, SPN_FPT multiplier) {
    multiplicand->x *= multiplier;
    multiplicand->y *= multiplier;
    multiplicand->z *= multiplier;
}

SPN_DEF spn_vec3 spn_vec3_div(spn_vec3 dividend, SPN_FPT divisor) {
    return (spn_vec3) {
        dividend.x / divisor, dividend.y / divisor, dividend.z / divisor,
    };
}

SPN_DEF void spn_vec3_div_ip(spn_vec3 *dividend, SPN_FPT divisor) {
    dividend->x /= divisor;
    dividend->y /= divisor;
    dividend->z /= divisor;
}

SPN_DEF spn_vec3 spn_vec3_scale(spn_vec3 vec, SPN_FPT mag) {
    SPN_FPT mult = mag / spn_vec3_mag(vec);
    return (spn_vec3) {vec.x * mult, vec.y * mult, vec.z * mult};
}

SPN_DEF void spn_vec3_scale_ip(spn_vec3 *vec, SPN_FPT mag) {
    SPN_FPT mult = mag / spn_vec3_mag(*vec);
    vec->x *= mult;
    vec->y *= mult;
    vec->z *= mult;
}

SPN_DEF spn_vec3 spn_vec3_lerp(spn_vec3 term1, spn_vec3 term2, SPN_FPT t) {
    return (spn_vec3) {
        term1.x + (term2.x - term1.x) * t,
        term1.y + (term2.y - term1.y) * t,
        term1.z + (term2.z - term1.z) * t,
    };
}

SPN_DEF void spn_vec3_lerp_ip(spn_vec3 *term1, spn_vec3 term2, SPN_FPT t) {
    term1->x += (term2.x - term1->x) * t;
    term1->y += (term2.y - term1->y) * t;
    term1->z += (term2.z - term1->z) * t;
}

SPN_DEF spn_vec3 spn_vec3_mov(spn_vec3 term1, spn_vec3 term2, SPN_FPT disp) {
    SPN_FPT t = disp / spn_vec3_dist(term1, term2);
    return spn_vec3_lerp(term1, term2, t);
}

SPN_DEF void spn_vec3_mov_ip(spn_vec3 *term1, spn_vec3 term2, SPN_FPT disp) {
    SPN_FPT t = disp / spn_vec3_dist(*term1, term2);
    spn_vec3_lerp_ip(term1, term2, t);
}

SPN_DEF spn_vec3 spn_vec3_rot_x(spn_vec3 vec, SPN_FPT angle) {
    SPN_FPT cosine = spn_cos(angle);
    SPN_FPT sine = spn_sin(angle);
    return (spn_vec3) {
        vec.x, vec.y * cosine - vec.z * sine, vec.y * sine + vec.z * cosine,
    };
}

SPN_DEF void spn_vec3_rot_x_ip(spn_vec3 *vec, SPN_FPT angle) {
    SPN_FPT cosine = spn_cos(angle);
    SPN_FPT sine = spn_sin(angle);
    SPN_FPT y = vec->y;
    SPN_FPT z = vec->z;
    vec->y = y * cosine - z * sine;
    vec->z = y * sine + z * cosine;
}

SPN_DEF spn_vec3 spn_vec3_rot_x_deg(spn_vec3 vec, SPN_FPT angle) {
    return spn_vec3_rot_x(vec, spn_d2r(angle));
}

SPN_DEF void spn_vec3_rot_x_deg_ip(spn_vec3 *vec, SPN_FPT angle) {
    spn_vec3_rot_x_ip(vec, spn_d2r(angle));
}

SPN_DEF spn_vec3 spn_vec3_rot_y(spn_vec3 vec, SPN_FPT angle) {
    SPN_FPT cosine = spn_cos(angle);
    SPN_FPT sine = spn_sin(angle);
    return (spn_vec3) {
        vec.x * cosine + vec.z * sine, vec.y, -vec.x * sine + vec.z * cosine,
    };
}

SPN_DEF void spn_vec3_rot_y_ip(spn_vec3 *vec, SPN_FPT angle) {
    SPN_FPT cosine = spn_cos(angle);
    SPN_FPT sine = spn_sin(angle);
    SPN_FPT x = vec->x;
    SPN_FPT z = vec->z;
    vec->x = x * cosine + z * sine;
    vec->z = -x * sine + z * cosine;
}

SPN_DEF spn_vec3 spn_vec3_rot_y_deg(spn_vec3 vec, SPN_FPT angle) {
    return spn_vec3_rot_y(vec, spn_d2r(angle));
}

SPN_DEF void spn_vec3_rot_y_deg_ip(spn_vec3 *vec, SPN_FPT angle) {
    spn_vec3_rot_y_ip(vec, spn_d2r(angle));
}

SPN_DEF spn_vec3 spn_vec3_rot_z(spn_vec3 vec, SPN_FPT angle) {
    SPN_FPT cosine = spn_cos(angle);
    SPN_FPT sine = spn_sin(angle);
    return (spn_vec3) {
        vec.x * cosine - vec.y * sine, vec.x * sine + vec.y * cosine, vec.z,
    };
}

SPN_DEF void spn_vec3_rot_z_ip(spn_vec3 *vec, SPN_FPT angle) {
    SPN_FPT cosine = spn_cos(angle);
    SPN_FPT sine = spn_sin(angle);
    SPN_FPT x = vec->x;
    SPN_FPT y = vec->y;
    vec->x = x * cosine - y * sine;
    vec->y = x * sine + y * cosine;
}

SPN_DEF spn_vec3 spn_vec3_rot_z_deg(spn_vec3 vec, SPN_FPT angle) {
    return spn_vec3_rot_z(vec, spn_d2r(angle));
}

SPN_DEF void spn_vec3_rot_z_deg_ip(spn_vec3 *vec, SPN_FPT angle) {
    spn_vec3_rot_z_ip(vec, spn_d2r(angle));
}

SPN_DEF spn_vec3 spn_vec3_cross(spn_vec3 term1, spn_vec3 term2) {
    return (spn_vec3) {
        term1.y * term2.z - term1.z * term2.y,
        term1.z * term2.x - term1.x * term2.z,
        term1.x * term2.y - term1.y * term2.x,
    };
}

SPN_DEF void spn_vec3_cross_dest(spn_vec3 term1, spn_vec3 term2, spn_vec3 *dest) {
    dest->x = term1.y * term2.z - term1.z * term2.y;
    dest->y = term1.z * term2.x - term1.x * term2.z;
    dest->z = term1.x * term2.y - term1.y * term2.x;
}

SPN_DEF SPN_FPT spn_vec3_dot(spn_vec3 term1, spn_vec3 term2) {
    return term1.x * term2.x + term1.y * term2.y + term1.z * term2.z;
}

SPN_DEF SPN_FPT spn_vec3_dist(spn_vec3 term1, spn_vec3 term2) {
    return spn_sqrt(spn_vec3_dist_sq(term1, term2));
}

SPN_DEF SPN_FPT spn_vec3_dist_sq(spn_vec3 term1, spn_vec3 term2) {
    SPN_FPT x = term2.x - term1.x;
    SPN_FPT y = term2.y - term1.y;
    SPN_FPT z = term2.z - term1.z;
    return x * x + y * y + z * z;
}

SPN_DEF SPN_FPT spn_vec3_angle_to(spn_vec3 term1, spn_vec3 term2) {
    return spn_acos(
        spn_vec3_dot(term1, term2)
        / (spn_vec3_mag(term1) * spn_vec3_mag(term2))
    );
}


#define spn_obj2_null (spn_obj2) { .type = SPN_OBJ2_NULL }
#define spn_obj2_poly(nvertices, vertices) \
    (spn_obj2) { \
        .type = SPN_OBJ2_POLY,      \
        .data = { .poly = {         \
            .nvertices = nvertices, \
            .vertices = vertices,   \
        } },                        \
    }
#define spn_obj2_pill(radius, length) \
    (spn_obj2) { \
        .type = SPN_OBJ2_PILL, \
        .data = { .pill = {    \
            .radius = radius,  \
            .length = length,  \
        } },                   \
    }
#define spn_obj2_ellipse(width, height) \
    (spn_obj2) { \
        .type = SPN_OBJ2_ELLIPSE, \
        .data = { .ellipse = {    \
            .width = width,       \
            .height = height,     \
        } },                      \
    }

SPN_DEF spn_obj2 spn_obj2_poly_create(size_t nvertices, ...) {
    spn_vec2 *vertices = spn_malloc(sizeof(spn_vec2) * nvertices);
    if (vertices == NULL) { return spn_obj2_null; }

    va_list args;
    va_start(args, nvertices);
    for (size_t i = 0; i < nvertices; i++) {
        vertices[i] = va_arg(args, spn_vec2);
    }

    return spn_obj2_poly(nvertices, vertices);
}


#endif /* SPN_H_IMPLEMENTATION */
#endif /* INCLUDE_SPN_H */

