#ifndef _eng_math
#define _eng_math

#include <stdlib.h>

#define M_PI 3.14

typedef struct { double x, y, z, w; } vec4;
typedef struct { vec4 x, y, z, w; } mat4x4;

void mat4x4_create_prespective_matrix(const double fov, const double near, const double far, mat4x4* mat);
void mat4x4_create_rotation_matrix(const double theta, const vec4* to, mat4x4* mat);
void mat4x4_create_size_matrix(const vec4* size, mat4x4* mat);
void mat4x4_create_transform_matrix(const vec4* pos, mat4x4* mat);

void math_mat4x4__create_zero(mat4x4* mat);
mat4x4 math_mat4x4__create_zero_inline(void);

void math_mat4x4__apply_to_vec4(const mat4x4* mat, vec4* vec);
void math_mat4x4__apply_to_vec4_arr(const mat4x4* mat, vec4* vecs, const size_t vecs_size);

#endif
