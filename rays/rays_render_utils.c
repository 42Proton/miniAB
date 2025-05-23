/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:13:10 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/26 03:58:31 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_colors	get_insect_color(t_rtptr *rts,
	t_intersections *insects, t_ray *ray, int depth)
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
			set_error(rts);
			return (res);
		}
		res = shade_hit(rts, &comp, depth);
		if (comp.is_err)
		{
			set_error(rts);
			return (res);
		}
	}
	else
		res = colorinit((ft_fabs(ray->direction.y) * 0.2)
				* rts->alight->ratio, rts->alight->ratio, rts->alight->ratio);
	return (res);
}

t_colors	ray_color(t_rtptr *rts, t_ray *ray, int depth)
{
	t_colors		res;
	t_intersections	*insects;

	res = color_black();
	if (depth == REFLECT_MAX_DEPTH)
		return (res);
	insects = world_intersect(rts->solid_objs, ray);
	if (!insects)
	{
		set_error(rts);
		return (res);
	}
	res = get_insect_color(rts, insects, ray, depth);
	clear_intersections(insects);
	return (res);
}
