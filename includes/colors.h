/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:33:07 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/15 13:43:05 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
#define COLORS_H


#include <utils.h>
typedef struct s_colors
{
        int red;
        int green;
        int blue;
        int alpha;
}       t_colors;

int     colorvalue(t_colors *a);
t_colors *colorinit(int red, int green, int blue, int alpha);

#endif