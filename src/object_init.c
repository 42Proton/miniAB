/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 01:17:49 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/04 02:07:42 by abueskander      ###   ########.fr       */
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
	al->ratio = atof(tmp);
	tmp = ft_strtok(NULL, " \t\b\r\f\v\n");
	return (al);
}