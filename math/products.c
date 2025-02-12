/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   products.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:14:02 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/12 16:20:46 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

t_tuple *tuplecross(t_tuple *a, t_tuple *b)
{
        t_tuple *res;

        if (!a || !b)
                return (NULL);
        res = malloc(sizeof(t_tuple));
        if (!res)
                return (NULL);
        res->X = a->Y * b->Z - b->Y * a->Z;
        res->Y = a->Z * b->X - b->Z * a->X;
        res->Z = a->X * b->Y - b->X * a->Y;
        return (res);
}

float tupledot(t_tuple *a, t_tuple *b)
{
        float res;

        if (!a || !b)
                return (0);
        res = a->X * b->X;
        res += a->Y * b->Y;
        res += a->Z * b->Z;
        res += a->W * b->W;
        return (res);
}