/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:42:32 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/24 23:24:38 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

time_t	get_timestamp(void)
{
	struct timeval	time;
	time_t			timestamp;

	gettimeofday(&time, 0);
	timestamp = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (timestamp);
}

void	keyhook(struct mlx_key_data keydata, void *rtptr)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		cleaner(rtptr);
}

void	scrollhook(int width, int height, void *rtptr)
{
	t_rtptr			*rts;

	rts = rtptr;
	rts->width = width;
	rts->height = height;
	rts->scroll_time = get_timestamp();
}

void	generichook(void *rtptr)
{
	t_rtptr	*rts;

	rts = rtptr;
	if (rts->scroll_time)
	{
		if (get_timestamp() > rts->scroll_time)
		{
			rts->scroll_time = 0;
			if (!mlx_resize_image(rts->img, rts->width, rts->height))
			{
				ft_dprintf(STDERR_FILENO, "mlx_resize_image failure");
				cleaner(rts);
			}
			if (render_scene(rts))
				cleaner(rts);
		}
	}
}
