/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 00:06:15 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/30 00:04:23 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	split_cam_alight(t_rtptr *rts,
	t_list *tmp, t_object_entry *entry)
{
	if (entry->type == CAMERA)
		rts->camera = entry->object;
	else
		rts->alight = entry->object;
	free(entry);
	if (tmp->next)
		tmp->next->prev = 0;
	free(tmp);
}

void	split_objs(t_rtptr *rts)
{
	t_list			*tmp;
	t_list			*tmp_next;
	t_object_entry	*entry;

	tmp = rts->objs;
	while (tmp)
	{
		tmp_next = tmp->next;
		entry = (t_object_entry *)tmp->content;
		if (entry->type == AMBIENTLIGHT)
			split_cam_alight(rts, tmp, entry);
		else if (entry->type < CAMERA)
			ft_move_lst(tmp, &rts->vision_objs);
		else if (entry->type > CAMERA)
			ft_move_lst(tmp, &rts->solid_objs);
		else if (entry->type == CAMERA)
			split_cam_alight(rts, tmp, entry);
		tmp = tmp_next;
	}
	rts->objs = 0;
}
