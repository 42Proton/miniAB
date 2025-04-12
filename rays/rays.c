/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:56:01 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/12 23:32:19 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>
#include <debug.h>

int	hyper_cap(t_object_entry *obj_entry, t_ray *ray, float t)
{
	t_hyper	*obj;
	t_tuple	hpoint;

	obj = obj_entry->object;
	hpoint = ray_hitpoint(ray, t);
	if (hpoint.y > obj->pos->y + obj->scale->y
		|| hpoint.y < obj->pos->y - obj->scale->y)
		return (1);
	return (0);
}

int	prep_intersections_sphere(t_intersections *res,
	t_object_entry *obj_entry, t_quad_eq *quad_eq)
{
	float	t1;
	float	t2;
	float	disc_sqrt;

	disc_sqrt = sqrt(quad_eq->discriminant);
	t1 = (-quad_eq->b - disc_sqrt)
		/ (2 * quad_eq->a);
	t2 = (-quad_eq->b + disc_sqrt)
		/ (2 * quad_eq->a);
	if (!add_intersection(res, t1, obj_entry))
		return (0);
	if (!add_intersection(res, t2, obj_entry))
		return (0);
	return (1);
}

int	prep_intersections_hyper(t_intersections *res,
	t_object_entry *obj_entry, t_quad_eq *quad_eq, t_ray *ray)
{
	float	t1;
	float	t2;
	float	disc_sqrt;

	disc_sqrt = sqrt(quad_eq->discriminant);
	t1 = (-quad_eq->b - disc_sqrt)
		/ (2 * quad_eq->a);
	t2 = (-quad_eq->b + disc_sqrt)
		/ (2 * quad_eq->a);
	if (!hyper_cap(obj_entry, ray, t1)
		&& !add_intersection(res, t1, obj_entry))
		return (0);
	if (!hyper_cap(obj_entry, ray, t1)
		&& !add_intersection(res, t2, obj_entry))
		return (0);
	return (1);
}

t_quad_eq	sphere_quad_eq(t_ray *ray)
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

t_quad_eq hyper_quad_eq(t_object_entry *obj_entry, t_ray *ray)
{
	t_quad_eq	quad_eq;
	t_tuple 	*dir;
	t_tuple		*o;

	dir = &ray->direction;
	o = &ray->origin;
	quad_eq.a = dir->x * dir->x + dir->z * dir->z - dir->y * dir->y;
    quad_eq.b = 2 * (o->x * dir->x + o->z * dir->z - o->y * dir->y);
    quad_eq.c = o->x * o->x + o->z * o->z - o->y * o->y - 1;
	quad_eq.discriminant = quad_eq.b * quad_eq.b - 4
		* quad_eq.a * quad_eq.c;
    return quad_eq;
}

int	hyper_intersect(t_intersections *insects,
	t_object_entry *obj_entry, t_ray *ray)
{
	t_quad_eq		quad_eq;
	t_hyper			*hyper;
	t_ray			ray_transform;

	hyper = (t_hyper *)obj_entry->object;
	ray_transform = transform_ray(hyper->inv_t, ray);
	quad_eq = hyper_quad_eq(obj_entry, &ray_transform);
	if (quad_eq.discriminant < 0)
		return (1);
	if (!prep_intersections_hyper(insects, obj_entry, &quad_eq, ray))
		return (0);
	return (1);
}

int	sphere_intersect(t_intersections *insects,
	t_object_entry *obj_entry, t_ray *ray)
{
	t_quad_eq		quad_eq;
	t_sphere		*sphere;
	t_ray			ray_transform;

	sphere = (t_sphere *)obj_entry->object;
	ray_transform = transform_ray(sphere->inv_t, ray);
	quad_eq = sphere_quad_eq(&ray_transform);
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
	t_tuple	hit_direction;
	t_tuple	res;

	hit_direction = n_tuplesmult(&ray->direction, t);
	res = n_tupleadd(&ray->origin, &hit_direction);
	return (res);
}
