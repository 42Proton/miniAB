/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:53:11 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/29 20:13:02 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>

t_colors	coloradd(t_colors *a, t_colors *b)
{
	t_colors	res;
	short		red;
	short		green;
	short		blue;

	red = a->red + b->red;
	green = a->green + b->green;
	blue = a->blue + b->blue;
	res.red = color_inrange(red);
	res.green = color_inrange(green);
	res.blue = color_inrange(blue);
	return (res);
}

t_colors	colorsub(t_colors *a, t_colors *b)
{
	t_colors	res;
	short		red;
	short		green;
	short		blue;

	red = a->red - b->red;
	green = a->green - b->green;
	blue = a->blue - b->blue;
	res.red = color_inrange(red);
	res.green = color_inrange(green);
	res.blue = color_inrange(blue);
	return (res);
}

t_colors	colormulti(t_colors *a, t_colors *b)
{
	t_colors	res;
	short		red;
	short		green;
	short		blue;

	red = a->red * b->red;
	green = a->green * b->green;
	blue = a->blue * b->blue;
	res.red = color_inrange(red);
	res.green = color_inrange(green);
	res.blue = color_inrange(blue);
	return (res);
}

t_colors	colormulti_f(t_colors *a, float val)
{
	t_colors	res;
	short		red;
	short		green;
	short		blue;

	red = a->red * val;
	green = a->green * val;
	blue = a->blue * val;
	res.red = color_inrange(red);
	res.green = color_inrange(green);
	res.blue = color_inrange(blue);
	return (res);
}
