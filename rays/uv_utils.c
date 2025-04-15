/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:57:07 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/15 22:57:22 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_uv	compute_plane_uv(t_plane *obj, t_tuple *p)
{
	t_uv			uv;
	mlx_texture_t	*ref;
	float			aspect_r;

	ref = obj->color_map_ref;
	aspect_r = (float)ref->width / ref->height;
	uv.u = p->x * (aspect_r * 0.05);
	if (obj->normal_vector->z > EPSILON)
		uv.v = p->y * (aspect_r * 0.05);
	else
		uv.v = p->z * (aspect_r * 0.05);
	uv.u = fmod(uv.u - floorf(uv.u), 1);
	uv.v = fmod(uv.v - floorf(uv.v), 1);
	return (uv);
}

t_uv	compute_sphere_uv(t_sphere *obj, t_computes *comps)
{
	t_uv	uv;
	t_tuple	nv;

	nv = comps->nv;
	uv.u = (asin(nv.x) / M_PI) + 0.5;
	uv.v = (asin(-nv.y) / M_PI) + 0.5;
	return (uv);
}

t_uv	compute_hyper_uv(t_hyper *obj, t_tuple *p)
{
	t_tuple			inv_p;
	t_uv			uv;
	mlx_texture_t	*ref;
	float			aspect_r;

	inv_p = transform_f(obj->inv_t, p);
	ref = obj->color_map_ref;
	aspect_r = (float)ref->width / ref->height;
	uv.u = (inv_p.x / obj->coeffs->x) * (aspect_r * 0.05);
	uv.v = (inv_p.z / obj->coeffs->z) * (aspect_r * 0.05);
	uv.u = fmod(uv.u - floorf(uv.u), 1);
	uv.v = fmod(uv.v - floorf(uv.v), 1);
	return (uv);
}
