/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:56:13 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/20 03:11:35 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <object.h>

t_tuple         transform_f(t_matrix *tmatrix, t_tuple *vec)
{
        t_tuple res;

        ft_bzero(&res, sizeof(t_tuple));
        if(!tmatrix || !vec || vec->w == VECTOR)
                return (res);
        else if (tmatrix->cols != 3 || tmatrix->rows != 3)
                return (res);
        res.x = vec->x * tmatrix->data[0] + vec->y * tmatrix->data[1] + vec->z * tmatrix->data[2];
        res.y = vec->x * tmatrix->data[3] + vec->y * tmatrix->data[4] + vec->z * tmatrix->data[5];
        res.z = vec->x * tmatrix->data[6] + vec->y * tmatrix->data[7] + vec->z * tmatrix->data[8];
        res.w = vec->w;
        return (res);
}

