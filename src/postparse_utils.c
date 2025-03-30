/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postparse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:32:31 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/30 20:52:25 by amsaleh          ###   ########.fr       */
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
