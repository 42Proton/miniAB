/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:32:46 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/15 13:44:42 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>

t_colors *colorinit(int red, int green, int blue, int alpha)
{
        t_colors *res;

        res = malloc(sizeof(t_colors));
        if (!res)
                return(NULL);
        res->red = red;
        res->green = green;
        res->blue = blue;
        res->alpha = alpha;
        
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

//__ __ __ __