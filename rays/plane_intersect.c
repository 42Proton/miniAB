/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:46:45 by bismail           #+#    #+#             */
/*   Updated: 2025/04/03 12:46:01 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>
#include <rays.h>

float	check_plane_intersect(t_plane *plane, t_ray *ray)
{
	t_tuple	plane_to_ray;
	float	dot;
	float	t;

	if (!plane || !ray)
		return (0);
	plane_to_ray = n_tuplesub(&ray->origin, plane->pos);
	dot = tupledot(plane->normal_vector, &ray->direction);
	if (floatcmp(dot, 0))
		return (0);
	t = tupledot(plane->normal_vector, &plane_to_ray) / dot;
	if (t < 0)
		return (0);
	return (t);
}

int	plane_intersect(t_intersections *insects, t_object_entry *object,
		t_ray *ray)
{
	t_plane *plane;
	t_ray ray_transform;
	float t;

	if (!insects || !object || !ray)
		return (0);
	plane = (t_plane *)object->object;
	ray_transform = transform_ray(plane->inv_t, ray);
	t = check_plane_intersect(plane, &ray_transform);
	if (t == 0)
		return (0);
	if (!add_intersection(insects, t, object))
		return (0);
	return (1);
}