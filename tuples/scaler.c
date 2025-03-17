/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:07:54 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/17 03:02:13 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

void	tuplesmult(t_tuple *a, float scale)
{
	if (!a)
		return ;
	a->x = a->x * scale;
	a->y = a->y * scale;
	a->z = a->z * scale;
}

void	tuplesdiv(t_tuple *a, float scale)
{
	if (!a)
		return ;
	a->x = a->x / scale;
	a->y = a->y / scale;
	a->z = a->z / scale;
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
