/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:13:10 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/14 14:30:39 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_colors	get_insect_color(t_rtptr *rts,
	t_intersections *insects, t_ray *ray)
{
	t_intersect		*insect;
	t_colors		res;
	t_computes		comp;

	ft_bzero(&res, sizeof(t_colors));
	insect = get_hit(insects);
	if (insect)
	{
		comp = init_computes(rts, insect, ray);
		if (comp.is_err)
		{
			rts->is_err = 1;
			return (res);
		}
		res = shade_hit(rts->alight, &comp, rts->vision_objs);
	}
	else
		res = colorinit(ft_fabs(ray->direction.y) * rts->alight->ratio, 0.8
				* rts->alight->ratio, 0.8 * rts->alight->ratio);
	return (res);
}

t_colors	ray_color(t_rtptr *rts, t_ray *ray)
{
	t_colors		res;
	t_intersections	*insects;

	insects = world_intersect(rts->solid_objs, ray);
	ft_bzero(&res, sizeof(t_colors));
	if (!insects)
	{
		rts->is_err = 1;
		clear_intersections(insects);
		return (res);
	}
	res = get_insect_color(rts, insects, ray);
	clear_intersections(insects);
	return (res);
}
