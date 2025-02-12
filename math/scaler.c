/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:07:54 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/12 11:54:25 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

t_tuple *tupleSmult(t_tuple *a, float scale)
{
        t_tuple *res;

        res = malloc(sizeof(t_tuple));
        if (!res)
                return (NULL);
        res->X = a->X * scale;
        res->Y = a->Y * scale;
        res->Z = a->Z * scale;
        res->W = a->W;
        return (res);
}
t_tuple *tupleSdiv(t_tuple *a, float scale)
{
        t_tuple *res;

        res = malloc(sizeof(t_tuple));
        if (!res)
                return (NULL);
        res->X = a->X / scale;
        res->Y = a->Y / scale;
        res->Z = a->Z / scale;
        res->W = a->W;
        return (res);
}
float tuplemagnitude(t_tuple *a)
{
        float res;

        if (a->W == POINT)
                return (0);
        res = 0;
        res += a->X * a->X;
        res += a->Y * a->Y;
        res += a->Z * a->Z;
        res += a->W * a->W;
        res = sqrt(res);
        return (res);
}