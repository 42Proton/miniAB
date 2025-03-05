/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 01:17:49 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/05 03:06:26 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	*ambient_light(void)
{
	t_alight *al;
	char *tmp;

	al = malloc(sizeof(t_alight));
	if (!al)
		return (NULL);
	tmp = ft_strtok(NULL, " \t\b\r\f\v\n");
	al->ratio = ft_atof(tmp, 0);
	tmp = ft_strtok(NULL, " \t\b\r\f\v\n");
	return (al);
}