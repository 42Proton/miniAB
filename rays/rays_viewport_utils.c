/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_viewport_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:21:32 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/20 19:41:37 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_ray	ray_pixel(t_camera *cam, float x, float y)
{
	t_ray_pixel	data;

	data.world_x = cam->hwidth - (x + 0.5) * cam->pixel_size;
	data.world_y = cam->hheight - (y + 0.5) * cam->pixel_size;
	data.world_origin = point(0, 0, 0);
	data.world_point = point(data.world_x, data.world_y, -1);
	data.world_origin = transform_f(cam->inv_t, &data.world_origin);
	data.world_point = transform_f(cam->inv_t, &data.world_point);
	data.ray_direction = n_tuplesub(&data.world_point, &data.world_origin);
	data.ray_direction = tuplenormalize(&data.ray_direction);
	data.ray = init_ray(&data.world_origin, &data.ray_direction);
	return (data.ray);
}

t_colors	scaled_pixel(t_rtptr *rts, float offset_x, float offset_y)
{
	t_ray		ray;
	t_colors	color;

	ray = ray_pixel(rts->camera, offset_x, offset_y);
	color = ray_color(rts, &ray, 0);
	return (color);
}

t_colors	scaled_ray(t_rtptr *rts, int x, int y)
{
	int			i;
	int			j;
	int			counter;
	t_colors	total_color;
	t_colors	temp;

	total_color = colorinit(0, 0, 0);
	counter = 0;
	i = -1;
	while (++i < SSAA)
	{
		j = -1;
		while (++j < SSAA)
		{
			temp = scaled_pixel(rts, x + ((float)j + 0.5) / SSAA - 0.5,
					y + ((float)i + 0.5) / SSAA - 0.5);
			if (check_error(rts))
				return (total_color);
			total_color = coloradd(&total_color, &temp);
			counter++;
		}
	}
	colorscale(&total_color, counter);
	return (total_color);
}
