/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:43:40 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/12 12:30:37 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	prep_shadow_data(t_rtptr *rts, t_shadow *data, t_tuple *p)
{
	data->light = ((t_object_entry *)data->vision_objs->content)->object;
	data->v = n_tuplesub(data->light->pos, p);
	data->dist = tuplemagnitude(&data->v);
	data->direction = tuplenormalize(&data->v);
	data->ray = init_ray(p, &data->direction);
	data->insects = world_intersect(rts->solid_objs, &data->ray);
	if (!data->insects)
		return (0);
	return (1);
}

int	is_shadow(t_rtptr *rts, t_tuple *p)
{
	t_shadow	data;
	int			is_insect;

	data.vision_objs = rts->vision_objs;
	is_insect = 0;
	while (data.vision_objs)
	{
		if (!prep_shadow_data(rts, &data, p))
			return (-1);
		data.insect = get_hit(data.insects);
		if (data.insect && data.insect->t < data.dist)
			is_insect = 1;
		else
		{
			clear_intersections(data.insects);
			return (0);
		}
		clear_intersections(data.insects);
		data.vision_objs = data.vision_objs->next;
	}
	return (is_insect);
}
