/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:37:37 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/04 22:18:25 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	cleaner(t_rtptr *rts, char *error)
{
	t_list	*tmp;

	if (error)
		ft_dprintf(2, "%s\n", error);
	if (rts->img)
		mlx_delete_image(rts->mlx, rts->img);
	// if (rts->mlx)
	mlx_terminate(rts->mlx);
	while (rts->objs)
	{
		tmp = rts->objs;
		rts->objs = rts->objs->next;
		if (tmp->content)
		{
			free(((t_object *)(tmp->content))->object);
			free(tmp->content);
		}
		free(tmp);
	}
	exit(EXIT_SUCCESS);
}
