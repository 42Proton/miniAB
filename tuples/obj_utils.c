/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:30:31 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/26 22:55:28 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

int	floatcmp(float a, float b)
{
	if (ft_fabs(a - b) < EPSILON)
		return (1);
	else
		return (0);
}

t_tuple	tuplenegt(t_tuple *a)
{
	t_tuple	res;

	ft_bzero(&res, sizeof(t_tuple));
	res.x = -a->x;
	res.y = -a->y;
	res.z = -a->z;
	res.w = a->w;
	return (res);
}
