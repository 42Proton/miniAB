/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:13:10 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/04 15:59:38 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (EXIT_FAILURE);
	if (ft_strncmp(ft_strchr(argv[1], '.'), ".rt", 4))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_mlx_pointers(t_rtptr *rts)
{
        rts->mlx = mlx_init(WID, HEG, "miniAB", false);
        if (!rts->mlx)
                return (EXIT_FAILURE);
        rts->img = mlx_new_image(rts->mlx, WID, HEG);
        if (!rts->img)
        {
                mlx_terminate(rts->mlx);
                return (EXIT_FAILURE);
        }
        mlx_image_to_window(rts->mlx, rts->img, 0, 0);
        return (EXIT_SUCCESS);
}