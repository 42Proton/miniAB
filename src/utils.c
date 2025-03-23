/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:32:31 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/23 03:05:09 by amsaleh          ###   ########.fr       */
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

int	prep_transform_m(t_matrix **m)
{
	*m = ident_matrix4x4(4, 4);
	if (!m)
		return (0);
	return (1);
}

int	prep_objs_transform(t_rtptr *rts)
{
	t_list			*tmp;
	t_object_entry	*entry;
	void			*obj;
	int				res;

	tmp = rts->objs;
	while (tmp)
	{
		entry = (t_object_entry *)tmp->content;
		obj = entry->object;
		if (entry->type == SPHERE)
			res = prep_transform_m(&((t_sphere *)obj)->transform);
		if (!res)
			return (EXIT_FAILURE);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
