/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:30:31 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/12 10:45:42 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

int floatcmp(double a, double b)
{
        if (fabs(a - b) < EPSILON)
                return (1);
        else
                return (0);
}
int tuplecmp(t_tuple *a, t_tuple *b)
{
        if (floatcmp(a->X, b->X) && floatcmp(a->Y, b->Y) && floatcmp(a->Z, b->Z) && floatcmp(a->W, b->W))
                return (1);
        else
                return (0);
}
t_tuple *tupleadd(t_tuple *a, t_tuple *b)
{
        t_tuple *res;

        if (a->W + b->W > 1)
                return (NULL);
        res = malloc(sizeof(t_tuple));
        if (!res)
                return (NULL);
        res->X = a->X + b->X;
        res->Y = a->Y + b->Y;
        res->Z = a->Z + b->Z;
        res->W = a->W + b->W;
        return (res);
}
t_tuple *tuplesub(t_tuple *a, t_tuple *b)
{
        struct s_tuple *res;

        res = malloc(sizeof(*res) * 4);
        if (!res)
                return (NULL);
        res->X = a->X - b->X;
        if(res->X)
                printf("Hi");
        res->Y = a->Y - b->Y;
        res->Z = a->Z - b->Z;
        res->W = a->W - b->W;
        return (res);
}
t_tuple *tuplenegt(t_tuple *a)
{
        t_tuple *res;

        res = malloc(sizeof(t_tuple));
        if (!res)
                return (NULL);
        res->X = -a->X;
        res->Y = -a->Y;
        res->Z = -a->Z;
        res->W = -a->W;
        return (res);
}