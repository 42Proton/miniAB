/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_uv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 05:54:37 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/26 05:55:28 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_disk_uv(t_uv *uv,
	t_cylinder *obj, t_tuple *p, int aspect_r)
{
	if (!floatcmp(obj->normal_axis->x, 0))
	{
		uv->u = p->z * (aspect_r * 0.05);
		uv->v = p->y * (aspect_r * 0.05);
	}
	else if (!floatcmp(obj->normal_axis->z, 0))
	{
		uv->u = p->x * (aspect_r * 0.05);
		uv->v = p->y * (aspect_r * 0.05);
	}
	else
	{
		uv->u = p->z * (aspect_r * 0.05);
		uv->v = p->x * (aspect_r * 0.05);
	}
}

t_uv	compute_disk_uv(t_cylinder *obj, t_tuple *p)
{
	t_uv			uv;
	mlx_texture_t	*ref;
	float			aspect_r;

	ref = obj->color_map_ref;
	if (ref)
		aspect_r = (float)ref->width / ref->height;
	else
		aspect_r = 1;
	set_disk_uv(&uv, obj, p, aspect_r);
	uv.u = fmod(uv.u - floorf(uv.u), 1);
	uv.v = fmod(uv.v - floorf(uv.v), 1);
	return (uv);
}
