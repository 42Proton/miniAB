/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:33:42 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/15 22:50:45 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	objectify_switch(t_object_entry	*entry, int type)
{
	if (type == AMBIENTLIGHT)
		entry->object = ambient_light_init();
	else if (type == CAMERA)
		entry->object = camera_init();
	else if (type == LIGHT)
		entry->object = light_init();
	else if (type == SPHERE)
		entry->object = sphere_init();
	else if (type == PLANE)
		entry->object = plane_init();
	else if (type == CYLINDER)
		entry->object = cylinder_init();
	else if (type == HYPER)
		entry->object = hyper_init();
}

t_object_entry	*objectify(t_parser *parser, int type)
{
	t_object_entry	*entry;

	entry = ft_calloc(1, sizeof(t_object_entry));
	if (!entry)
		return (NULL);
	objectify_switch(entry, type);
	if (!entry->object)
	{
		free(entry);
		return (0);
	}
	entry->type = type;
	return (entry);
}
