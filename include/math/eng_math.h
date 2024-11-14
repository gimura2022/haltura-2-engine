#ifndef _eng_math
#define _eng_math

#include <stdlib.h>

#define M_PI 3.14

typedef struct { double x, y, z, w; } vec4;
typedef struct { vec4 x, y, z, w; } mat4x4;

void math_vec4__mul(vec4* vec0, const vec4* vec1);
vec4 math_vec4__mul_inline(const vec4* vec);
void math_vec4__muls(vec4* vec, const size_t count, ...);
vec4 math_vec4__muls_inline(const size_t count, ...);

void math_mat4x4__mul(mat4x4* mat0, const mat4x4* mat1);
mat4x4 math_mat4x4__mul_inline(const mat4x4* mat);
void math_mat4x4__muls(mat4x4* mat, const size_t count, ...);
mat4x4 math_mat4x4__muls_inline(const size_t count, ...);

void math_mat4x4__create_zero(mat4x4* mat);
mat4x4 math_mat4x4__create_zero_inline(void);

void math_mat4x4__apply_to_vec4(const mat4x4* mat, vec4* vec);
void math_mat4x4__apply_to_vec4_arr(const mat4x4* mat, vec4* vecs, const size_t vecs_size);

#endif
