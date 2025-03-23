/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:56:13 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/23 03:10:21 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

t_tuple	transform_f(t_matrix *m, t_tuple *vec)
{
	t_tuple res;

	ft_bzero(&res, sizeof(t_tuple));
	if (!m || !vec || vec->w == VECTOR)
		return (res);
	res.x = vec->x * m->data[0] + vec->y * m->data[1] + vec->z * m->data[2];
	res.y = vec->x * m->data[3] + vec->y * m->data[4] + vec->z * m->data[5];
	res.z = vec->x * m->data[6] + vec->y * m->data[7] + vec->z * m->data[8];
	res.w = vec->w;
	return (res);
}
