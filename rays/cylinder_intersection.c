/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:35:39 by bismail           #+#    #+#             */
/*   Updated: 2025/04/16 18:01:18 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>
#include <debug.h>

// int     check_cylinder_intersect(t_cylinder *cy, t_ray *ray)
// {

// }

float           cylinder_first_part(t_ray *ray)
{
        float res_ray;
        t_tuple temp;

        temp = point(0,0,0);
        res_ray = tupledot(&temp, &ray->direction);
        res_ray =  1 - powf(res_ray,2);
        
        return res_ray;
}

float           cylinder_middle_part(t_ray *ray)
{
        float   res;
        t_tuple temp;
        
        temp = point(0,0,0);
        res = 2 * (tupledot(&ray->direction,&ray->origin));
        res -= tupledot(&temp,&ray->direction) * tupledot(&temp , &ray->origin);
        
        return (res);
}
float   cylinder_last_part(t_ray *ray , float   radius)
{
        float res;
        t_tuple temp;

        temp = point(0,0,0);
        res = tupledot(&ray->origin,&ray->origin);
        res -= powf(tupledot(&temp,&ray->origin),2) - powf(radius,2);
        
        return (res);
}
int	cylinder_intersect(t_intersections *insects, t_object_entry *object, t_ray *ray)
{
        t_cylinder *cylinder;
        t_ray ray_transform;
        t_quad_eq quad;
        // float    count;
        float   upper_root;
        float   lower_root;
        if(!insects || !object || !ray)
                return (0);
        cylinder = (t_cylinder *)object->object;
        ray_transform = transform_ray(cylinder->inv_t,ray);
        quad.a = cylinder_first_part(&ray_transform);
        quad.b = cylinder_middle_part(&ray_transform);
        quad.c = cylinder_last_part(&ray_transform,cylinder->dim / 2);
        quad.discriminant = (quad.b * quad.b) + 4 *(quad.a * quad.c);
        printf("a %f b %f c%f disc %f \n",quad.a,quad.b,quad.c , quad.discriminant);
        if(quad.discriminant > EPSILON )
        {
                float b_term = quad.b < EPSILON ? -quad.b + sqrt(quad.discriminant): -quad.b - sqrt(quad.discriminant);
                lower_root = b_term /2 *quad.a;
                upper_root = (2 * quad.c) /b_term;
                if(lower_root > upper_root)
                        {
                                float tmp = lower_root;
                                lower_root = upper_root;
                                upper_root = tmp;
                        }
        } else if (quad.discriminant > -EPSILON && quad.discriminant <= EPSILON )
        {
                lower_root = -(quad.b / 2* quad.a);
                upper_root = lower_root;
                return 1;
        }
        else
        {
                lower_root = NAN;
                upper_root = NAN;
        }
        printf("%f,%f \n",upper_root,lower_root);
        if (!add_intersection(insects, upper_root, object) && !add_intersection(insects,lower_root,object))
                 return (0);
        return(1);
        
}

