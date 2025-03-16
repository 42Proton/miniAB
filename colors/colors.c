/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:32:46 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/17 02:23:08 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>

t_colors	colorinit(short red, short green, short blue, short alpha)
{
	t_colors	res;

	res.red = (red);
	res.green = (green);
	res.blue = (blue);
	res.alpha = (alpha);
	return (res);
}

int	colorvalue(t_colors *a)
{
	int			res;
	t_colors	tmcol;

	tmcol = colorinit(color_inrange(a->red), color_inrange(a->green),
			color_inrange(a->blue), color_inrange(a->alpha));
	if (!a)
		return (0);
	res = 0;
	res = res | (tmcol.alpha << 24);
	res = res | (tmcol.red << 16);
	res = res | (tmcol.green << 8);
	res = res | (tmcol.blue);
	return (res);
}