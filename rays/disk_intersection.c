/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:41:23 by bismail           #+#    #+#             */
/*   Updated: 2025/04/26 23:00:22 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>

static float	check_hit_point_in_disk(t_ray *ray, float t, t_tuple *local_pos)
{
	t_tuple	hit_point;
	t_tuple	temp;
	float	distance_from_center;

	hit_point = ray_hitpoint(ray, t);
	hit_point.z = 0;
	local_pos->z = 0;
	temp = n_tuplesub(&hit_point, local_pos);
	distance_from_center = tuplemag2(&temp);
	if (distance_from_center <= 1.0f)
		return (t);
	return (__FLT_MIN__);
}

float	check_disk_intersect(t_cylinder *cylinder, t_ray *ray, float z_pos)
{
	t_tuple	n;
	float	denom;
	t_tuple	p2r;
	float	t;
	t_tuple	local_pos;

	n = vector(0, 0, 1);
	denom = tupledot(&n, &ray->direction);
	if (ft_fabs(denom) > EPSILON)
	{
		local_pos = point(0, 0, z_pos);
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

	if (!insects || !object || !ray)
		return (0);
	cylinder = (t_cylinder *)(object->object);
	ray_transform = transform_ray(cylinder->inv_t, ray);
	t = check_disk_intersect(cylinder, &ray_transform, -cylinder->height);
	if (t != __FLT_MIN__ && !add_intersection(insects, t, object))
		return (0);
	t = check_disk_intersect(cylinder, &ray_transform, cylinder->height);
	if (t != __FLT_MIN__ && !add_intersection(insects, t, object))
		return (0);
	return (1);
}
