/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/04 16:13:33 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	main(int argc, char **argv)
{
	t_rtptr	rts;

	ft_bzero(&rts, sizeof(t_rtptr));
	if (check_args(argc, argv))
	{
		ft_dprintf(2, "Invalid Args");
		return (EXIT_FAILURE);
	}
	if (init_mlx_pointers(&rts) || parser(argv[1], &rts))
		cleaner(&rts, "STARTUP ERROR");
	mlx_key_hook(rts.mlx, keyhook, &rts);
	mlx_loop(rts.mlx);
	mlx_terminate(rts.mlx);
	return (0);
}
