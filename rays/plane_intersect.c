/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:46:45 by bismail           #+#    #+#             */
/*   Updated: 2025/04/04 21:01:30 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>
#include <rays.h>

float	check_plane_intersect(t_plane *plane, t_ray *ray)
{
	t_tuple	*n;
	float	denom;
	t_tuple	p2r;
	float	t;
	t_tuple	normpos;

	normpos = tuplenormalize(plane->pos);
	n = plane->normal_vector;
	denom = tupledot(n, &ray->direction);
	if (denom < -EPSILON)
	{
		p2r = n_tuplesub(&normpos, &ray->origin);
		t = tupledot(&p2r, n) / denom;
		if (t >= 0)
			return (t);
	}
	return (0);
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
	if (floatcmp(t, 0))
		return (1);
	if (!add_intersection(insects, t, object))
		return (0);
	return (1);
}