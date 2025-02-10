/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:29:01 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/10 16:57:23 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

float *point(float x, float y, float z)
{
        float *vop;

        vop = malloc(sizeof(float) * 4);
        vop[X] = x;
        vop[Y] = y;
        vop[Z] = z;
        vop[W] = POINT;
        return vop;
}
float *vector(float x, float y, float z)
{
        float *vop;

        vop = malloc(sizeof(float) * 4);
        vop[X] = x;
        vop[Y] = y;
        vop[Z] = z;
        vop[W] = VECTOR;
        return vop;
}
