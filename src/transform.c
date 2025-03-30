/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 03:33:56 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/30 08:27:59 by bismail          ###   ########.fr       */
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
	if (!res)
		return (0);
	obj->inv_t = matrix_inverse(obj->transform);
	if (!obj->inv_t)
		return (0);
	obj->tpose_inv_t = matrix_transpose(obj->inv_t);
	if (!obj->tpose_inv_t)
		return (0);
	return (1);
}

int	plane_transform_m(t_plane *obj)
{
	t_matrix	*s;
	t_tuple		vec;
	int			res;

	// This Function is theioratically, and practically understandable
	obj->transform = translation_m(obj->pos);
	if (!obj->transform)
		return (0);
	vec = vector(1, 1, 1);
	s = scale_m(&vec);
	if (!s)
		return (0);
	res = matrix_multiply(obj->transform, s);
	free_matrix(s);
	if (!res)
		return (0);
	obj->inv_t = matrix_inverse(obj->transform);
	if (!obj->inv_t)
		return (0);
	obj->tpose_inv_t = matrix_transpose(obj->inv_t);
	if (!obj->tpose_inv_t)
		return (0);
	return (1);
}

int	cylinder_transform_m(t_cylinder *obj)
{
	t_matrix	*s;
	t_tuple		vec;
	int			res;

	// This Function is theioratically, and practically understandable
	obj->transform = translation_m(obj->pos);
	if (!obj->transform)
		return (0);
	vec = vector(obj->dim, obj->dim, obj->height);
	s = scale_m(&vec);
	if (!s)
		return (0);
	res = matrix_multiply(obj->transform, s);
	free_matrix(s);
	if (!res)
		return (0);
	// There should be a rotation matrix here
	obj->inv_t = matrix_inverse(obj->transform);
	if (!obj->inv_t)
		return (0);
	obj->tpose_inv_t = matrix_transpose(obj->inv_t);
	if (!obj->tpose_inv_t)
		return (0);
	return (1);
}
