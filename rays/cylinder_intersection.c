/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:35:39 by bismail           #+#    #+#             */
/*   Updated: 2025/04/20 20:27:45 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>
#include <rays.h>

static t_quad_eq	check_cylinder_intersect(t_cylinder *cy, t_ray *ray)
{
	t_quad_eq	quad;

	quad.a = cylinder_first_part(ray);
	quad.b = cylinder_middle_part(ray);
	quad.c = cylinder_last_part(ray);
	quad.discriminant = (quad.b * quad.b) - 4 * (quad.a * quad.c);
	return (quad);
}

int	cylinder_cap(t_ray *ray, float t1, t_cylinder *obj)
{
	t_tuple	hit_point;

	hit_point = ray_hitpoint(ray, t1);
	if (hit_point.z < -obj->height || hit_point.z > obj->height)
		return (0);
	return (1);
}

static int	prep_cylinder_intersect(t_quad_eq quad, t_ray *ray_transform,
		t_intersections *insects, t_object_entry *object)
{
	float	t1;
	float	t2;
	float	disc_sqrt;

	disc_sqrt = sqrtf(quad.discriminant);
	t1 = (-quad.b + disc_sqrt) / (2 * quad.a);
	t2 = (-quad.b - disc_sqrt) / (2 * quad.a);
	if (cylinder_cap(ray_transform, t1, object->object)
		&& !add_intersection(insects, t1, object))
		return (0);
	if (cylinder_cap(ray_transform, t2, object->object))
		if (!add_intersection(insects, t2, object))
			return (0);
	return (1);
}

int	cylinder_intersect(t_intersections *insects, t_object_entry *object,
		t_ray *ray)
{
	t_cylinder	*cylinder;
	t_ray		ray_transform;
	t_quad_eq	quad;
	int			result;

	if (!insects || !object || !ray)
		return (0);
	cylinder = (t_cylinder *)object->object;
	ray_transform = transform_ray(cylinder->inv_t, ray);
	quad = check_cylinder_intersect(cylinder, &ray_transform);
	if (quad.discriminant >= 0)
	{
		result = prep_cylinder_intersect(quad, &ray_transform, insects, object);
		if (!result)
			return (result);
	}
	disk_intersection(insects, object, ray);
	return (1);
}
