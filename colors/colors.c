/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:32:46 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/30 18:38:03 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>

t_colors	colorinit(float red, float green, float blue)
{
	t_colors	res;

	res.red = red;
	res.green = green;
	res.blue = blue;
	return (res);
}

u_int32_t	colorvalue(t_colors *a)
{
	int			res;
	u_int8_t	red;
	u_int8_t	green;
	u_int8_t	blue;

	if (!a)
		return (0);
	red = color_inrange(a->red);
	green = color_inrange(a->green);
	blue = color_inrange(a->blue);
	res = 0;
	res = res | (red << 24);
	res = res | (green << 16);
	res = res | (blue << 8);
	res = res | 0xFF;
	return (res);
}