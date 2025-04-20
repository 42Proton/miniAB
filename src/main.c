/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/20 19:49:42 by amsaleh          ###   ########.fr       */
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

int	setup_threads(t_rtptr *rts)
{
	int	i;

	i = -1;
	rts->n_procs = get_nprocs();
	rts->threads = malloc(rts->n_procs * sizeof(pthread_t));
	rts->t_data = ft_calloc(rts->n_procs, sizeof(t_thread_data));
	if (!rts->threads || !rts->t_data)
	{
		perror("malloc");
		return (EXIT_FAILURE);
	}
	if (pthread_mutex_init(&rts->fail_mutex, 0))
	{
		ft_dprintf(STDERR_FILENO, "pthread_mutex_init failure\n");
		return (EXIT_FAILURE);
	}
	prep_threads_data(rts);
	if (spawn_threads(rts))
		return (EXIT_FAILURE);
	while (++i < rts->n_procs)
		pthread_join(rts->threads[i], 0);
	if (check_error(rts))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_rtptr		rts;

	if (prep_rt_core(ac, av, &rts))
		cleaner(&rts);
	if (init_mlx(&rts))
		cleaner(&rts);
	if (setup_threads(&rts))
		cleaner(&rts);
	mlx_image_to_window(rts.mlx, rts.img, 0, 0);
	mlx_key_hook(rts.mlx, keyhook, &rts);
	mlx_loop(rts.mlx);
	cleaner(&rts);
	return (0);
}
