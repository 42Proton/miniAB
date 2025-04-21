/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vec_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:45:01 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/21 17:48:34 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>

t_tuple	get_cylinder_object_normal(t_tuple *object_point,
	float height)
{
	t_tuple	object_normal;
	float	dist;

	dist = object_point->x * object_point->x + object_point->y
		* object_point->y;
	if (dist < 1.0 && ft_fabs(object_point->z - height) < EPSILON)
		object_normal = vector(0, 0, 1);
	else if (dist < 1.0 && ft_fabs(object_point->z + height) < EPSILON)
		object_normal = vector(0, 0, -1);
	else
	{
		object_normal = vector(object_point->x, object_point->y, 0);
		object_normal = tuplenormalize(&object_normal);
	}
	return (object_normal);
}
