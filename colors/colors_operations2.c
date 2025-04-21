/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operations2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:26:35 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/21 17:45:23 by amsaleh          ###   ########.fr       */
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
