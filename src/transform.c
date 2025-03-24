/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 03:33:56 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/24 03:34:59 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	sphere_transform_m(t_sphere *obj)
{
	t_matrix	*s;
	t_tuple		vec;
	int			res;

	obj->transform = translation_m(obj->pos);
	if (!obj->transform)
		return (0);
	vec = vector(obj->dim, obj->dim, obj->dim);
	s = scale_m(&vec);
	if (!s)
		return (0);
	res = matrix_multiply(obj->transform, s);
	free_matrix(s);
	return (res);
}

int	plane_transform_m(t_plane *obj)
{
	return (1);
}

int	cylinder_transform_m(t_cylinder *obj)
{
	return (1);
}

int	prep_objs_transform(t_rtptr *rts)
{
	t_list *tmp;
	t_object_entry *entry;
	void *obj;
	int res;

	tmp = rts->solid_objs;
	while (tmp)
	{
		entry = (t_object_entry *)tmp->content;
		obj = entry->object;
		if (entry->type == SPHERE)
			res = sphere_transform_m((t_sphere *)obj);
		else if (entry->type == PLANE)
			res = plane_transform_m((t_plane *)obj);
		else if (entry->type == CYLINDER)
			res = cylinder_transform_m((t_cylinder *)obj);
		if (!res)
			return (EXIT_FAILURE);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}