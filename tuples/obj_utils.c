/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:30:31 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/14 21:53:39 by amsaleh          ###   ########.fr       */
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

t_tuple	*tupleadd(t_tuple *a, t_tuple *b)
{
	t_tuple	*res;

	if (!a || !b)
		return (NULL);
	if (a->w + b->w > 1)
		return (NULL);
	res = malloc(sizeof(t_tuple));
	if (!res)
		return (NULL);
	res->x = a->x + b->x;
	res->y = a->y + b->y;
	res->z = a->z + b->z;
	res->w = a->w + b->w;
	return (res);
}

t_tuple	*tuplesub(t_tuple *a, t_tuple *b)
{
	t_tuple	*res;

	if (!a || !b)
		return (NULL);
	res = malloc(sizeof(t_tuple));
	if (!res)
		return (NULL);
	res->x = a->x - b->x;
	res->y = a->y - b->y;
	res->z = a->z - b->z;
	res->w = a->w - b->w;
	return (res);
}

t_tuple	*tuplenegt(t_tuple *a)
{
	t_tuple	*res;

	if (!a)
		return (NULL);
	res = malloc(sizeof(t_tuple));
	if (!res)
		return (NULL);
	res->x = -a->x;
	res->y = -a->y;
	res->z = -a->z;
	res->w = -a->w;
	return (res);
}
