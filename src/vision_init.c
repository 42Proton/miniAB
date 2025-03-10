/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:54:55 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/10 03:50:02 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	*ambient_light_init(void)
{
	t_alight	*al;
	char		*tmp;

	al = ft_calloc(1, sizeof(t_alight));
	if (!al)
		return (NULL);
	tmp = ft_strtok(NULL, " \t\r\f\v");
	al->ratio = ft_atof(tmp);
	al->colors = color();
	if (!al->colors)
	{
		free(al);
		return (NULL);
	}
	return (al);
}

void	*light_init(void)
{
	t_light	*light;
	char	*tmp;

	light = ft_calloc(1, sizeof(t_light));
	if (!light)
		return (NULL);
	light->pos = pos();
	if (!light->pos)
	{
		free(light);
		return (NULL);
	}
	tmp = ft_strtok(NULL, " \t\r\f\v");
	light->brightness = ft_atof(tmp);
	light->colors = color();
	if (!light->colors)
	{
		free(light->pos);
		free(light);
		return (NULL);
	}
	return (light);
}
