/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:05:02 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/06 23:58:49 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>

short	color_value_check_positve(short color)
{
	if (color > 0xFF)
		return (0xFF);
	else
		return (color);
}

short	color_value_check_negative(short color)
{
	if (color < 0)
		return (0);
	else
		return (color);
}

short	color_inrange(short color)
{
	short	res;

	if (color > 0xFF)
		res = 0xFF;
	else if (color < 0)
		res = 0;
	else
		res = color;
	return (res);
}

short	alpha_ftos(float alpha)
{
	return ((short)roundf(alpha * 255.0f));
}
