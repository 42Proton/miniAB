/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:42:32 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/26 22:51:08 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

time_t	get_timestamp_sec(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return (time.tv_sec);
}

void	keyhook(struct mlx_key_data keydata, void *rtptr)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		cleaner(rtptr);
}

void	resizehook(int width, int height, void *rtptr)
{
	t_rtptr			*rts;

	rts = rtptr;
	rts->width = width;
	rts->height = height;
	rts->resize_time = get_timestamp_sec();
}

void	generichook(void *rtptr)
{
	t_rtptr	*rts;

	rts = rtptr;
	if (rts->resize_time)
	{
		if (get_timestamp_sec() > rts->resize_time + 3)
		{
			if (!mlx_resize_image(rts->img, rts->width, rts->height))
			{
				ft_dprintf(STDERR_FILENO, "mlx_resize_image failure");
				cleaner(rts);
			}
			camera_portparse(rts->camera, rts->width, rts->height);
			if (render_scene(rts))
				cleaner(rts);
			rts->resize_time = 0;
		}
	}
}
