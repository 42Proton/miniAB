/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:54:55 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/05 22:55:17 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	*ambient_light(void)
{
	t_alight *al;
	char *tmp;
	char **colors;

	al = malloc(sizeof(t_alight));
	if (!al)
		return (NULL);
	tmp = ft_strtok(NULL, " \t\b\r\f\v\n");
	al->ratio = ft_atof(tmp);
	tmp = ft_strtok(NULL, " \t\b\r\f\v\n");
	colors = ft_split(tmp, ',');
	if (!colors)
	{
		free(al);
		return (NULL);
	}
	al->colors.red = ft_atoi(colors[0]);
	al->colors.green = ft_atoi(colors[1]);
	al->colors.blue = ft_atoi(colors[2]);
	al->colors.alpha = 0;
	free_array((void *)colors);
	return (al);
}