/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operations2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:26:35 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/26 04:28:49 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>

t_colors	colorpow_f(t_colors *a, float val)
{
	t_colors	res;

	res.red = powf(a->red, val);
	res.green = powf(a->green, val);
	res.blue = powf(a->blue, val);
	return (res);
}

float	saturate_c(float c)
{
	float	res;

	res = fminf(fmaxf(c, 0.0f), 1.0f);
	return (res);
}

float	tone_map_aces(float c)
{
	float	res;

	res = saturate_c(c * (2.51f * c + 0.03f)
		/ (c * (2.43f * c + 0.59f) + 0.14f));
	return (res);
}
