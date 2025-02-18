#ifndef RAY_H
# define RAY_H

# include "minirt.h"

//Cria um novo raio a partir da origem e direcao
t_ray	ray_create(t_vector origin, t_vector direction);

//Calcula um ponto ao longo do raio em um determinado
t_vector	ray_at(t_ray ray, double t);

#endif