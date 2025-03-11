/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:13:10 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/08 18:26:32 by amsaleh          ###   ########.fr       */
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