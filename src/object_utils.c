/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 00:06:15 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/23 04:02:28 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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
		if (entry->type < CAMERA)
			ft_move_lst(tmp, &rts->vision_objs);
		else if (entry->type > CAMERA)
			ft_move_lst(tmp, &rts->solid_objs);
		else if (entry->type == CAMERA)
		{
			rts->camera = entry->object;
			free(entry);
			free(tmp);
		}
		tmp = tmp_next;
	}
	rts->objs = 0;
}
