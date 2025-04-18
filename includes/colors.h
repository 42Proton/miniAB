/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:33:07 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/12 10:59:30 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <stdlib.h>
# include <stddef.h>
# define __USE_XOPEN
# include <math.h>
# include <libft.h>

// defintions
# define EPSILON 0.00001

typedef struct s_colors
{
	float	red;
	float	green;
	float	blue;
}			t_colors;

u_int32_t	colorvalue(t_colors *a);
t_colors	colorinit(float red, float green, float blue);
t_colors	coloradd(t_colors *a, t_colors *b);
t_colors	colorsub(t_colors *a, t_colors *b);
t_colors	colormulti(t_colors *a, t_colors *b);
t_colors	colormulti_f(t_colors *a, float val);
t_colors	coloravg(t_colors *a, t_colors *b);
u_int8_t	color_inrange(float val);
t_colors	color_from_value(u_int32_t color_value);
t_colors	colorscale(t_colors *colors, int scale);

#endif