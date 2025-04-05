/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:16:30 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/05 13:11:45 by bismail          ###   ########.fr       */
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

t_tuple	plane_normal(t_plane *obj)
{
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_normal = *obj->normal_vector;
	world_normal = matrix_mult_t(obj->tpose_inv_t, &object_normal);
	world_normal = tuplenormalize(&world_normal);
	return (world_normal);
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
