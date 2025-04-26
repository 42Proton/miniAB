/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:32:31 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/26 23:01:28 by amsaleh          ###   ########.fr       */
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

t_tuple	*norm_vec(void)
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
	*res = vector(ft_atof(split_vec[0]), ft_atof(split_vec[1]),
			ft_atof(split_vec[2]));
	*res = tuplenormalize(res);
	free_array((void **)split_vec);
	return (res);
}

t_colors	*color(void)
{
	char		**colors;
	t_colors	*color;
	int			red;
	int			green;
	int			blue;

	colors = ft_split(ft_strtok(NULL, " \t\r\f\v\n"), ',');
	if (!colors)
		return (NULL);
	color = malloc(sizeof(t_colors));
	if (!color)
	{
		free_array((void **)colors);
		return (0);
	}
	red = ft_atoi(colors[0]);
	green = ft_atoi(colors[1]);
	blue = ft_atoi(colors[2]);
	*color = colorinit(red / 255.0f, green / 255.0f,
			blue / 255.0f);
	free_array((void **)colors);
	return (color);
}

t_tuple	norm_to_radian(t_tuple *vec)
{
	t_tuple	res;

	res.x = vec->x * PI_2;
	res.y = vec->y * PI_2;
	res.z = vec->z * PI_2;
	res.w = VECTOR;
	return (res);
}

float	deg_to_rad(float deg)
{
	return (deg * PI_180);
}
