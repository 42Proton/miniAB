/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:42:04 by bismail           #+#    #+#             */
/*   Updated: 2025/04/20 19:47:21 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	cylinder_tm_core(t_cylinder *obj)
{
	t_matrix	*m;
	t_tuple		vec;
	int			res;

	obj->transform = translation_m(obj->pos);
	if (!obj->transform)
		return (0);
	m = lookat_m(obj->pos, obj->normal_axis);
	if (!m)
		return (0);
	res = matrix_multiply(obj->transform, m);
	free_matrix(m);
	if (!res)
		return (0);
	vec = vector(obj->dim, obj->dim, obj->height);
	m = scale_m(&vec);
	if (!m)
		return (0);
	res = matrix_multiply(obj->transform, m);
	free_matrix(m);
	if (!res)
		return (0);
	return (1);
}

int	hyper_tm_core(t_hyper *obj)
{
	t_matrix	*m;
	int			res;

	obj->transform = translation_m(obj->pos);
	if (!obj->transform)
		return (0);
	m = lookat_m(obj->pos, obj->nv);
	if (!m)
		return (0);
	res = matrix_multiply(obj->transform, m);
	free_matrix(m);
	if (!res)
		return (0);
	m = scale_m(obj->scale);
	if (!m)
		return (0);
	res = matrix_multiply(obj->transform, m);
	free_matrix(m);
	if (!res)
		return (0);
	return (1);
}
