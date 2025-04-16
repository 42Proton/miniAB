/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:35:39 by bismail           #+#    #+#             */
/*   Updated: 2025/04/16 22:45:37 by bismail          ###   ########.fr       */
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

float   check_cylinder_intersect(t_cylinder *cy, t_ray *ray)
{
	t_quad_eq	quad;
	float		upper_root;
	float		lower_root;

	quad.a = cylinder_first_part(ray);
	quad.b = cylinder_middle_part(ray);
	quad.c = cylinder_last_part(ray, (cy->dim / 2));
	quad.discriminant = (quad.b * quad.b) - 4 * (quad.a * quad.c);
	if (quad.discriminant < 0)
		return (-1);
        else if (quad.discriminant == 0)
        {
                return(-(quad.b)/ (2 *quad.a));
        }
        else if (quad.discriminant > 0)
        {
                upper_root = ((-quad.b) + sqrt(quad.discriminant)) / (2 *quad.a);
                lower_root= ((-quad.b) - sqrt(quad.discriminant)) / (2 *quad.a);
                if(upper_root > 0)
                        return(upper_root);
                else if (upper_root < 0 && lower_root > 0)
                        return(lower_root);
                else
                        return(-1);
        }
	return (-1);
}
int	cylinder_intersect(t_intersections *insects, t_object_entry *object, t_ray *ray)
{
        t_cylinder *cylinder;
        t_ray ray_transform;
        float   res;
        t_tuple         hit_point;

        if(!insects || !object || !ray)
                return (0);
        cylinder = (t_cylinder *)object->object;
        ray_transform = transform_ray(cylinder->inv_t,ray);
        res = check_cylinder_intersect(cylinder,&ray_transform);
        printf("res = %f \n", res);
        if(res == -1)
                return (1);
        tuplesmult(&ray_transform.direction, res);
        hit_point = n_tupleadd(&ray_transform.origin,&ray_transform.direction );
        if(hit_point.y < cylinder->height /2.0f || hit_point.y > cylinder->height / 2.0f)
                return (1);
        if(!add_intersection(insects,res,object))
                return(0);
        return(1);
}

