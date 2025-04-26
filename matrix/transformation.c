/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:56:13 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/26 23:00:01 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>

t_tuple	transform_f(t_matrix *m, t_tuple *vec)
{
	t_tuple	res;

	ft_bzero(&res, sizeof(t_tuple));
	if (!m || !vec)
		return (res);
	res.x = vec->x * m->data[0] + vec->y * m->data[1]
		+ vec->z * m->data[2] + vec->w * m->data[3];
	res.y = vec->x * m->data[4] + vec->y * m->data[5]
		+ vec->z * m->data[6] + vec->w * m->data[7];
	res.z = vec->x * m->data[8] + vec->y * m->data[9]
		+ vec->z * m->data[10] + vec->w * m->data[11];
	res.w = vec->x * m->data[12] + vec->y * m->data[13]
		+ vec->z * m->data[14] + vec->w * m->data[15];
	return (res);
}

int	check_if_scale_m(t_matrix *m)
{
	if (!floatcmp(m->data[0], 1) || !floatcmp(m->data[5], 1)
		|| !floatcmp(m->data[10], 1))
		return (1);
	return (0);
}

t_ray	transform_ray(t_matrix *m, t_ray *ray)
{
	t_ray		res;

	ft_bzero(&res, sizeof(t_ray));
	if (!m || !ray)
		return (res);
	res.origin = transform_f(m, &ray->origin);
	res.direction = transform_f(m, &ray->direction);
	if (!check_if_scale_m(m))
		res.direction = tuplenormalize(&res.direction);
	return (res);
}
