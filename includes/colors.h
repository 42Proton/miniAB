/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:33:07 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/30 18:36:28 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <stdlib.h>
# include <stddef.h>
# define __USE_XOPEN
# include <math.h>
# include <libft.h>

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
u_int8_t	color_inrange(float val);

#endif