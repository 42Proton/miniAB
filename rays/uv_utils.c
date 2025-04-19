/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:57:07 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/19 19:10:10 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

// All the following uv function was obtained
// By solving the parameterized representation
// of surfaces for u and v
t_uv	compute_plane_uv(t_plane *obj, t_tuple *p)
{
	t_uv			uv;
	mlx_texture_t	*ref;
	float			aspect_r;

	ref = obj->color_map_ref;
	if (ref)
		aspect_r = (float)ref->width / ref->height;
	else
		aspect_r = 1;
	if (!floatcmp(obj->normal_vector->x, 0))
	{
		uv.u = p->z * (aspect_r * 0.05);
		uv.v = p->y * (aspect_r * 0.05);
	}
	else if (!floatcmp(obj->normal_vector->z, 0))
	{
		uv.u = p->x * (aspect_r * 0.05);
		uv.v = p->y * (aspect_r * 0.05);
	}
	else
	{
		uv.u = p->x * (aspect_r * 0.05);
		uv.v = p->z * (aspect_r * 0.05);
	}
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
	uv.v = (asin(nv.y) / M_PI) + 0.5;
	return (uv);
}

t_uv	compute_hyper_uv(t_hyper *obj, t_tuple *p)
{
	t_uv			uv;
	t_tuple			inv_p;

	inv_p = transform_f(obj->inv_t, p);
	uv.u = atan(obj->coeffs->x / obj->coeffs->z
		* inv_p.z / inv_p.x);
	if (uv.u < 0)
		uv.u += 2 * M_PI;
	uv.v = asinh(inv_p.y / obj->coeffs->y);
	uv.u /= 2 * M_PI;
	uv.v = fmod(uv.v - floorf(uv.v), 1);
	return (uv);
}
