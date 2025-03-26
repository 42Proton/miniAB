/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postparse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:32:31 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/26 03:55:36 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	sphere_postparse(t_rtptr *rts, t_sphere *obj)
{
	t_alight	*alight;
	int			res;

	alight = rts->alight;
	obj->mat.ambient = colormulti_f(alight->colors, alight->ratio);
	res = sphere_transform_m(obj);
	return (res);
}

int	plane_postparse(t_rtptr *rts, t_plane *obj)
{
	t_alight	*alight;
	int			res;

	alight = rts->alight;
	obj->mat.ambient = colormulti_f(alight->colors, alight->ratio);
	res = plane_transform_m(obj);
	return (res);
}

int	cylinder_postparse(t_rtptr *rts, t_cylinder *obj)
{
	t_alight	*alight;
	int			res;

	alight = rts->alight;
	obj->mat.ambient = colormulti_f(alight->colors, alight->ratio);
	res = cylinder_transform_m(obj);
	return (res);
}
