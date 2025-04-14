/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 02:01:56 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/10 03:38:00 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	*get_color_map_name(t_object_entry *entry)
{
	if (entry->type == SPHERE)
		return (((t_sphere *)entry->object)->color_map);
	if (entry->type == PLANE)
		return (((t_plane *)entry->object)->color_map);
	if (entry->type == CYLINDER)
		return (((t_cylinder *)entry->object)->color_map);
	return (0);
}

void	*get_bump_map_name(t_object_entry *entry)
{
	if (entry->type == SPHERE)
		return (((t_sphere *)entry->object)->bump_map);
	if (entry->type == PLANE)
		return (((t_plane *)entry->object)->bump_map);
	if (entry->type == CYLINDER)
		return (((t_cylinder *)entry->object)->bump_map);
	return (0);
}

mlx_texture_t	*get_texture_ref(char *str, t_rtptr *rts)
{
	t_list		*node;
	t_texture	*texture;

	node = rts->textures;
	while (node)
	{
		texture = node->content;
		if (!ft_strcmp(str, texture->name))
			return (texture->map);
		node = node->next;
	}
	return (0);
}
