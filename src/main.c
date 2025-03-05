/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/05 20:40:53 by abueskander      ###   ########.fr       */
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
	// mlx_loop(rts.mlx);
	cleaner(&rts, NULL);
	return (0);
}
