/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:13:10 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/10 06:56:36 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	check_args(int argc, char **argv)
{
	char	*ptr;

	if (argc != 2)
	{
		simple_report(ERR_ARGS_COUNT);
		return (EXIT_FAILURE);
	}
	ptr = ft_strchr(argv[1], '.');
	if (!ptr || ft_strncmp(ptr, ".rt", 4))
	{
		simple_report(ERR_FILE_EXT);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_mlx(t_rtptr *rts)
{
	rts->mlx = mlx_init(wid_res, heg_res, "miniAB", false);
	if (!rts->mlx)
		return (EXIT_FAILURE);
	rts->img = mlx_new_image(rts->mlx, wid_res, heg_res);
	if (!rts->img)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
