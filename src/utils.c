/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:32:31 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/10 03:51:47 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	*pos(void)
{
	char	**split_vec;
	t_tuple	*res;

	split_vec = ft_split(ft_strtok(0, " \t\r\f\v"), ',');
	if (!split_vec)
		return (0);
	res = point(ft_atof(split_vec[0]), ft_atof(split_vec[1]),
			ft_atof(split_vec[2]));
	free_array((void **)split_vec);
	return (res);
}

void	*color(void)
{
	char		**colors;
	t_colors	*color;
	int			alpha;

	alpha = 1;
	colors = ft_split(ft_strtok(NULL, " \t\r\f\v"), ',');
	if (!colors)
		return (NULL);
	if (ft_arrlen((void **)colors) > 3)
		alpha = alpha_ftos(ft_atof(colors[3]));
	color = colorinit(ft_atoi(colors[0]), ft_atoi(colors[1]),
			ft_atoi(colors[2]), alpha);
	free_array((void **)colors);
	return (color);
}
