/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:37:37 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/07 00:38:23 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	free_sphere(t_sphere *sphere)
{
	free(sphere->pos);
	free(sphere->colors);
	free(sphere);
}

void	free_plane(t_plane *plane)
{
	free(plane->pos);
	free(plane->normal_vector);
	free(plane->colors);
	free(plane);
}

void	free_cylinder(t_cylinder *cylinder)
{
	free(cylinder->pos);
	free(cylinder->normal_axis);
	free(cylinder->colors);
	free(cylinder);
}

void	object_cleanup(void *content)
{
	t_object_entry	*entry;

	entry = (t_object_entry *)content;
	if (entry)
	{
		if (entry->type == SPHERE)
			free_sphere(entry->object);
		else if (entry->type == PLANE)
			free_plane(entry->object);
		else if (entry->type == CYLINDER)
			free_cylinder(entry->object);
	}
	free(content);
}

void	cleaner(t_rtptr *rts)
{
	if (rts->img)
		mlx_delete_image(rts->mlx, rts->img);
	if (rts->mlx)
		mlx_terminate(rts->mlx);
	ft_lstclear(&rts->objs, object_cleanup);
	exit(EXIT_SUCCESS);
}
