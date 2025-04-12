/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:16:30 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/12 00:04:15 by bismail          ###   ########.fr       */
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
	world_norm.w = VECTOR;
	world_norm = tuplenormalize(&world_norm);
	return (world_norm);
}

t_tuple	plane_normal(t_plane *obj)
{
	t_tuple	world_norm;

	world_norm = transform_f(obj->tpose_inv_t, obj->normal_vector);
	world_norm.w = 0;
	world_norm = tuplenormalize(&world_norm);
	return (world_norm);
}

t_tuple	normal_at(void *obj, int obj_type, t_tuple *p)
{
	t_tuple	nv;

	ft_bzero(&nv, sizeof(t_tuple));
	if (obj_type == SPHERE)
		nv = sphere_normal(obj, p);
	if (obj_type == PLANE)
		nv = plane_normal(obj);
	return (nv);
}
