/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:37:37 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/26 03:55:19 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	object_cleanup(void *content)
{
	t_object_entry	*entry;

	entry = (t_object_entry *)content;
	if (entry)
	{
		if (entry->type == AMBIENTLIGHT)
			free_ambient(entry->object);
		else if (entry->type == LIGHT)
			free_light(entry->object);
		else if (entry->type == CAMERA)
			free_camera(entry->object);
		else if (entry->type == SPHERE)
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
	int	dummy;

	if (rts->img)
		mlx_delete_image(rts->mlx, rts->img);
	if (rts->mlx)
		mlx_terminate(rts->mlx);
	if (rts->objs)
		ft_lstclear(&rts->objs, object_cleanup);
	else
	{
		ft_lstclear(&rts->solid_objs, object_cleanup);
		ft_lstclear(&rts->vision_objs, object_cleanup);
		free_camera(rts->camera);
		free_ambient(rts->alight);
	}
	get_next_line(-1, 1, &dummy);
	exit(EXIT_SUCCESS);
}
