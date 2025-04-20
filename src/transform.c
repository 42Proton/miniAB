/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 03:33:56 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/20 18:13:42 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	camera_transform_m(t_camera *obj)
{
	int			res;
	t_matrix	*m;
	t_tuple		vec;

	obj->transform = lookat_m(obj->pos, obj->orientation);
	if (!obj->transform)
		return (0);
	vec = tuplenegt(obj->pos);
	m = translation_m(&vec);
	if (!m)
		return (0);
	res = matrix_multiply(obj->transform, m);
	free_matrix(m);
	if (!res)
		return (0);
	obj->inv_t = matrix_inverse(obj->transform);
	if (!obj->inv_t)
		return (0);
	return (1);
}

int	sphere_transform_m(t_sphere *obj)
{
	t_matrix	*m;
	t_tuple		vec;
	int			res;

	obj->transform = translation_m(obj->pos);
	if (!obj->transform)
		return (0);
	vec = vector(obj->dim, obj->dim, obj->dim);
	m = scale_m(&vec);
	if (!m)
		return (0);
	res = matrix_multiply(obj->transform, m);
	free_matrix(m);
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
	obj->transform = translation_m(obj->pos);
	if (!obj->transform)
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
	if (!cylinder_tm_core(obj))
		return (0);
	obj->inv_t = matrix_inverse(obj->transform);
	if (!obj->inv_t)
		return (0);
	obj->tpose_inv_t = matrix_transpose(obj->inv_t);
	if (!obj->tpose_inv_t)
		return (0);
	return (1);
}

int	hyper_transform_m(t_hyper *obj)
{
	if (!hyper_tm_core(obj))
		return (0);
	obj->inv_t = matrix_inverse(obj->transform);
	if (!obj->inv_t)
		return (0);
	obj->tpose_inv_t = matrix_transpose(obj->inv_t);
	if (!obj->tpose_inv_t)
		return (0);
	return (1);
}
