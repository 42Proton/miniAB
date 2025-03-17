/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:56:13 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/17 03:52:03 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <object.h>

t_tuple         transform_f(t_matrix *tmatrix, t_tuple *vec)
{
        t_tuple res;

        if(!tmatrix || !vec || vec->w == VECTOR)
                return ((t_tuple){0, 0, 0, 0});
        else if (tmatrix->cols != 3 || tmatrix->rows != 3)
                return ((t_tuple){0, 0, 0, 0});
        res.x = vec->x * tmatrix->data[0] + vec->y * tmatrix->data[1] + vec->z * tmatrix->data[2];
        res.y = vec->x * tmatrix->data[3] + vec->y * tmatrix->data[4] + vec->z * tmatrix->data[5];
        res.z = vec->x * tmatrix->data[6] + vec->y * tmatrix->data[7] + vec->z * tmatrix->data[8];
        res.w = vec->w;
        return (res);
}

