/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:07:54 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/24 22:13:16 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>
#include <stdio.h>

void	tuplesmult(t_tuple *a, float scale)
{
	a->x = a->x * scale;
	a->y = a->y * scale;
	a->z = a->z * scale;
}

void	tuplesdiv(t_tuple *a, float scale)
{
	a->x = a->x / scale;
	a->y = a->y / scale;
	a->z = a->z / scale;
}

float	tuplemagnitude(t_tuple *a)
{
	float	res;

	if (a->w == POINT)
		return (0);
	res = 0;
	res += a->x * a->x;
	res += a->y * a->y;
	res += a->z * a->z;
	res = sqrtf(res);
	return (res);
}

float	tuplemag2(t_tuple *a)
{
	float	res;

	if (a->w == POINT)
		return (0);
	res = 0;
	res += a->x * a->x;
	res += a->y * a->y;
	res += a->z * a->z;
	return (res);
}
