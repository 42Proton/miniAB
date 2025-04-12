/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postparse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:32:31 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/12 17:44:04 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	sphere_postparse(t_rtptr *rts, t_sphere *obj)
{
	int	res;

	if (obj->color_map)
		obj->color_map_ref = get_texture_ref(obj->color_map, rts);
	if (obj->bump_map)
		obj->bump_map_ref = get_texture_ref(obj->bump_map, rts);
	res = sphere_transform_m(obj);
	return (res);
}

int	plane_postparse(t_rtptr *rts, t_plane *obj)
{
	int	res;

	if (obj->color_map)
		obj->color_map_ref = get_texture_ref(obj->color_map, rts);
	if (obj->bump_map)
		obj->bump_map_ref = get_texture_ref(obj->bump_map, rts);
	res = plane_transform_m(obj);
	return (res);
}

int	cylinder_postparse(t_rtptr *rts, t_cylinder *obj)
{
	int	res;

	if (obj->color_map)
		obj->color_map_ref = get_texture_ref(obj->color_map, rts);
	if (obj->bump_map)
		obj->bump_map_ref = get_texture_ref(obj->bump_map, rts);
	res = cylinder_transform_m(obj);
	return (res);
}

int	hyper_postparse(t_rtptr *rts, t_hyper *obj)
{
	int	res;

	if (obj->color_map)
		obj->color_map_ref = get_texture_ref(obj->color_map, rts);
	if (obj->bump_map)
		obj->bump_map_ref = get_texture_ref(obj->bump_map, rts);
	res = hyper_transform_m(obj);
	return (res);
}

int	camera_portparse(t_camera *obj)
{
	float	hview;
	float	aspect;

	if (!camera_transform_m(obj))
		return (0);
	hview = tan(deg_to_rad(obj->fov) / 2);
	aspect = (float)WID / (float)HEG;
	if (aspect >= 1)
	{
		obj->hwidth = hview;
		obj->hheight = hview / aspect;
	}
	else
	{
		obj->hwidth = hview * aspect;
		obj->hheight = hview;
	}
	obj->pixel_size = (obj->hwidth * 2) / WID;
	return (1);
}
