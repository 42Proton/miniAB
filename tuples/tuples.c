/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:29:01 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/14 21:52:51 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

t_tuple	*point(float x, float y, float z)
{
	t_tuple	*pnt;

	pnt = malloc(sizeof(struct s_tuple));
	if (!pnt)
		return (NULL);
	pnt->x = x;
	pnt->y = y;
	pnt->z = z;
	pnt->w = POINT;
	return (pnt);
}

t_tuple	*vector(float x, float y, float z)
{
	t_tuple	*vec;

	vec = malloc(sizeof(struct s_tuple));
	if (!vec)
		return (NULL);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	vec->w = VECTOR;
	return (vec);
}
