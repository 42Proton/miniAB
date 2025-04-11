/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:13:10 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/11 10:58:47 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_colors	*ray_color(t_rtptr *rts, t_ray *ray)
{
	t_colors		*res;
	t_intersections	*insects;
	t_intersect		*insect;
	t_computes		comp;

	insects = world_intersect(rts->solid_objs, ray);
	res = malloc(sizeof(t_colors));
	if (!insects || !res)
	{
		free(res);
		clear_intersections(insects);
		return (0);
	}
	insect = get_hit(insects);
	if (insect)
	{
		comp = init_computes(insect, ray);
		*res = shade_hit(rts->alight, &comp,
				((t_object_entry *)rts->vision_objs->content)->object);
	}
	else
		*res = colorinit(ft_fabs(ray->direction.y) * rts->alight->ratio, 0.8
				* rts->alight->ratio, 0.8 * rts->alight->ratio);
	clear_intersections(insects);
	return (res);
}

t_ray	ray_pixel(t_camera *cam, int x, int y)
{
	t_ray_pixel	data;

	data.world_x = cam->hwidth - ((x + 0.5) * cam->pixel_size);
	data.world_y = cam->hheight - ((y + 0.5) * cam->pixel_size);
	data.world_origin = point(0, 0, 0);
	data.world_point = point(data.world_x, data.world_y, -1);
	data.world_origin = transform_f(cam->inv_t, &data.world_origin);
	data.world_point = transform_f(cam->inv_t, &data.world_point);
	data.ray_direction = n_tuplesub(&data.world_point, &data.world_origin);
	data.ray_direction = tuplenormalize(&data.ray_direction);
	data.ray = init_ray(&data.world_origin, &data.ray_direction);
	return (data.ray);
}

t_colors	*scaled_ray(t_rtptr *rts ,t_camera *cam, int x, int y)
{
	t_ray	avg_rays;
	int	i;
	int	j;
	int 	counter;
	t_colors *total_color;
	t_colors *temp;

	i = -SSAA + 1;
	total_color = malloc(sizeof(t_colors));
	if(!total_color)
		return (NULL);
	*total_color = colorinit(0,0,0);
	counter = 0;
	while(i < SSAA)
	{	
		if( y + i > 0 && y + i < HEG)
		{
			j = -SSAA + 1;
			while(j < SSAA)
			{
				if( x + j > 0 && x + j < WID)
					avg_rays = ray_pixel(cam, x + j, y + i);
				temp = ray_color(rts,&avg_rays);
				if(!temp)
					return (NULL);
				*total_color = coloradd(total_color,temp);
				free(temp);
				counter++;
				j++;
			}
		}
		i++;
		
	}
	total_color->blue /= counter;
	total_color->red /= counter;
	total_color->green /= counter;

	return (total_color);
}
int	render_viewport(t_rtptr *rts)
{
	// t_ray		ray;
	t_colors	*color;
	int			x;
	int			y;

	y = 0;
	while (y < HEG)
	{
		x = 0;
		while (x < WID)
		{
			color = scaled_ray(rts,rts->camera,x,y);
			if (!color)
				return (0);
			mlx_put_pixel(rts->img, x, y, colorvalue(color));
			free(color);
			x ++;
		}
		y ++;
	}
	return (1);
}

