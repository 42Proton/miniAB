/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:53:11 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/23 01:59:02 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>

t_colors	coloradd(t_colors *a, t_colors *b)
{
	t_colors	res;

	ft_bzero(&res, sizeof(t_colors));
	if (!a || !b)
		return (res);
	res.alpha = a->alpha + b->alpha;
	res.red = a->red + b->red;
	res.green = a->green + b->green;
	res.blue = a->blue + b->blue;
	return (res);
}

t_colors	colorsub(t_colors *a, t_colors *b)
{
	t_colors	res;

	ft_bzero(&res, sizeof(t_colors));
	if (!a || !b)
		return (res);
	res.alpha = a->alpha - b->alpha;
	res.red = a->red - b->red;
	res.green = a->green - b->green;
	res.blue = a->blue - b->blue;
	return (res);
}

t_colors	colormulti(t_colors *a, t_colors *b)
{
	t_colors	res;

	ft_bzero(&res, sizeof(t_colors));
	if (!a || !b)
		return (res);
	res.alpha = a->alpha * b->alpha;
	res.red = a->red * b->red;
	res.green = a->green * b->green;
	res.blue = a->blue * b->blue;
	return (res);
}
