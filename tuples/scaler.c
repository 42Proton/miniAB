/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:07:54 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/17 22:34:42 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>
#include <stdio.h>

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
	res = sqrt(res);
	return (res);
}

t_tuple	unit_vector(t_tuple *a)
{
	t_tuple	res;
	float	magnitude;

	ft_bzero(&res, sizeof(t_tuple));
	if (!a)
		return (res);
	magnitude = tuplemagnitude(a);
	res = n_tuplesdiv(a, magnitude);
	return (res);
}
