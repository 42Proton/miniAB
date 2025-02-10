/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:07:54 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/10 17:12:02 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

float *tupleSmult(float *a, float scale)
{
        float *res;

        res = malloc(sizeof(float) * 4);
        if (!res)
                return (NULL);
        res[X] = a[X] * scale;
        res[Y] = a[Y] * scale;
        res[Z] = a[Z] * scale;
        res[W] = a[W];
        return (res);
}
float *tupleSdiv(float *a, float scale)
{
        float *res;

        res = malloc(sizeof(float) * 4);
        if (!res)
                return (NULL);
        res[X] = a[X] / scale;
        res[Y] = a[Y] / scale;
        res[Z] = a[Z] / scale;
        res[W] = a[W];
        return (res);
}