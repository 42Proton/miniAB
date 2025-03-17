/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:32:31 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/17 17:24:38 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	*pos(void)
{
	char	**split_vec;
	t_tuple	*res;

	split_vec = ft_split(ft_strtok(0, " \t\r\f\v\n"), ',');
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

t_colors	*color(void)
{
	char		**colors;
	t_colors	*color;
	int			alpha;

	alpha = 255;
	colors = ft_split(ft_strtok(NULL, " \t\r\f\v\n"), ',');
	if (!colors)
		return (NULL);
	color = malloc(sizeof(t_colors));
	if (!color)
	{
		free_array((void **)colors);
		return (0);
	}
	if (ft_arrlen((void **)colors) > 3)
		alpha = alpha_ftos(ft_atof(colors[3]));
	*color = colorinit(ft_atoi(colors[0]), ft_atoi(colors[1]),
			ft_atoi(colors[2]), alpha);
	free_array((void **)colors);
	return (color);
}
