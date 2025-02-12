/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:58:19 by bismail           #+#    #+#             */
/*   Updated: 2025/02/12 11:52:46 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

t_tuple *tuplenormalize(t_tuple *a)
{
        t_tuple *res;
        float   mag;

        res = malloc(sizeof(t_tuple));
        if(!res)
                return (NULL);
        mag = tuplemagnitude(a);
        if (!mag)
                return (NULL);
        res->X = a->X / mag;
        res->Y = a->Y / mag;
        res->Z = a->Z / mag;
        res->W = a->W;
        return (res);
}