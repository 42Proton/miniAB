/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_threading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 03:29:18 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/19 03:52:48 by amsaleh          ###   ########.fr       */
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

	y = data->start_y;
	while (y < data->end_y)
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

// Have to work on handling case when proccessors count is odd
void	*thread_routine(void *arg)
{
	t_thread_data	*data;
	int				offset_x;
	int				offset_y;
	int				x_mod;
	float			y_factor;

	data = arg;
	x_mod = data->n_procs / 2;
	y_factor = 2.0f / data->n_procs;
	offset_x = WID / (data->n_procs / 2);
	offset_y = HEG / 2;
	data->start_x = offset_x * (data->t_num % x_mod);
	data->start_y = offset_y * (int)(data->t_num * y_factor);
	data->end_x = (offset_x * (data->t_num % x_mod)) + offset_x;
	data->end_y = offset_y * ((int)(data->t_num * y_factor) + 1);
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
