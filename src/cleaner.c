/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:37:37 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/06 00:07:24 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	object_cleanup(void *content)
{
	if (((t_object *)content))
		free(((t_object *)content)->object);
	// TODO: Cleaner Switch to free each object as it's type
	free(content);
}

void	cleaner(t_rtptr *rts, char *error)
{
	if (error)
		ft_dprintf(2, "%s\n", error);
	if (rts->img)
		mlx_delete_image(rts->mlx, rts->img);
	if (rts->mlx)
		mlx_terminate(rts->mlx);
	ft_lstclear(&rts->objs, object_cleanup);
	exit(EXIT_SUCCESS);
}
