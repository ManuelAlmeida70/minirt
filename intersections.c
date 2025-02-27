#include "intersections.h"
#include "ray.h"
#include "vector.h"

//Intersecao com uma esfera(Equacao quadratica)
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
	hit->normal = vector_subtract(hit->point, sphere.center);
	vector_normalize(&hit->normal);
	hit->color = sphere.color;
	return true;
}

//Intersecao com um cilindro (Equacao parametrica)
bool	intersect_cylinder(t_ray ray, t_cylinder cylinder, t_hit *hit)
{
	t_vector	oc = vector_subtract(ray.origin, cylinder.center);
	t_vector	d = cylinder.direction;
	vector_normalize(&d);

	t_vector	v = vector_subtract(ray.direction, vector_scale(d, vector_dot(ray.direction, d)));
	t_vector	w = vector_subtract(oc, vector_scale(d, vector_dot(oc, d)));

	double a = vector_dot(v, v);
	double b = 2.0 * vector_dot(v, w);
	double c = vector_dot(w, w) - (cylinder.radius * cylinder.radius);
	double discriminant = b * b - 4 * a * c;

	if (discriminant < 0)
		return false;
	
	double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
	double t2 = (-b + sqrt(discriminant)) / (2.0 * a);
	double t = (t1 > 0) ? t1 : t2;

	if (t < 0)
		return false;
	
	hit->t = t;
	hit->point = ray_at(ray, t);
	hit->normal = vector_subtract(hit->point, cylinder.center);
	vector_normalize(&hit->normal);
	hit->color = cylinder.color;
	return true;
}

//Intersecao com um rectangulo
bool	intersect_rectangle(t_ray ray, t_rectangle rectangle, t_hit *hit)
{
	double denom = vector_dot(rectangle.normal, ray.direction);

	if (fabs(denom) < 1e-6)
		return false;

	double t = vector_dot(vector_subtract(rectangle.point, ray.origin), rectangle.normal) / denom;

	if (t < 0)
		return false;
	
	hit->t = t;
	hit->point = ray_at(ray, t);
	hit->normal = rectangle.normal;
	hit->color = rectangle.color;
	return true;
}

//Intersecao do raio com um plano
bool	intersect_plane(t_ray ray, t_plane plane, t_hit *hit)
{
	double	denom = vector_dot(plane.normal, ray.direction);

	if (fabs(denom) < 1e-6) //O raio e paralelo ao plano
		return false;
	double	t = vector_dot(vector_subtract(plane.point, ray.origin), plane.normal) / denom;

	hit->t = t;
	hit->point = ray_at(ray, t);
	hit->color = plane.color;
	return true;
}

//Intersecao com cilindro(Equacao parametrica)
bool	intersect_cylinder(t_ray ray, t_cylinder cylinder, t_hit *hit)
{
	t_vector oc = vector_subtract(ray.origin, cylinder.center);
	t_vector d = cylinder.direction;
	vector_normalize(&d);

	t_vector v = vector_subtract(ray.direction, vector_scale(d, vector_dot(ray.direction, d)));
	t_vector w = vector_subtract(oc, vector_scale(d, vector_dot(oc, d)));

	double a =  vector_dot(v, v);
	double b = 2.0 * vector_dot(v, w);
	double c = vector_dot(w, w) - (cylinder.radius * cylinder.radius);
	double discriminant = b * b - 4 * a * c;

	if (discriminant < 0)
		return false;
	
		double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
		double t2 = (-b + sqrt(discriminant)) / (2.0 * a);
		double t = (t1 > 0) ? t1 : t2;

		if (t < 0)
			return false;

		hit->t = t;
		hit->point = ray_at(ray, t);
		hit->normal = vector_subtract(hit->point, cylinder.center);
		vector_normalize(&hit->normal);
		hit->color = cylinder.color;
		return true;
}

bool	intersect_rectangle(t_ray ray, t_rectangle rectangle, t_hit *hit)
{
	double denom = vector_dot(rectangle.normal, ray.direction);

	if (fabs(denom) < 1e-6)
		return false;
	
		double t = vector_dot(vector_subtract(rectangle.point, ray.origin));

		if (t < 0)
			return false;
		
			hit->t = t;
			hit->point = ray_at(ray, t);
			hit->normal = rectangle.normal;
			hit->color = rectangle.color;
			return true;
}