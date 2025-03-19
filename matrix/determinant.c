/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:59:56 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/19 23:03:29 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <utils.h>

float	determinant2x2(t_matrix *m)
{
	float res;

	if (m->rows != 2 || m->cols != 2)
		return (0);
	res = m->data[0 * m->cols + 0] * m->data[1 * m->cols + 1] - m->data[0
		* m->cols + 1] * m->data[1 * m->cols + 0];
	return (res);
}