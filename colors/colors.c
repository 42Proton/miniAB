/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:32:46 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/23 15:49:56 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>
#include <stdio.h>

t_colors	colorinit(float red, float green, float blue)
{
	t_colors	res;

	res.red = red;
	res.green = green;
	res.blue = blue;
	return (res);
}

t_colors	color_black(void)
{
	t_colors	res;

	ft_bzero(&res, sizeof(t_colors));
	return (res);
}

u_int32_t	color_uint(t_colors *a)
{
	u_int8_t	red;
	u_int8_t	green;
	u_int8_t	blue;
	u_int32_t	res;

	red = color_channel_uint(a->red);
	green = color_channel_uint(a->green);
	blue = color_channel_uint(a->blue);
	res = 0;
	res = res | (red << 24);
	res = res | (green << 16);
	res = res | (blue << 8);
	res = res | 0xFF;
	return (res);
}

u_int32_t	colorvalue(t_colors *a)
{
	t_colors	tmp;
	u_int32_t	res;

	if (!a)
		return (0);
	tmp.red = tone_map_aces(a->red);
	tmp.green = tone_map_aces(a->green);
	tmp.blue = tone_map_aces(a->blue);
	tmp = colorpow_f(&tmp, 1.0f / GAMMA);
	res = color_uint(&tmp);
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
	result.red = red * 0.003921569f;
	result.green = green * 0.003921569f;
	result.blue = blue * 0.003921569f;
	return (result);
}
