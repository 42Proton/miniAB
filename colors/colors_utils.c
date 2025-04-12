/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:05:02 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/12 11:01:20 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>

u_int8_t	color_inrange(float val)
{
	if (val > 1.0)
		return (0xFF);
	if (val <= 0)
		return (0);
	return (val * 255);
}

t_colors	colorscale(t_colors *colors, int scale)
{
	if (scale > 0)
	{
		colors->blue /= scale;
		colors->red /= scale;
		colors->green /= scale;
	}
	return (*colors);
}
