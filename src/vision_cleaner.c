/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:00:17 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/07 01:18:40 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	free_ambient(t_alight *al)
{
	free(al->colors);
	free(al);
}
void	free_light(t_light *light)
{
	free(light->colors);
	free(light->pos);
	free(light);
}