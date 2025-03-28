/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 03:33:56 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/26 16:18:12 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	sphere_transform_m(t_sphere *obj)
{
	t_matrix	*s;
	t_tuple		vec;
	int			res;

	obj->transform = translation_m(obj->pos);
	if (!obj->transform)
		return (0);
	vec = vector(obj->dim, obj->dim, obj->dim);
	s = scale_m(&vec);
	if (!s)
		return (0);
	res = matrix_multiply(obj->transform, s);
	free_matrix(s);
	return (res);
}

int	plane_transform_m(t_plane *obj)
{
}

int	cylinder_transform_m(t_cylinder *obj)
{
	return (1);
}
