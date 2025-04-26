/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:16:48 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/27 00:08:32 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	spawn_threads(t_rtptr *rts)
{
	int	i;

	i = 0;
	while (i < rts->n_procs)
	{
		if (pthread_create(&rts->threads[i],
				0, thread_routine, &rts->t_data[i]))
		{
			ft_dprintf(STDERR_FILENO, "pthread_create failure\n");
			set_error(rts);
			i--;
			while (i > -1)
			{
				pthread_join(rts->threads[i], 0);
				i--;
			}
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	render_scene(t_rtptr *rts)
{
	int	i;

	i = -1;
	if (!prep_threads_data(rts))
		return (EXIT_FAILURE);
	if (spawn_threads(rts))
		return (EXIT_FAILURE);
	while (++i < rts->n_procs)
		pthread_join(rts->threads[i], 0);
	if (check_error(rts))
	{
		ft_dprintf(STDERR_FILENO, "Error occured in a thread\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
