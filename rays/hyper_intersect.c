/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyper_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:47:02 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/15 22:56:29 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	hyper_cap(t_object_entry *obj_entry, t_ray *ray, float t)
{
	t_hyper	*obj;
	t_tuple	hpoint;

	obj = obj_entry->object;
	hpoint = ray_hitpoint(ray, t);
	if (hpoint.z > obj->scale->z
		|| hpoint.z < -obj->scale->z)
		return (1);
	return (0);
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
	if (!hyper_cap(obj_entry, ray, t2)
		&& !add_intersection(res, t2, obj_entry))
		return (0);
	return (1);
}

t_quad_eq	hyper_quad_eq(t_object_entry *obj_entry, t_ray *ray)
{
	t_quad_eq	quad_eq;
	t_tuple		*dir;
	t_tuple		*o;
	t_tuple		*coeffs;

	dir = &ray->direction;
	o = &ray->origin;
	coeffs = &((t_hyper *)obj_entry->object)->coeffs2;
	quad_eq.a = (dir->x * dir->x) / coeffs->x + (dir->y
			* dir->y) / coeffs->y - (dir->z * dir->z) / coeffs->z;
	quad_eq.b = 2 * ((o->x * dir->x) / coeffs->x + (o->y
				* dir->y) / coeffs->y - (o->z * dir->z) / coeffs->z);
	quad_eq.c = (o->x * o->x) / coeffs->x + (o->y
			* o->y) / coeffs->y - (o->z * o->z) / coeffs->z - 1;
	quad_eq.discriminant = quad_eq.b * quad_eq.b - 4
		* quad_eq.a * quad_eq.c;
	return (quad_eq);
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
	if (!prep_intersections_hyper(insects, obj_entry, &quad_eq, &ray_transform))
		return (0);
	return (1);
}
