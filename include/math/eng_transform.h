#ifndef _eng_transform_h
#define _eng_transform_h

#include <math/eng_math.h>

void transform__projection(mat4x4* mat, const double fov, const double near, const double far);
void transform__rotation(mat4x4* mat, const double theta, const vec4* to);
void transform__size(mat4x4* mat, const vec4* size);
void transform__transleate(mat4x4* mat, const vec4* pos);

mat4x4 transform__projection_inline(const double fov, const double near, const double far);
mat4x4 transform__rotation_inline(const double theta, const vec4* to);
mat4x4 transform__size_inline(const vec4* size);
mat4x4 transform__transleate_inline(const vec4* pos);

#endif
