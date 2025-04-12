/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:13:10 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/12 11:00:46 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_colors	ray_color(t_rtptr *rts, t_ray *ray)
{
	t_colors		res;
	t_intersections	*insects;
	t_intersect		*insect;
	t_computes		comp;

	insects = world_intersect(rts->solid_objs, ray);
	ft_bzero(&res, sizeof(t_colors));
	if (!insects)
	{
		rts->is_err = 1;
		clear_intersections(insects);
		return (res);
	}
	insect = get_hit(insects);
	if (insect)
	{
		comp = init_computes(rts, insect, ray);
		if (comp.is_err)
		{
			rts->is_err = 1;
			clear_intersections(insects);
			return (res);
		}
		res = shade_hit(rts->alight, &comp, rts->vision_objs);
	}
	else
		res = colorinit(ft_fabs(ray->direction.y) * rts->alight->ratio, 0.8
				* rts->alight->ratio, 0.8 * rts->alight->ratio);
	clear_intersections(insects);
	return (res);
}

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
	color = ray_color(rts, &ray);
	return (color);
}

t_colors	scaled_ray(t_rtptr *rts, t_camera *cam, int x, int y)
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
			if (rts->is_err)
				return (total_color);
			total_color = coloradd(&total_color, &temp);
			counter++;
		}
	}
	colorscale(&total_color, counter);
	return (total_color);
}

int	render_viewport(t_rtptr *rts)
{
	t_colors	color;
	int			x;
	int			y;

	y = 0;
	while (y < HEG)
	{
		x = 0;
		while (x < WID)
		{
			color = scaled_ray(rts, rts->camera, x, y);
			if (rts->is_err)
				return (0);
			mlx_put_pixel(rts->img, x, y, colorvalue(&color));
			x++;
		}
		y++;
	}
	return (1);
}
