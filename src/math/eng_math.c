#include <stddef.h>

#include <math/eng_math.h>

void math_mat4x4__apply_to_vec4(const mat4x4* mat, vec4* vec)
{
	vec4 new_vec = {};

	new_vec.x = mat->x.x * vec->x + mat->x.y * vec->y + mat->x.z * vec->z + mat->x.w * vec->w;
	new_vec.y = mat->y.x * vec->x + mat->y.y * vec->y + mat->y.z * vec->z + mat->y.w * vec->w;
	new_vec.z = mat->z.x * vec->x + mat->z.y * vec->y + mat->z.z * vec->z + mat->z.w * vec->w;
	new_vec.w = mat->w.x * vec->x + mat->w.y * vec->y + mat->w.z * vec->z + mat->w.w * vec->w;

	vec->x = new_vec.x;
	vec->y = new_vec.y;
	vec->z = new_vec.z;
	vec->w = new_vec.w;
}

void math_mat4x4__apply_to_vec4_arr(const mat4x4* mat, vec4* vecs, const size_t vecs_size)
{
	for (size_t i = 0; i < vecs_size; i++) {
		math_mat4x4__apply_to_vec4(mat, &vecs[i]);
	}
}

void math_mat4x4__create_zero(mat4x4* mat)
{
	mat->x.x = 1;
	mat->y.y = 1;
	mat->z.z = 1;
	mat->w.w = 1;
}

mat4x4 math_mat4x4__create_zero_inline(void)
{
	mat4x4 mat;
	math_mat4x4__create_zero(&mat);

	return mat;
}
