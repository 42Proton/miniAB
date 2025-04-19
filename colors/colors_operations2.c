/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operations2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:26:35 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/19 17:31:19 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>

t_colors	colorpow_f(t_colors *a, float val)
{
	t_colors	res;

	res.red = pow(a->red, val);
	res.green = pow(a->green, val);
	res.blue = pow(a->blue, val);
	return (res);
}
