/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:16:30 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/01 14:12:26 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>

t_tuple	sphere_normal(t_sphere *obj, t_tuple *p)
{
	t_tuple		object_norm;
	t_tuple		world_norm;
	t_tuple		object_origin;
	t_tuple		inv_t_point;

	object_origin = point(0, 0, 0);
	inv_t_point = transform_f(obj->inv_t, p);
	object_norm = n_tuplesub(&inv_t_point, &object_origin);
	world_norm = matrix_mult_t(obj->tpose_inv_t, &object_norm);
	world_norm = tuplenormalize(&world_norm);
	world_norm.w = VECTOR;
	return (world_norm);
}

t_tuple	normal_at(void *obj, int obj_type, t_tuple *p)
{
	t_tuple	nv;

	if (obj_type == SPHERE)
		nv = sphere_normal(obj, p);
	return (nv);
}
