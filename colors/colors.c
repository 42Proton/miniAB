/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:32:46 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/19 15:51:07 by amsaleh          ###   ########.fr       */
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

t_colors	color_black()
{
	t_colors	res;

	ft_bzero(&res, sizeof(t_colors));
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

t_colors	color_from_value(u_int32_t color_value)
{
	t_colors	result;
	u_int8_t	red;
	u_int8_t	green;
	u_int8_t	blue;

	red = (color_value >> 24) & 0xFF;
	green = (color_value >> 16) & 0xFF;
	blue = (color_value >> 8) & 0xFF;
	result.red = red / 255.0f;
	result.green = green / 255.0f;
	result.blue = blue / 255.0f;
	return (result);
}
