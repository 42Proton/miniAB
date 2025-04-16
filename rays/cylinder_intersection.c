/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:35:39 by bismail           #+#    #+#             */
/*   Updated: 2025/04/17 00:49:27 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>
#include <rays.h>

t_quad_eq	check_cylinder_intersect(t_cylinder *cy, t_ray *ray)
{
	t_quad_eq	quad;

	quad.a = cylinder_first_part(ray);
	quad.b = cylinder_middle_part(ray);
	quad.c = cylinder_last_part(ray, (1));
	quad.discriminant = (quad.b * quad.b) - 4 * (quad.a * quad.c);
	return (quad);
}

int	check_cap(t_ray ray, float t1, float height)
{
	t_tuple	hit_point;

	hit_point = ray_hitpoint(&ray, t1);
	if (hit_point.y < -height / 2 || hit_point.y > height / 2)
		return (0);
	return (1);
}

int	prep_cylinder_intersect(t_quad_eq quad, t_ray *ray_transform,
		t_intersections *insects, t_object_entry *object)
{
	float	t1;
	float	t2;

	if (quad.discriminant == 0)
	{
		t1 = cylinder_first_root(quad, ray_transform, object);
		if (t1 == __FLT_MIN__)
			return (-1);
		if (!add_intersection(insects, t1, object))
			return (0);
	}
	else
	{
		t1 = ((-quad.b) + quad.discriminant) / (2 * quad.a);
		t2 = ((-quad.b) - quad.discriminant) / (2 * quad.a);
		if (check_cap(*ray_transform, t1,
				((t_cylinder *)object->object)->height)
			&& !add_intersection(insects, t1, object))
			return (0);
		if (check_cap(*ray_transform, t2,
				((t_cylinder *)object->object)->height))
			if (!add_intersection(insects, t2, object))
				return (0);
	}
	return (1);
}

int	cylinder_intersect(t_intersections *insects, t_object_entry *object,
		t_ray *ray)
{
	t_cylinder	*cylinder;
	t_ray		ray_transform;
	t_quad_eq	quad;

	if (!insects || !object || !ray)
		return (0);
	cylinder = (t_cylinder *)object->object;
	ray_transform = transform_ray(cylinder->inv_t, ray);
	quad = check_cylinder_intersect(cylinder, &ray_transform);
	if (quad.discriminant < 0)
		return (1);
	return (prep_cylinder_intersect(quad, &ray_transform, insects, object));
}
