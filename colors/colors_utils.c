/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:05:02 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/24 15:31:43 by abueskander      ###   ########.fr       */
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
