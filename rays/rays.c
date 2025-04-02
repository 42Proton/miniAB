/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:56:01 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/01 15:18:47 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>
#include <debug.h>

int	prep_intersections_sphere(t_intersections *res,
	t_object_entry *obj_entry, t_quad_eq *quad_eq)
{
	float	t1;
	float	t2;
	float	disc_sqrt;

	disc_sqrt = sqrt(quad_eq->discriminant);
	t1 = (-quad_eq->b - disc_sqrt)
		/ (2 * quad_eq->a);
	t2 = (-quad_eq->b  + disc_sqrt)
		/ (2 * quad_eq->a);
	if (!add_intersection(res, t1, obj_entry))
		return (0);
	if (!add_intersection(res, t2, obj_entry))
		return (0);
	return (1);
}

t_quad_eq	sphere_quad_eq(t_object_entry *obj_entry, t_ray *ray)
{
	t_tuple		sphere_to_ray;
	t_quad_eq	quad_eq;
	t_tuple		world_origin;

	world_origin = point(0, 0, 0);
	sphere_to_ray = n_tuplesub(&ray->origin, &world_origin);
	quad_eq.a = tupledot(&ray->direction, &ray->direction);
	quad_eq.b = 2 * tupledot(&ray->direction, &sphere_to_ray);
	quad_eq.c = tupledot(&sphere_to_ray, &sphere_to_ray)
		- 1;
	quad_eq.discriminant = quad_eq.b * quad_eq.b - 4
		* quad_eq.a * quad_eq.c;
	return (quad_eq);
}

int	sphere_intersect(t_intersections *insects,
	t_object_entry *obj_entry, t_ray *ray)
{
	t_quad_eq		quad_eq;
	t_sphere		*sphere;
	t_ray			ray_transform;

	sphere = (t_sphere *)obj_entry->object;
	ray_transform = transform_ray(sphere->inv_t, ray);
	quad_eq = sphere_quad_eq(obj_entry, &ray_transform);
	if (quad_eq.discriminant < 0)
		return (1);
	if (!prep_intersections_sphere(insects, obj_entry, &quad_eq))
		return (0);
	return (1);
}

t_ray	init_ray(t_tuple *origin, t_tuple *direction)
{
	t_ray	ray;

	ray.origin = *origin;
	ray.direction = *direction;
	return (ray);
}

t_tuple	ray_hitpoint(t_ray *ray, float t)
{
	t_tuple hit_direction;
	t_tuple	res;

	hit_direction = n_tuplesmult(&ray->direction, t);
	res = n_tupleadd(&ray->origin, &hit_direction);
	return (res);
}
