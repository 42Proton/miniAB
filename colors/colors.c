/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:32:46 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/15 14:18:20 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>

t_colors *colorinit(short red, short green, short blue, short alpha)
{
        t_colors *res;

        res = malloc(sizeof(t_colors));
        if (!res)
                return(NULL);
        res->red = color_inrange(red);
        res->green = color_inrange(green);
        res->blue = color_inrange(blue);
        res->alpha = color_inrange(alpha);
        
        return (res);
}

int     colorvalue(t_colors *a)
{
        int     res;
        if(!a)
                return (0);
        res = 0;
        res = res | (a->alpha << 24);
        res = res | (a->red << 16);
        res = res | (a->green << 8);
        res = res | (a->blue);

        return (res);
}
