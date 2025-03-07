/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:29:01 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/24 15:31:58 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

t_tuple	*point(float x, float y, float z)
{
	t_tuple	*pnt;

	pnt = malloc(sizeof(struct s_tuple));
	if (!pnt)
		return (NULL);
	pnt->X = x;
	pnt->X = x;
	pnt->Y = y;
	pnt->Z = z;
	pnt->W = POINT;
	return (pnt);
}
t_tuple	*vector(float x, float y, float z)
{
	t_tuple	*vec;

	vec = malloc(sizeof(struct s_tuple));
	if (!vec)
		return (NULL);
	vec->X = x;
	vec->Y = y;
	vec->Z = z;
	vec->W = VECTOR;
	return (vec);
}
