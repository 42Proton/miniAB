/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vec_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:45:01 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/26 05:44:20 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>

t_tuple	get_cylinder_object_normal(t_tuple *object_point,
	float height)
{
	t_tuple	object_normal;

	if (floatcmp(object_point->z, height))
		object_normal = vector(0, 0, 1);
	else if (floatcmp(object_point->z, -height))
		object_normal = vector(0, 0, -1);
	else
	{
		object_normal = vector(object_point->x, object_point->y, 0);
		object_normal = tuplenormalize(&object_normal);
	}
	return (object_normal);
}
