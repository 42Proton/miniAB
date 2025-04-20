/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_transform.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:42:04 by bismail           #+#    #+#             */
/*   Updated: 2025/04/20 15:57:15 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	apply_cylinder_rotation(t_cylinder *obj)
{
	t_matrix	*r;
	t_tuple		vec;
	t_tuple		up;
	t_tuple		axis;
	int			res;

	axis = tuplenormalize(obj->normal_axis);
	up = vector(0, 1, 0);
	if (fabs(tupledot(&up, &axis) - 1.0) > EPSILON)
	{
		vec = norm_to_radian(obj->normal_axis);
		r = rotation_m(&vec);
		if (!r)
			return (0);
		res = matrix_multiply(obj->transform, r);
		free_matrix(r);
		if (!res)
			return (0);
	}
	return (1);
}

int	apply_cylinder_scaling(t_cylinder *obj)
{
	t_matrix	*s;
	t_tuple		vec;
	int			res;

	vec = vector(obj->dim, obj->height, obj->dim);
	s = scale_m(&vec);
	if (!s)
		return (0);
	res = matrix_multiply(obj->transform, s);
	free_matrix(s);
	return (res);
}
