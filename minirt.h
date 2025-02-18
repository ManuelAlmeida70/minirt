#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct	s_camera
{
	t_vector	position;
	t_vector	direction;
	double		fov;
}	t_camera;

typedef struct s_ambient_light
{
	double	intesnity;
	t_color	color;
}	t_ambient_light;

typedef	struct s_light
{
	t_vector	position;
	double	intensity;
	t_color	color;
	struct	s_light *next;
}	t_light;

typedef struct	s_sphere
{
	t_vector	center;
	double	radius;
	t_color	color;
	struct s_phere	*next;
}	t_sphere;

typedef struct s_rectangle
{
	t_vector	point;
	t_vector	normal;
	t_color		color;
	struct s_rectangle *next;
} t_rectangle;

typedef struct s_cylinder
{
	t_vector	center;
	t_vector	direction;
	double	radius;
	double	height;
	t_color	color;
	struct s_cylinder *next;
} t_cylinder;



typedef struct	s_ray
{
	t_vector	origin;
	t_vector	direction;
}	t_ray;

typedef struct	s_scena
{
	t_camera	camera;
	t_ambient_light	ambiente;
	t_light		*lights;
	t_sphere	*spheres;
	t_rectangle		*rectangles;
	t_cylinder	*cylinders;
}	t_scene;

typedef	struct s_plane
{
	t_vector	point;
	t_vector	normal;
	t_color		color;
}	t_plane;

#endif