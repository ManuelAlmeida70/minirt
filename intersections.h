#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include <stdbool.h>
# include "minirt.h"

typedef struct s_hit
{
	double	t;
	t_vector	point;
	t_vector	normal;
	int	color;
}	t_hit;

//Calcula a intersecao do raio com uma esfera
bool	intersect_sphere(t_ray ray, t_sphere, t_hit *hit);

#endif