/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:35:33 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/20 19:41:47 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>

int	world_intersect_iter(t_list *solid_objs,
	t_intersections *insects, t_ray *ray)
{
	int				res;
	t_object_entry	*entry;

	entry = solid_objs->content;
	if (entry->type == SPHERE)
		res = sphere_intersect(insects, entry, ray);
	if (entry->type == PLANE)
		res = plane_intersect(insects, entry, ray);
	if (entry->type == HYPER)
		res = hyper_intersect(insects, entry, ray);
	if (entry->type == CYLINDER)
		res = cylinder_intersect(insects, entry, ray);
	return (res);
}
