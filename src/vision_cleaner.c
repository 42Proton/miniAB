/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:00:17 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/17 02:40:04 by amsaleh          ###   ########.fr       */
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

void	free_camera(t_camera *camera)
{
	free(camera->orientation);
	free(camera->pos);
	free(camera);
}
