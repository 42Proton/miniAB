/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:54:55 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/05 23:57:55 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	*ambient_light(void)
{
	t_alight	*al;
	char		*tmp;

	al = malloc(sizeof(t_alight));
	if (!al)
		return (NULL);
	tmp = ft_strtok(NULL, " \t\b\r\f\v\n");
	al->ratio = ft_atof(tmp);
	al->colors = color();
	if (!al->colors)
	{
		free(al);
		return (NULL);
	}
	return (al);
}
void	*light(void)
{
	t_light	*light;
	char	*tmp;

	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->pos = pos();
	if (!light->pos)
	{
		free(light);
		return (NULL);
	}
	tmp = ft_strtok(NULL, " \t\b\r\f\v\n");
	light->brightness = ft_atof(tmp);
	light->colors = color();
	if (!light->colors)
	{
		free(light->pos);
		free(light);
		return (NULL);
	}
	printf("%f,%f,%f %f %d %d %d", light->pos->X, light->pos->Y, light->pos->Z,
		light->brightness, light->colors->red, light->colors->green,
		light->colors->blue);
	return (light);
}
