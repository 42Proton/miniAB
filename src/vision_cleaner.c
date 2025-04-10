/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:00:17 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/10 04:07:03 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	free_ambient(t_alight *al)
{
	if (al)
	{
		free(al->colors);
		free(al);
	}
}

void	free_light(t_light *light)
{
	free(light->colors);
	free(light->pos);
	free(light);
}

void	free_camera(t_camera *camera)
{
	if (camera)
	{
		free(camera->orientation);
		free(camera->pos);
		free_matrix(camera->transform);
		free_matrix(camera->inv_t);
		free(camera);
	}
}
