/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:32:31 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/05 23:32:59 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	*pos(void)
{
	char	*tmp;
	char	**arrays;
	t_tuple	*pnt;

	tmp = ft_strtok(NULL, " \t\b\r\f\v\n");
	arrays = ft_split(tmp, ',');
	if (!arrays)
		return (NULL);
	free_array((void *)arrays);
	pnt = point(ft_atof(arrays[0]), ft_atof(arrays[1]), ft_atof(arrays[2]));
	return (pnt);
}
void	*color(void)
{
	char *tmp;
	char **colors;
	t_colors *color;

	tmp = ft_strtok(NULL, " \t\b\r\f\v\n");
	colors = ft_split(tmp, ',');
	if (!colors)
		return (NULL);
	color = colorinit(ft_atoi(colors[0]), ft_atoi(colors[1]),
			ft_atoi(colors[2]), 0);
	free_array((void *)colors);
	return (color);
}