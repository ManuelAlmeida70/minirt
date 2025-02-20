#include "scene.h"
#include <float.h>

bool    find_closest_hit(t_ray ray, t_scene scene, t_hit *closest_hit)
{
    t_hit   temp_hit;
    bool    hit_found = false;
    double  closest_t = DBL_MAX;

    //Testa intersecao com esferas
    for (int i = 0; i < scene.num_spheres; i++)
    {
        if (intersect_sphere(ray, scene.spheres[i], &temp_hit) && temp_hit.t < closest_t)
        {
            *closest_hit = temp_hit;
            closest_t = temp_hit.t;
            hit_found = true;
        }
    }
    //Testa intersecao com rectangulos
}