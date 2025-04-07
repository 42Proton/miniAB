/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 08:22:16 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/07 21:47:39 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_computes	init_computes(t_rtptr *rts,
		t_intersect *insect, t_ray *ray)
{
	t_computes	comps;
	float		dot_nv_e;

	comps.is_err = 0;
	comps.insect = insect;
	comps.hpoint = ray_hitpoint(ray, insect->t);
	comps.eyev = tuplenegt(&ray->direction);
	comps.nv = normal_at(insect->obj, insect->obj_type, &comps.hpoint);
	dot_nv_e = tupledot(&comps.nv, &comps.eyev);
	if (dot_nv_e < 0)
		comps.nv = tuplenegt(&comps.nv);
	comps.eyev = tuplenormalize(&comps.eyev);
	// Computations of shadow intersections
	// The reason in here we are not checking the direct hpoint
	// and we are using shifted point instead is because
	// We can't represent the start point with infintie precision
	// Which causes self intersection to prevent that we shift the point
	// With artifical value called shadow bias which solves the issue
	comps.over_point = n_tuplesmult(&comps.nv, SHADOW_BIAS);
	comps.over_point = n_tupleadd(&comps.over_point, &comps.hpoint);
	comps.is_shadow = is_shadow(rts, &comps.over_point);
	if (comps.is_shadow == -1)
		comps.is_err = 1;
	return (comps);
}
