/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postparse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:32:31 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/31 14:36:33 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	sphere_postparse(t_rtptr *rts, t_sphere *obj)
{
	int	res;

	res = sphere_transform_m(obj);
	return (res);
}

int	plane_postparse(t_rtptr *rts, t_plane *obj)
{
	int	res;

	res = plane_transform_m(obj);
	return (res);
}

int	cylinder_postparse(t_rtptr *rts, t_cylinder *obj)
{
	int	res;

	res = cylinder_transform_m(obj);
	return (res);
}

int	camera_portparse(t_camera *obj)
{
	int		res;
	float	hview;
	float	aspect;

	res = camera_transform_m(obj);
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
	return (res);
}
