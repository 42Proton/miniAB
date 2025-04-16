/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_quad_parts.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:37:46 by bismail           #+#    #+#             */
/*   Updated: 2025/04/17 00:49:39 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>
#include <rays.h>

float	cylinder_first_part(t_ray *ray)
{
	return (ray->direction.x * ray->direction.x + ray->direction.z
		* ray->direction.z);
}

float	cylinder_middle_part(t_ray *ray)
{
	return (2 * (ray->origin.x * ray->direction.x + ray->origin.z
			* ray->direction.z));
}

float	cylinder_last_part(t_ray *ray, float radius)
{
	return (ray->origin.x * ray->origin.x + ray->origin.z * ray->origin.z
		- radius * radius);
}

float	cylinder_first_root(t_quad_eq quad, t_ray *ray_transform,
		t_object_entry *object)
{
	float	t1;

	t1 = ((-quad.b) + quad.discriminant) / (2 * quad.a);
	if (!check_cap(*ray_transform, t1, ((t_cylinder *)object->object)->height))
		return (t1);
	return (__FLT_MIN__);
}
