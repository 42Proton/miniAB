/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:05:02 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/30 18:43:09 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>

u_int8_t	color_inrange(float val)
{
	if (val > 1.0)
		return (0xFF);
	if (val < 0)
		return (0);
	return (val * 255);
}
