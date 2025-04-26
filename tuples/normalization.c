/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:58:19 by bismail           #+#    #+#             */
/*   Updated: 2025/04/24 22:12:52 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

t_tuple	tuplenormalize(t_tuple *a)
{
	t_tuple	res;
	float	mag;

	mag = tuplemagnitude(a);
	if (!mag)
	{
		res = vector(0, 0, 0);
		return (res);
	}
	res.x = a->x / mag;
	res.y = a->y / mag;
	res.z = a->z / mag;
	res.w = VECTOR;
	return (res);
}
