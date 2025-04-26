/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 23:18:27 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/21 19:55:43 by amsaleh          ###   ########.fr       */
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
	offset = ((int)roundf((1 - uv->v) * height) * texture->width
			+ (int)roundf(uv->u * width)) * 4;
	res.red = (float)texture->pixels[offset] / 255;
	res.green = (float)texture->pixels[offset + 1] / 255;
	res.blue = (float)texture->pixels[offset + 2] / 255;
	return (res);
}

t_colors	get_map_color(void *obj, int obj_type, t_computes *comps)
{
	t_colors		res;
	mlx_texture_t	*ref;

	res = color_black();
	ref = 0;
	if (obj_type == PLANE && ((t_plane *)obj)->color_map_ref)
		ref = ((t_plane *)obj)->color_map_ref;
	else if (obj_type == SPHERE && ((t_sphere *)obj)->color_map_ref)
		ref = ((t_sphere *)obj)->color_map_ref;
	else if (obj_type == CYLINDER && ((t_cylinder *)obj)->color_map_ref)
		ref = ((t_cylinder *)obj)->color_map_ref;
	else if (obj_type == HYPER && ((t_hyper *)obj)->color_map_ref)
		ref = ((t_hyper *)obj)->color_map_ref;
	if (ref)
		res = get_pixel_color(ref, &comps->uv);
	return (res);
}

t_uv	get_uv_coords(void *obj, int obj_type, t_computes *comps)
{
	t_uv	uv;

	ft_bzero(&uv, sizeof(&uv));
	if (obj_type == PLANE && ((t_plane *)obj)->color_map_ref)
		uv = compute_plane_uv(obj, &comps->hpoint);
	else if (obj_type == SPHERE && ((t_sphere *)obj)->color_map_ref)
		uv = compute_sphere_uv(comps);
	else if (obj_type == CYLINDER && ((t_cylinder *)obj)->color_map_ref)
		uv = compute_cylinder_uv(obj, &comps->hpoint);
	else if (obj_type == HYPER && ((t_hyper *)obj)->color_map_ref)
		uv = compute_hyper_uv(obj, &comps->hpoint);
	return (uv);
}

mlx_texture_t	*get_bump_ref(void *obj, int obj_type)
{
	mlx_texture_t	*ref;

	ref = 0;
	if (obj_type == PLANE && ((t_plane *)obj)->bump_map_ref)
		ref = ((t_plane *)obj)->bump_map_ref;
	else if (obj_type == SPHERE && ((t_sphere *)obj)->bump_map_ref)
		ref = ((t_sphere *)obj)->bump_map_ref;
	else if (obj_type == CYLINDER && ((t_sphere *)obj)->bump_map_ref)
		ref = ((t_cylinder *)obj)->bump_map_ref;
	else if (obj_type == HYPER && ((t_hyper *)obj)->bump_map_ref)
		ref = ((t_hyper *)obj)->bump_map_ref;
	return (ref);
}
