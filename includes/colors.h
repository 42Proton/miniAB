/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:33:07 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/17 02:23:19 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <stdlib.h>
# include <stddef.h>
# include <math.h>
# include <libft.h>

typedef struct s_colors
{
	short	red;
	short	green;
	short	blue;
	short	alpha;
}			t_colors;

int			colorvalue(t_colors *a);
t_colors	colorinit(short red, short green, short blue, short alpha);
short		color_value_check_positve(short color);
short		color_value_check_negative(short color);
t_colors	coloradd(t_colors *a, t_colors *b);
t_colors	colorsub(t_colors *a, t_colors *b);
t_colors	colormulti(t_colors *a, t_colors *b);
short		color_inrange(short color);
short		alpha_ftos(float alpha);

#endif