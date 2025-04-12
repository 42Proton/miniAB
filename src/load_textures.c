/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:47:32 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/10 04:08:13 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	check_dup_texture(char *str, t_list *textures)
{
	t_texture	*texture;

	while (textures)
	{
		texture = textures->content;
		if (!ft_strcmp(texture->name, str))
			return (1);
		textures = textures->next;
	}
	return (0);
}

mlx_texture_t	*load_texture(char *str)
{
	char			*path;
	mlx_texture_t	*map;

	path = ft_strjoin("./textures/", str);
	if (!path)
	{
		perror("malloc");
		return (0);
	}
	map = mlx_load_png(path);
	free(path);
	if (!map)
	{
		ft_dprintf(2, "mlx_load_png failure\n");
		return (0);
	}
	return (map);
}

int	push_texture(t_rtptr *rts, char *str)
{
	t_texture	*texture;
	t_list		*node;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (0);
	texture->name = str;
	texture->map = load_texture(str);
	if (!texture->map)
	{
		free(texture);
		return (0);
	}
	node = ft_lstnew(texture);
	if (!node)
	{
		free(texture->name);
		free(texture);
		return (0);
	}
	ft_lstadd_back(&rts->textures, node);
	return (1);
}

int	push_textures(t_rtptr *rts, t_object_entry *entry)
{
	char		*color_map;
	char		*bump_map;

	color_map = get_color_map_name(entry);
	bump_map = get_bump_map_name(entry);
	if (color_map && !(check_dup_texture(color_map, rts->textures)))
	{
		if (!push_texture(rts, color_map))
			return (0);
	}
	if (bump_map && !(check_dup_texture(bump_map, rts->textures)))
	{
		if (!push_texture(rts, bump_map))
			return (0);
	}
	return (1);
}

int	load_textures(t_rtptr *rts)
{
	t_list			*lst;
	t_object_entry	*entry;

	lst = rts->solid_objs;
	while (lst)
	{
		entry = lst->content;
		if (!push_textures(rts, entry))
			return (EXIT_FAILURE);
		lst = lst->next;
	}
	return (EXIT_SUCCESS);
}
