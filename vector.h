#ifndef VECTOR_H
# define VECTOR_H

#include "minirt.h"

//Funcoes que retornam um novo vetor
t_vector	vector_add(t_vector v1, t_vector v2);
t_vector	vector_subtract(t_vector v1, t_vector v2);
t_vector	vector_scale(t_vector v, double scalar);
t_vector	vector_cross(t_vector v1, t_vector v2);

//Funcoes que retornam um escalar
double	vector_dot(t_vector v1, t_vector v2);
double	vector_length(t_vector v);

//Funcao que modifica diretamente um vetor
void	vector_normalize(t_vector *v);

#endif