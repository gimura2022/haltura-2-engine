#include <math.h>
#include <stddef.h>

#include <eng_math.h>

void mat4x4_create_prespective_matrix(const double fov, const double near, const double far, mat4x4* mat)
{
	math_mat4x4__create_zero(mat);

	const double scale = 1 / tan(fov * 0.5 * M_PI / 180);

	mat->x.x = scale;
	mat->y.y = scale;
	mat->z.z = -far / (far - near);
	mat->w.z = -far * near / (far - near);
	mat->z.w = -1;
	mat->w.w = 0;
}

void mat4x4_create_rotation_matrix(const double theta, const vec4* to, mat4x4* mat)
{
	math_mat4x4__create_zero(mat);

	const double sint = sin(theta);
	const double cost = cos(theta);

	const double x = to->x;
	const double y = to->y;
	const double z = to->z;

	mat->x.x = x * x * (1 - cost) + cost;
	mat->x.y = y * x * (1 - cost) - z * sint;
	mat->x.z = z * x * (1 - cost) + y * sint;
	mat->x.w = 0;

	mat->y.x = x * y * (1 - cost) + z * sint;
	mat->y.y = y * y * (1 - cost) + cost;
	mat->y.z = z * y * (1 - cost) - x * sint;
	mat->y.w = 0;

	mat->z.x = x * z * (1 - cost) - y * sint;
	mat->z.y = y * z * (1 - cost) + x * sint;
	mat->z.z = z * z * (1 - cost) + cost;
	mat->z.w = 0;

	mat->w.w = 1;
}

void mat4x4_create_size_matrix(const vec4* size, mat4x4* mat)
{
	math_mat4x4__create_zero(mat);

	mat->x.x = size->x;
	mat->y.y = size->y;
	mat->z.z = size->z;
	mat->w.w = size->w;
}

void mat4x4_create_transform_matrix(const vec4* pos, mat4x4* mat)
{
	math_mat4x4__create_zero(mat);

	mat->x.w = pos->x;
	mat->y.w = pos->y;
	mat->z.w = pos->z;
}

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
