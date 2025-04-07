/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:43:40 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/07 21:38:38 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	is_shadow(t_rtptr *rts, t_tuple *p)
{
	t_shadow	data;

	data.vision_objs = rts->vision_objs;
	while (data.vision_objs)
	{
		data.light = ((t_object_entry *)data.vision_objs->content)->object;
		data.v = n_tuplesub(data.light->pos, p);
		data.dist = tuplemagnitude(&data.v);
		data.direction = tuplenormalize(&data.v);
		data.ray = init_ray(p, &data.direction);
		data.insects = world_intersect(rts->solid_objs, &data.ray);
		if (!data.insects)
			return (-1);
		data.insect = get_hit(data.insects);
		if (data.insect && data.insect->t < data.dist)
		{
			clear_intersections(data.insects);
			return (1);
		}
		clear_intersections(data.insects);
		data.vision_objs = data.vision_objs->next;
	}
	return (0);
}
