/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:37:37 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/04 15:58:59 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	cleaner(t_rtptr *rts, char *error)
{
	if (error)
		ft_dprintf(2, "%s\n", error);
	mlx_terminate(rts->mlx);
	exit(EXIT_SUCCESS);
}
