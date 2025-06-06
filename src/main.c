/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/27 00:16:38 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	main(int ac, char **av)
{
	t_rtptr		rts;

	if (prep_rt_core(ac, av, &rts))
		cleaner(&rts);
	if (init_mlx(&rts))
		cleaner(&rts);
	if (pthread_mutex_init(&rts.fail_mutex, 0))
	{
		ft_dprintf(STDERR_FILENO, "pthread_mutex_init failure\n");
		cleaner(&rts);
	}
	rts.is_mutex_init = 1;
	if (render_scene(&rts))
		cleaner(&rts);
	mlx_image_to_window(rts.mlx, rts.img, 0, 0);
	mlx_key_hook(rts.mlx, keyhook, &rts);
	mlx_resize_hook(rts.mlx, resizehook, &rts);
	mlx_loop_hook(rts.mlx, generichook, &rts);
	mlx_loop(rts.mlx);
	cleaner(&rts);
	return (0);
}
