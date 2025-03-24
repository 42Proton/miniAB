/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:32:31 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/24 03:33:48 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>
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

t_tuple	norm_to_radian(t_tuple *vec)
{
	t_tuple	res;

	if (vec->x >= 0)
		res.x = vec->x * M_PI;
	else
		res.x = ft_fabs(vec->x) * M_PI + M_PI;
	if (vec->y >= 0)
		res.y = vec->y * M_PI;
	else
		res.y = ft_fabs(vec->y) * M_PI + M_PI;
	if (vec->z >= 0)
		res.z = vec->z * M_PI;
	else
		res.z = ft_fabs(vec->z) * M_PI + M_PI;
	res.w = VECTOR;
	return (res);
}
