#ifndef _eng_math
#define _eng_math

#include <stdlib.h>

#define M_PI 3.14

typedef struct { double x, y, z, w; } vec4;
typedef struct { vec4 x, y, z, w; } mat4x4;

void math_mat4x4__create_zero(mat4x4* mat);
mat4x4 math_mat4x4__create_zero_inline(void);

void math_mat4x4__apply_to_vec4(const mat4x4* mat, vec4* vec);
void math_mat4x4__apply_to_vec4_arr(const mat4x4* mat, vec4* vecs, const size_t vecs_size);

#endif
