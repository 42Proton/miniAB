/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_threading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 03:29:18 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/24 23:15:32 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_error(t_rtptr *rts)
{
	pthread_mutex_lock(&rts->fail_mutex);
	rts->is_err = 1;
	pthread_mutex_unlock(&rts->fail_mutex);
}

int	check_error(t_rtptr *rts)
{
	int	res;

	pthread_mutex_lock(&rts->fail_mutex);
	if (rts->is_err)
		res = 1;
	else
		res = 0;
	pthread_mutex_unlock(&rts->fail_mutex);
	return (res);
}

void	render_section(t_thread_data *data)
{
	t_colors	color;
	int			x;
	int			y;

	y = 0;
	while (y < data->rts->height)
	{
		x = data->start_x;
		while (x < data->end_x)
		{
			color = scaled_ray(data->rts, x, y);
			if (check_error(data->rts))
				return ;
			mlx_put_pixel(data->rts->img, x, y, colorvalue(&color));
			x++;
		}
		y++;
	}
}

void	*thread_routine(void *arg)
{
	t_thread_data	*data;
	int				offset_x;

	data = arg;
	offset_x = data->rts->width / data->n_procs;
	data->start_x = data->t_num * offset_x;
	data->end_x = (data->t_num + 1) * offset_x;
	render_section(data);
	return (0);
}

void	prep_threads_data(t_rtptr *rts)
{
	int	i;

	i = 0;
	while (i < rts->n_procs)
	{
		rts->t_data[i].rts = rts;
		rts->t_data[i].n_procs = rts->n_procs;
		rts->t_data[i].t_num = i;
		i++;
	}
}
