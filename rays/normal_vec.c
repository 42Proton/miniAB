/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:16:30 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/20 15:41:37 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>

t_tuple	sphere_normal(t_sphere *obj, t_tuple *p)
{
	t_tuple	object_norm;
	t_tuple	world_norm;
	t_tuple	object_origin;
	t_tuple	inv_t_point;

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

static t_tuple	get_cylinder_object_normal(t_tuple *object_point,
		float half_height)
{
	t_tuple	object_normal;
	float	dist;

	dist = object_point->x * object_point->x + object_point->z
		* object_point->z;
	if (dist < 1.0 && fabs(object_point->y - half_height) < EPSILON)
		object_normal = vector(0, 1, 0);
	else if (dist < 1.0 && fabs(object_point->y + half_height) < EPSILON)
		object_normal = vector(0, -1, 0);
	else
	{
		object_normal = vector(object_point->x, 0, object_point->z);
		object_normal = tuplenormalize(&object_normal);
	}
	return (object_normal);
}

t_tuple	cylinder_normal(t_cylinder *obj, t_tuple *p)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;
	float	half_height;

	object_point = transform_f(obj->inv_t, p);
	half_height = obj->height / 2;
	object_normal = get_cylinder_object_normal(&object_point, half_height);
	world_normal = matrix_mult_t(obj->tpose_inv_t, &object_normal);
	world_normal.w = VECTOR;
	return (tuplenormalize(&world_normal));
}

t_tuple	normal_at(void *obj, int obj_type, t_tuple *p)
{
	t_tuple	nv;

	ft_bzero(&nv, sizeof(t_tuple));
	if (obj_type == SPHERE)
		nv = sphere_normal(obj, p);
	else if (obj_type == PLANE)
		nv = plane_normal(obj);
	else if (obj_type == CYLINDER)
		nv = cylinder_normal(obj, p);
	return (nv);
}
