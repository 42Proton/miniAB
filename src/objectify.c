/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:33:42 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/07 00:24:19 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_object_entry	*objectify(t_parser *parser, int type)
{
	t_object_entry *entry;

	entry = ft_calloc(1, sizeof(t_object_entry));
	if (!entry)
		return (NULL);
	// if (type == AMBIENTLIGHT)
	// 	entry->object = ambient_light(parser, &entry->type);
	if (type == SPHERE)
		entry->object = sphere_init();
	else if (type == PLANE)
		entry->object = plane_init();
	else if (type == CYLINDER)
		entry->object = cylinder_init();
	if (!entry->object)
	{
		free(entry);
		return (0);
	}
	return (entry);
}
