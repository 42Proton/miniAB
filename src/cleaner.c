/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:37:37 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/07 21:17:55 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	cleaner(t_rtptr *rts, char *error)
{
	ft_dprintf(2, "%s\n", error);
	if (rts->win)
		mlx_destroy_window(rts->mlx, rts->win);
	if (rts->mlx)
		mlx_destroy_display(rts->mlx);
	free(rts->mlx);
	exit(EXIT_SUCCESS);
}
