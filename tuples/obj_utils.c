/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:30:31 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/17 23:11:56 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

int	floatcmp(float a, float b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	else
		return (0);
}

int	tuplecmp(t_tuple *a, t_tuple *b)
{
	if (!a || !b)
		return (0);
	if (floatcmp(a->x, b->x) && floatcmp(a->y, b->y) && floatcmp(a->z, b->z)
		&& floatcmp(a->w, b->w))
		return (1);
	else
		return (0);
}

void	tupleadd(t_tuple *a, t_tuple *b)
{

	if (a->w + b->w > 1)
		return;
	a->x = a->x + b->x;
	a->y = a->y + b->y;
	a->z = a->z + b->z;
	a->w = a->w + b->w;
}

void	tuplesub(t_tuple *a, t_tuple *b)
{
	if (!a || !b)
		return ;
	a->x = a->x - b->x;
	a->y = a->y - b->y;
	a->z = a->z - b->z;
	a->w = a->w - b->w;
}

t_tuple	tuplenegt(t_tuple *a)
{
	t_tuple	res;

	ft_bzero(&res, sizeof(t_tuple));
	if (!a)
		return (res);
	res.x = -a->x;
	res.y = -a->y;
	res.z = -a->z;
	res.w = a->w;
	return (res);
}
