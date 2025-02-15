/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:53:11 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/15 14:12:47 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.h>

t_colors *coloradd(t_colors *a, t_colors *b)
{
        t_colors *res;

        res = malloc(sizeof(t_colors));
        if(!res)
                return (NULL);
        res->alpha = color_value_check_positve(a->alpha + b->alpha);
        res->red = color_value_check_positve(a->red + b->red);
        res->green = color_value_check_positve(a->green + b->green);
        res->blue = color_value_check_positve(a->blue + b->blue);
        return (res);
}