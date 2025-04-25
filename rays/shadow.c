/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:43:40 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/25 05:56:42 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	is_shadow(t_rtptr *rts, t_tuple *p, t_light	*light)
{
	t_shadow	data;
	int			res;

	data.light = light;
	res = 0;
	data.v = n_tuplesub(data.light->pos, p);
	data.dist = tuplemagnitude(&data.v);
	data.direction = tuplenormalize(&data.v);
	data.ray = init_ray(p, &data.direction);
	data.insects = world_intersect(rts->solid_objs, &data.ray);
	if (!data.insects)
		return (-1);
	data.insect = get_hit(data.insects);
	if (data.insect && data.insect->t < data.dist)
		res = 1;
	else
		res = 0;
	clear_intersections(data.insects);
	return (res);
}
