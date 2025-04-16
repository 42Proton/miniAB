/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:35:39 by bismail           #+#    #+#             */
/*   Updated: 2025/04/16 23:56:41 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>
#include <debug.h>

// int     check_cylinder_intersect(t_cylinder *cy, t_ray *ray)
// {

// }

float cylinder_first_part(t_ray *ray)
{
    return (ray->direction.x * ray->direction.x + ray->direction.z * ray->direction.z);
}


float cylinder_middle_part(t_ray *ray)
{
    return 2 * (ray->origin.x * ray->direction.x + ray->origin.z * ray->direction.z);
}

float cylinder_last_part(t_ray *ray, float radius)
{
    return (ray->origin.x * ray->origin.x + ray->origin.z * ray->origin.z - radius * radius);
}

t_quad_eq   check_cylinder_intersect(t_cylinder *cy, t_ray *ray)
{
	t_quad_eq	quad;

	quad.a = cylinder_first_part(ray);
	quad.b = cylinder_middle_part(ray);
	quad.c = cylinder_last_part(ray, (1));
	quad.discriminant = (quad.b * quad.b) - 4 * (quad.a * quad.c);
        return quad;
}
int     check_cap(float t1, float height)
{
        if (t1 < -height / 2 || t1 > height / 2)
                return (0);
        return (1);
}
int	cylinder_intersect(t_intersections *insects, t_object_entry *object, t_ray *ray)
{
        t_cylinder *cylinder;
        t_ray ray_transform;
        t_quad_eq       quad;
        // t_tuple         hit_point;
        float t1;
        float t2;


        if(!insects || !object || !ray)
                return (0);
        cylinder = (t_cylinder *)object->object;
        ray_transform = transform_ray(cylinder->inv_t,ray);
        quad = check_cylinder_intersect(cylinder,&ray_transform);
        if(quad.discriminant < 0)
                return (1);
        if(quad.discriminant == 0)
        {
                t1 = ((-quad.b) + quad.discriminant) / (2 * quad.a);
                if(!check_cap(t1,cylinder->height))
                        return(1);
                if(!add_intersection(insects,t1,object))
                return(0);
        }else
        {
                t1 = ((-quad.b) + quad.discriminant) / (2 * quad.a);
                t2 = ((-quad.b) - quad.discriminant) / (2 * quad.a);
                if(check_cap(t1,cylinder->height))
                        if(!add_intersection(insects,t1,object))
                                return(0);
                if(check_cap(t1,cylinder->height))
                        if(!add_intersection(insects,t2,object))
                                return(0);
        }
        return(1);
}

