/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postparse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:32:31 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/24 23:23:28 by amsaleh          ###   ########.fr       */
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
	int		res;
	t_tuple	*coeffs;

	coeffs = obj->coeffs;
	if (obj->color_map)
		obj->color_map_ref = get_texture_ref(obj->color_map, rts);
	if (obj->bump_map)
		obj->bump_map_ref = get_texture_ref(obj->bump_map, rts);
	obj->coeffs2 = point(coeffs->x * coeffs->x,
			coeffs->y * coeffs->y, coeffs->z * coeffs->z);
	res = hyper_transform_m(obj);
	return (res);
}

void	camera_portparse(t_camera *obj, int width, int height)
{
	float	hview;
	float	aspect;

	hview = tan(deg_to_rad(obj->fov) / 2);
	obj->origin = point(0, 0, 0);
	obj->origin = transform_f(obj->inv_t, &obj->origin);
	aspect = (float)width / height;
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
	obj->pixel_size = (obj->hwidth * 2) / width;
}
