/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_utils_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:01:13 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/17 03:00:47 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

t_tuple	n_tuplesub(t_tuple *a, t_tuple *b)
{
	t_tuple	res;

	ft_bzero(&res, sizeof(t_tuple));
	if (!a || !b)
		return (res);
	res.x = a->x - b->x;
	res.y = a->y - b->y;
	res.z = a->z - b->z;
	res.w = a->w - b->w;
	return (res);
}

t_tuple	n_tupleadd(t_tuple *a, t_tuple *b)
{
	t_tuple	res;

	ft_bzero(&res, sizeof(t_tuple));
	if (!a || !b)
		return (res);
	if (a->w + b->w > 1)
		return (res);
	res.x = a->x + b->x;
	res.y = a->y + b->y;
	res.z = a->z + b->z;
	res.w = a->w + b->w;
	return (res);
}

t_tuple	n_tuplesdiv(t_tuple *a, float scale)
{
	t_tuple	res;

	ft_bzero(&res, sizeof(t_tuple));
	if (!a)
		return (res);
	res.x = a->x / scale;
	res.y = a->y / scale;
	res.z = a->z / scale;
	res.w = a->w;
	return (res);
}

t_tuple	n_tuplesmult(t_tuple *a, float scale)
{
	t_tuple	res;

	ft_bzero(&res, sizeof(t_tuple));
	if (!a)
		return (res);
	res.x = a->x * scale;
	res.y = a->y * scale;
	res.z = a->z * scale;
	res.w = a->w;
	return (res);
}