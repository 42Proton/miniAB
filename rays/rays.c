/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:56:01 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/16 00:01:47 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>

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

t_quad_eq	*sphere_quad_eq(t_object_entry *obj_entry, t_ray *ray)
{
	t_tuple		*sphere_to_ray;
	t_sphere	*sphere;
	t_quad_eq	*quad_eq;

	sphere = (t_sphere *)obj_entry->object;
	sphere_to_ray = tuplesub(ray->origin, sphere->pos);
	if (!sphere_to_ray)
		return (0);
	quad_eq = malloc(sizeof(quad_eq));
	if (!quad_eq)
	{
		free(sphere_to_ray);
		return (0);
	}
	quad_eq->a = tupledot(ray->direction, ray->direction);
	quad_eq->b = 2 * tupledot(ray->direction, sphere_to_ray);
	quad_eq->c = tupledot(sphere_to_ray, sphere_to_ray) - sphere->dim;
	quad_eq->discriminant = quad_eq->b * quad_eq->b - 4
		* quad_eq->a * quad_eq->c;
	free(sphere_to_ray);
	return (quad_eq);
}

t_intersections	*sphere_intersect(t_object_entry *obj_entry, t_ray *ray)
{
	t_quad_eq		*quad_eq;
	t_intersections	*res;

	res = ft_calloc(1, sizeof(res));
	if (!res)
		return (0);
	quad_eq = sphere_quad_eq(obj_entry, ray);
	if (!quad_eq)
	{
		free(res);
		return (0);
	}
	if (quad_eq->discriminant < 0)
	{
		free(quad_eq);
		return (res);
	}
	if (!prep_intersections_sphere(res, obj_entry, quad_eq))
	{
		clear_intersections(res);
		free(quad_eq);
		return (0);
	}
	free(quad_eq);
	return (res);
}

t_ray	*init_ray(t_tuple *origin, t_tuple *direction)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (0);
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}
