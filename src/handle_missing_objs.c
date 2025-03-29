/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_missing_objs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 05:24:16 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/29 20:06:16 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_camera	*init_default_camera()
{
	t_camera	*cam;

	cam = ft_calloc(1, sizeof(t_camera));
	if (!cam)
		return (0);
	cam->orientation = ft_calloc(1, sizeof(t_tuple));
	cam->pos = ft_calloc(1, sizeof(t_tuple));
	if (!cam->orientation || !cam->pos)
	{
		free(cam->orientation);
		free(cam->pos);
		free(cam);
		return (0);
	}
	cam->fov = 90;
	return (cam);
}

static t_alight	*init_default_alight()
{
	t_alight	*alight;

	alight = malloc(sizeof(t_alight));
	if (!alight)
		return (0);
	alight->colors = malloc(sizeof(t_colors));
	if (!alight->colors)
	{
		free(alight);
		return (0);
	}
	*alight->colors = colorinit(255, 255, 255);
	alight->ratio = 1.0f;
	return (alight);
}

int	handle_missing_objs(t_rtptr *rts)
{
	if (!rts->camera)
	{
		simple_report(WARN_CAMERA_MISSING);
		rts->camera = init_default_camera();
		if (!rts->camera)
		{
			perror("malloc");
			return (EXIT_FAILURE);
		}
	}
	if (!rts->alight)
	{
		simple_report(WARN_ALIGHT_MISSING);
		rts->alight = init_default_alight();
		if (!rts->alight)
		{
			perror("malloc");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
