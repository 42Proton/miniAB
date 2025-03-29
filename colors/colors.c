/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:32:46 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/29 20:16:35 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>

t_colors	colorinit(u_int8_t red, u_int8_t green, u_int8_t blue)
{
	t_colors	res;

	res.red = (red);
	res.green = (green);
	res.blue = (blue);
	return (res);
}

u_int32_t	colorvalue(t_colors *a)
{
	int			res;
	t_colors	tmcol;

	if (!a)
		return (0);
	tmcol = colorinit(a->red, a->green, a->blue);
	res = 0;
	res = res | (tmcol.red << 24);
	res = res | (tmcol.green << 16);
	res = res | (tmcol.blue << 8);
	res = res | 0xFF;
	return (res);
}