/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:05:02 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/23 03:04:15 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>

u_int8_t	color_channel_uint(float val)
{
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
