/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init_misc_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:51:33 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/15 22:53:24 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	*phong_props(char *tok)
{
	char	**split_vec;
	t_tuple	*res;

	split_vec = ft_split(tok, ',');
	if (!split_vec)
		return (0);
	res = malloc(sizeof(t_tuple));
	if (!res)
	{
		free_array((void **)split_vec);
		return (0);
	}
	*res = point(ft_atof(split_vec[0]), ft_atof(split_vec[1]),
			ft_atof(split_vec[2]));
	free_array((void **)split_vec);
	return (res);
}

int	check_init_misc(char *tok, void *phong_props, void *color_map,
		void *bump_map)
{
	if (!ft_strncmp(tok, "phong:", 6))
	{
		if (!phong_props)
			return (0);
	}
	else if (!ft_strncmp(tok, "color:", 6))
	{
		if (!color_map)
			return (0);
	}
	else if (!ft_strncmp(tok, "bump:", 5))
	{
		if (!bump_map)
			return (0);
	}
	return (1);
}
