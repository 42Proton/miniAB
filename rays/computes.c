/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 08:22:16 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/11 21:53:57 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_colors	get_pixel_color(mlx_texture_t *texture, t_uv *uv)
{
	t_colors	res;
	size_t		offset;
	int			width;
	int			height;

	width = texture->width - 1;
	height = texture->height - 1;
	offset = ((int)roundf(uv->v * height) * texture->width + (int)roundf(uv->u * width)) * 4;
	res.red = (float)texture->pixels[offset] / 255;
	res.green = (float)texture->pixels[offset + 1] / 255;
	res.blue = (float)texture->pixels[offset + 2] / 255;
	return (res);
}

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
	uv.v = (asin(nv.y) / M_PI) + 0.5;
	return (uv);
}

t_colors	get_map_color(void *obj, int obj_type, t_computes *comps)
{
	t_colors		res;
	t_uv			uv;
	mlx_texture_t	*ref;

	res = colorinit(0, 0, 0);
	ref = 0;
	if (obj_type == PLANE && ((t_plane *)obj)->color_map_ref)
	{
		uv = compute_plane_uv(obj, &comps->hpoint);
		ref = ((t_plane *)obj)->color_map_ref;
	}
	if (obj_type == SPHERE && ((t_sphere *)obj)->color_map_ref)
	{
		uv = compute_sphere_uv(obj, comps);
		ref = ((t_sphere *)obj)->color_map_ref;
	}
	if (ref)
		res = get_pixel_color(ref, &uv);
	return (res);
}

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
	comps.map_color = get_map_color(insect->obj, insect->obj_type, &comps);
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
