#include "ray.h"
#include "vector.h"

t_ray	ray_create(t_vector origin, t_vector direction)
{
	vector_normalize(&direction);
	return (t_ray)
	{
		origin, direction
	};
}

t_vector	ray_at(t_ray ray, double t)
{
	return 
		vector_add(ray.origin, vector_scale(ray.direction, t));
}
