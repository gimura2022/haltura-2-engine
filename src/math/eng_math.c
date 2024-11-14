#include <stddef.h>
#include <stdarg.h>

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

void math_vec4__mul(vec4* vec0, const vec4* vec1)
{
	vec0->x *= vec1->x;
	vec0->y *= vec1->y;
	vec0->z *= vec1->z;
	vec0->w *= vec1->w;
}

vec4 math_vec4__mul_inline(const vec4* vec)
{
	vec4 out;
	math_vec4__mul(&out, vec);

	return out;
}

static void math_vec4__muls_va_list(vec4* vec, const size_t count, va_list args);

void math_vec4__muls(vec4* vec, const size_t count, ...)
{
	va_list args;
	va_start(args, count);

	math_vec4__muls_va_list(vec, count, args);

	va_end(args);
}

vec4 math_vec4__muls_inline(const size_t count, ...)
{
	va_list args;
	va_start(args, count);

	vec4 out;
	math_vec4__muls_va_list(&out, count, args);

	va_end(args);

	return out;
}

void math_mat4x4__mul(mat4x4* mat0, const mat4x4* mat1)
{
	math_vec4__mul(&mat0->x, &mat1->x);
	math_vec4__mul(&mat0->y, &mat1->y);
	math_vec4__mul(&mat0->z, &mat1->z);
	math_vec4__mul(&mat0->w, &mat1->w);
}

mat4x4 math_mat4x4__mul_inline(const mat4x4* mat)
{
	mat4x4 out;
	math_mat4x4__mul(&out, mat);

	return out;
}

static void math_mat4x4__muls_va_list(mat4x4* mat, const size_t count, va_list args);

void math_mat4x4__muls(mat4x4* mat, const size_t count, ...)
{
	va_list args;
	va_start(args, count);

	math_mat4x4__muls_va_list(mat, count, args);

	va_end(args);
}

mat4x4 math_mat4x4__muls_inline(const size_t count, ...)
{
	va_list args;
	va_start(args, count);

	mat4x4 mat;
	math_mat4x4__muls_va_list(&mat, count, args);

	va_end(args);

	return mat;
}

static void math_vec4__muls_va_list(vec4* vec, const size_t count, va_list args)
{
	for (size_t i = 0; i < count; i++) {
		math_vec4__mul(vec, va_arg(args, vec4*));
	}
}

static void math_mat4x4__muls_va_list(mat4x4* mat, const size_t count, va_list args)
{
	for (size_t i = 0; i < count; i++) {
		math_mat4x4__mul(mat, va_arg(args, vec4*));
	}
}
