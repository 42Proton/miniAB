/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:58:19 by bismail           #+#    #+#             */
/*   Updated: 2025/03/14 21:52:35 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

t_tuple	*tuplenormalize(t_tuple *a)
{
	t_tuple	*res;
	float	mag;

	res = malloc(sizeof(t_tuple));
	if (!res)
		return (NULL);
	mag = tuplemagnitude(a);
	if (!mag)
		return (NULL);
	res->x = a->x / mag;
	res->y = a->y / mag;
	res->z = a->z / mag;
	res->w = a->w;
	return (res);
}
