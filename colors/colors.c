/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:32:46 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/11 11:34:42 by bismail          ###   ########.fr       */
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
t_colors color_from_value(u_int32_t color_value)
{
    t_colors result;
    u_int8_t red;
    u_int8_t green;
    u_int8_t blue;
    
    // Extract RGB components from the 32-bit color value
    // Based on the bit positions in colorvalue function
    red = (color_value >> 24) & 0xFF;
    green = (color_value >> 16) & 0xFF;
    blue = (color_value >> 8) & 0xFF;
    
    // Convert from 0-255 range to float values (0.0-1.0)
    result.red = red / 255.0f;
    result.green = green / 255.0f;
    result.blue = blue / 255.0f;
    
    return (result);
}