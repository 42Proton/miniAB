/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   products.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:14:02 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/24 22:11:35 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>
#include <libft.h>

t_tuple	tuplecross(t_tuple *a, t_tuple *b)
{
	t_tuple	res;

	res.x = a->y * b->z - b->y * a->z;
	res.y = a->z * b->x - b->z * a->x;
	res.z = a->x * b->y - b->x * a->y;
	return (res);
}

float	tupledot(t_tuple *a, t_tuple *b)
{
	float	res;

	res = a->x * b->x;
	res += a->y * b->y;
	res += a->z * b->z;
	return (res);
}
