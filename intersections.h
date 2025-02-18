#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include <stdbool.h>
# include "minirt.h"

typedef struct s_hit
{
	double	t;
	t_vector	point;
	t_vector	normal;
	t_color		color;
}	t_hit;

//Calcula a intersecao do raio com uma esfera
bool	intersect_sphere(t_ray ray, t_sphere, t_hit *hit);

//Calcula a intersecao do raio com uma cilindro
bool	intersect_cylinder(t_ray ray, t_cylinder cylinder, t_hit *hit);

//Calcula a intersecao do raio com retangulo
bool	intersect_rectangle(t_ray ray, t_rectangle rectangle, t_hit *hit);

//Intersecao do raio com um plano
bool	intersect_plane(t_ray ray, t_plane plane, t_hit *hit);

#endif