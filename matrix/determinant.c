/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:59:56 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/20 02:45:46 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

float	determinant2x2(t_matrix *m)
{
	float	res;

	if (m->rows != 2 || m->cols != 2)
		return (0);
	res = m->data[0 * m->cols + 0] * m->data[1 * m->cols + 1] - m->data[0
		* m->cols + 1] * m->data[1 * m->cols + 0];
	return (res);
}

float	s_determinant_3x3(t_matrix_9 *m)
{
	float	m0;
	float	m1;
	float	m2;

	m0 = m->data[4] * m->data[8] - m->data[5] * m->data[7];
	m1 = m->data[3] * m->data[8] - m->data[5] * m->data[6];
	m2 = m->data[3] * m->data[7] - m->data[4] * m->data[6];
	return (m0 * m->data[0] - m1 * m->data[1] + m2 * m->data[2]);
}

float	determinant_3x3(t_matrix *m)
{
	float	m0;
	float	m1;
	float	m2;

	if (m->cols != 3 && m->rows != 3)
		return (0);
	m0 = m->data[4] * m->data[8] - m->data[5] * m->data[7];
	m1 = m->data[3] * m->data[8] - m->data[5] * m->data[6];
	m2 = m->data[3] * m->data[7] - m->data[4] * m->data[6];
	return (m0 * m->data[0] - m1 * m->data[1] + m2 * m->data[2]);
}

float	determinant(t_matrix *m)
{
	float		det;
	float		cofactor;
	int			i;
	t_matrix_9	sub_m;

	if (m->rows == 2 && m->cols == 2)
		return (determinant2x2(m));
	if (m->rows == 3 && m->cols == 3)
		return (determinant2x2(m));
	det = 0;
	i = -1;
	while (++i < m->cols)
	{
		sub_m = submatrix_3x3(m, 0, i);
		cofactor = m->data[i] * s_determinant_3x3(&sub_m);
		if (i % 2)
			det -= cofactor;
		else
			det += cofactor;
	}
	return (det);
}
