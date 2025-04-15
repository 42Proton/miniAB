/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:16:30 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/15 22:58:13 by amsaleh          ###   ########.fr       */
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
	world_norm.w = VECTOR;
	world_norm = tuplenormalize(&world_norm);
	return (world_norm);
}

t_tuple	hyper_normal(t_hyper *obj, t_tuple *p)
{
	t_tuple	world_norm;
	t_tuple	object_norm;
	t_tuple	inv_p;
	t_tuple	*coeffs;

	coeffs = &obj->coeffs2;
	inv_p = transform_f(obj->inv_t, p);
	object_norm = vector(inv_p.x / coeffs->x,
			inv_p.y / coeffs->y, -inv_p.z / coeffs->z);
	world_norm = transform_f(obj->tpose_inv_t, &object_norm);
	world_norm.w = VECTOR;
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
	if (obj_type == HYPER)
		nv = hyper_normal(obj, p);
	return (nv);
}
