#include "intersections.h"
#include "ray.h"
#include "vector.h"

bool	intersect_sphere(t_ray ray, t_sphere sphere, t_hit *hit)
{
	t_vector	oc = vector_subtract(ray.origin, sphere.center);
	double	a = vector_dot(ray.direction, ray.direction);
	double	b = 2.0 * vector_dot(oc, ray.direction);
	double	c = vector_dot(oc, oc) - sphere.radius * sphere.radius;
	double	discriniminant = b * b - 4 * a * c;

	if (discriniminant < 0)
		return false; //Sem intersecao
	double	t1 = (-b - sqrt(discriniminant)) / (2.0 * a);
	double	t2 = (-b + sqrt(discriniminant)) / (2.0 * a);
	double t = (t1 > 0) ? t1 : t2;

	if (t < 0)
		return false; //A esfera esta atras da camera
	
	hit->t = t;
	hit->point = ray_at(ray, t);
}