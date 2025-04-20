/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:41:23 by bismail           #+#    #+#             */
/*   Updated: 2025/04/20 15:34:43 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>
#include <rays.h>

static float	check_hit_point_in_disk(t_ray *ray, float t, t_tuple *local_pos)
{
	t_tuple	hit_point;
	t_tuple	temp;
	float	distance_from_center;

	hit_point = ray_hitpoint(ray, t);
	hit_point.y = 0;
	local_pos->y = 0;
	temp = n_tuplesub(&hit_point, local_pos);
	distance_from_center = tuplemag2(&temp);
	if (distance_from_center <= 1.0f)
		return (t);
	return (__FLT_MIN__);
}

float	check_disk_intersect(t_cylinder *cylinder, t_ray *ray, float y_pos)
{
	t_tuple	n;
	float	denom;
	t_tuple	p2r;
	float	t;
	t_tuple	local_pos;

	n = vector(0, 1, 0);
	denom = tupledot(&n, &ray->direction);
	if (ft_fabs(denom) > EPSILON)
	{
		local_pos = point(0, y_pos, 0);
		p2r = n_tuplesub(&local_pos, &ray->origin);
		t = tupledot(&p2r, &n) / denom;
		if (t >= 0)
			return (check_hit_point_in_disk(ray, t, &local_pos));
	}
	return (__FLT_MIN__);
}

int	disk_intersection(t_intersections *insects, t_object_entry *object,
		t_ray *ray)
{
	t_cylinder	*cylinder;
	t_ray		ray_transform;
	float		t;
	float		y_pos;

	if (!insects || !object || !ray)
		return (0);
	cylinder = (t_cylinder *)(object->object);
	ray_transform = transform_ray(cylinder->inv_t, ray);
	y_pos = -(cylinder->height / 2);
	t = check_disk_intersect(cylinder, &ray_transform, y_pos);
	if (t != __FLT_MIN__ && !add_intersection(insects, t, object))
		return (0);
	y_pos = cylinder->height / 2;
	t = check_disk_intersect(cylinder, &ray_transform, y_pos);
	if (t != __FLT_MIN__ && !add_intersection(insects, t, object))
		return (0);
	return (1);
}
