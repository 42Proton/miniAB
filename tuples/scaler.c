/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:07:54 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/14 21:52:02 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

t_tuple	*tuplesmult(t_tuple *a, float scale)
{
	t_tuple	*res;

	if (!a)
		return (NULL);
	res = malloc(sizeof(t_tuple));
	if (!res)
		return (NULL);
	res->x = a->x * scale;
	res->y = a->y * scale;
	res->z = a->z * scale;
	res->w = a->w;
	return (res);
}

t_tuple	*tuplesdiv(t_tuple *a, float scale)
{
	t_tuple	*res;

	if (!a)
		return (NULL);
	res = malloc(sizeof(t_tuple));
	if (!res)
		return (NULL);
	res->x = a->x / scale;
	res->y = a->y / scale;
	res->z = a->z / scale;
	res->w = a->w;
	return (res);
}

float	tuplemagnitude(t_tuple *a)
{
	float	res;

	if (!a)
		return (0);
	if (a->w == POINT)
		return (0);
	res = 0;
	res += a->x * a->x;
	res += a->y * a->y;
	res += a->z * a->z;
	res += a->w * a->w;
	res = sqrt(res);
	return (res);
}
