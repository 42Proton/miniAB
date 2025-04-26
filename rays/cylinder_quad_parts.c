/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_quad_parts.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:37:46 by bismail           #+#    #+#             */
/*   Updated: 2025/04/26 23:00:19 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>

float	cylinder_first_part(t_ray *ray)
{
	return (ray->direction.x * ray->direction.x
		+ ray->direction.y * ray->direction.y);
}

float	cylinder_middle_part(t_ray *ray)
{
	return (2 * (ray->origin.x * ray->direction.x
			+ ray->origin.y * ray->direction.y));
}

float	cylinder_last_part(t_ray *ray)
{
	return (ray->origin.x * ray->origin.x
		+ ray->origin.y * ray->origin.y - 1);
}

float	cylinder_first_root(t_quad_eq quad, t_ray *ray_transform,
		t_object_entry *object)
{
	float	t1;

	t1 = (-quad.b) / (2 * quad.a);
	if (!cylinder_cap(ray_transform, t1, object->object))
		return (t1);
	return (__FLT_MIN__);
}
