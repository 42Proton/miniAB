/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:56:01 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/24 01:31:46 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>
#include <debug.h>

int	prep_intersections_sphere(t_intersections *res,
	t_object_entry *obj_entry, t_quad_eq *quad_eq)
{
	float	t1;
	float	t2;

	t1 = ((quad_eq->b * -1) - sqrt(quad_eq->discriminant))
		/ (2 * quad_eq->a);
	t2 = ((quad_eq->b * -1) + sqrt(quad_eq->discriminant))
		/ (2 * quad_eq->a);
	if (!add_intersection(res, t1, obj_entry))
		return (0);
	if (!add_intersection(res, t2, obj_entry))
		return (0);
	return (1);
}

t_quad_eq	sphere_quad_eq(t_object_entry *obj_entry, t_ray *ray)
{
	t_tuple		sphere_to_ray;
	t_quad_eq	quad_eq;
	t_tuple		world_origin;

	world_origin = point(0, 0, 0);
	sphere_to_ray = n_tuplesub(&ray->origin, &world_origin);
	quad_eq.a = tupledot(&ray->direction, &ray->direction);
	quad_eq.b = 2 * tupledot(&ray->direction, &sphere_to_ray);
	quad_eq.c = tupledot(&sphere_to_ray, &sphere_to_ray)
		- 1;
	quad_eq.discriminant = quad_eq.b * quad_eq.b - 4
		* quad_eq.a * quad_eq.c;
	return (quad_eq);
}

t_intersections	*sphere_intersect(t_object_entry *obj_entry, t_ray *ray)
{
	t_quad_eq		quad_eq;
	t_sphere		*sphere;
	t_intersections	*res;
	t_ray			ray_transform;
	t_matrix		*m_inv;

	sphere = (t_sphere *)obj_entry->object;
	m_inv = matrix_inverse(sphere->transform);
	if (!m_inv)
		return (0);
	ray_transform = transform_ray(m_inv, ray);
	free_matrix(m_inv);
	res = ft_calloc(1, sizeof(t_intersections));
	if (!res)
		return (0);
	quad_eq = sphere_quad_eq(obj_entry, &ray_transform);
	if (quad_eq.discriminant < 0)
		return (res);
	if (!prep_intersections_sphere(res, obj_entry, &quad_eq))
	{
		clear_intersections(res);
		return (0);
	}
	return (res);
}

t_ray	init_ray(t_tuple *origin, t_tuple *direction)
{
	t_ray	ray;

	ray.origin = *origin;
	ray.direction = *direction;
	return (ray);
}

t_tuple	ray_hitpoint(t_ray *ray, float t)
{
	t_tuple hit_direction;
	t_tuple	res;

	hit_direction = n_tuplesmult(&ray->direction, t);
	res = n_tupleadd(&ray->origin, &hit_direction);
	return (res);
}
