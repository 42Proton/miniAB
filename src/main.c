/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/14 14:41:02 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>
#include <minirt.h>



int	main(int ac, char **av)
{
	t_rtptr		rts;

	if (prep_rt_core(ac, av, &rts))
		cleaner(&rts);
	if (init_mlx(&rts))
		cleaner(&rts);
	render_viewport(&rts);
	mlx_image_to_window(rts.mlx, rts.img, 0, 0);
	mlx_key_hook(rts.mlx, keyhook, &rts);
	mlx_loop(rts.mlx);
	cleaner(&rts);
	return (0);
}
