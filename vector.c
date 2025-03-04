#include "vector.h"

t_vector	vector_add(t_vector v1, t_vector v2)
{
	return (t_vector)
	{
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z
	};
}

t_vector	vector_subtract(t_vector v1, t_vector v2)
{
	return (t_vector)
	{
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z
	};
}

t_vector	vector_scale(t_vector v, double scalar)
{
	return (t_vector)
	{
		v.x * scalar,
		v.y * scalar,
		v.z * scalar
	};
}

t_vector	vector_cross(t_vector v1, t_vector v2)
{
	return (t_vector)
	{
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x
	};
}

double		vector_dot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double		vector_length(t_vector v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double		vector_normalize(t_vector *v)
{
	double	length = vector_length(*v);
	if (length == 0)
		return ;
	v->x /= length;
	v->y /= length;
	v->z /= length;
}
