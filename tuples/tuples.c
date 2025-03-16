/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:29:01 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/17 01:48:19 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

t_tuple	point(float x, float y, float z)
{
	t_tuple	pnt;

	pnt.x = x;
	pnt.y = y;
	pnt.z = z;
	pnt.w = POINT;
	return (pnt);
}

t_tuple	vector(float x, float y, float z)
{
	t_tuple	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = VECTOR;
	return (vec);
}
