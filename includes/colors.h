/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:33:07 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/26 04:16:29 by amsaleh          ###   ########.fr       */
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
# define TAU 6.283185307f
# define PI_180 0.0174532925f
# define PI_2 1.570796326794f
# define PI 3.141592653589f
# define EPSILON 0.00001f
# define GAMMA 2.2f

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
u_int8_t	color_channel_uint(float val);
t_colors	color_from_value(u_int32_t color_value);
t_colors	colorscale(t_colors *colors, int scale);
t_colors	colorpow_f(t_colors *a, float val);
float		saturate_c(float c);
float		tone_map_aces(float c);
t_colors	color_black(void);

#endif