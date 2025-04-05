/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:53:11 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/30 18:34:34 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>

t_colors	coloradd(t_colors *a, t_colors *b)
{
	t_colors	res;

	res.red = a->red + b->red;
	res.green = a->green + b->green;
	res.blue = a->blue + b->blue;
	return (res);
}

t_colors	colorsub(t_colors *a, t_colors *b)
{
	t_colors	res;

	res.red = a->red - b->red;
	res.green = a->green - b->green;
	res.blue = a->blue - b->blue;
	return (res);
}

t_colors	colormulti(t_colors *a, t_colors *b)
{
	t_colors	res;

	res.red = a->red * b->red;
	res.green = a->green * b->green;
	res.blue = a->blue * b->blue;
	return (res);
}

t_colors	colormulti_f(t_colors *a, float val)
{
	t_colors	res;

	res.red = a->red * val;
	res.green = a->green * val;
	res.blue = a->blue * val;
	return (res);
}
