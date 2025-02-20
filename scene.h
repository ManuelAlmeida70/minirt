#ifndef SCENE_H
# define SCENE_H

#include "minirt.h"
#include "intersections.h""

typedef struct s_scene
{
    t_sphere    *spheres;
    int num_spheres;

    t_cylinder  *s_cylinder;
    int num_cylinders;

    t_rectangle *rectangles;
    int num_rectangles;

    t_plane     *planes;
    int num_planes;
}   t_scene;

bool    find_closest_hit(t_ray ray, t_scene secne, t_hit *closest_hit);

#endif