#include "eng_math.h"
#include <math.h>

#include <eng_transform.h>

void transform__projection(mat4x4* mat, const double fov, const double near, const double far)
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

void transform__rotation(mat4x4* mat, const double theta, const vec4* to)
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

void transform__size(mat4x4* mat, const vec4* size)
{
	math_mat4x4__create_zero(mat);

	mat->x.x = size->x;
	mat->y.y = size->y;
	mat->z.z = size->z;
	mat->w.w = size->w;
}

void transform__transleate(mat4x4* mat, const vec4* pos)
{
	math_mat4x4__create_zero(mat);

	mat->x.w = pos->x;
	mat->y.w = pos->y;
	mat->z.w = pos->z;
}

mat4x4 transform__projection_inline(const double fov, const double near, const double far)
{
	mat4x4 mat;
	transform__projection(&mat, fov, near, far);

	return mat;
}

mat4x4 transform__rotation_inline(const double theta, const vec4* to)
{
	mat4x4 mat;
	transform__rotation(&mat, theta, to);

	return mat;
}

mat4x4 transform__size_inline(const vec4* size)
{
	mat4x4 mat;
	transform__size(&mat, size);

	return mat;
}

mat4x4 transform__transleate_inline(const vec4* pos)
{
	mat4x4 mat;
	transform__transleate(&mat, pos);

	return mat;
}
