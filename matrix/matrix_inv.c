/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 01:51:25 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/26 22:58:07 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	is_invertible(t_matrix *m)
{
	if (determinant(m) < EPSILON)
		return (0);
	return (1);
}

float	m_minor(t_matrix *m, int col, int row)
{
	t_matrix_9	sub_m;
	float		det;

	sub_m = submatrix_3x3(m, col, row);
	det = s_determinant_3x3(&sub_m);
	return (det);
}

float	cofactor(t_matrix *m, int col, int row)
{
	float	m0;
	int		sign;

	m0 = m_minor(m, col, row);
	sign = pow(-1, col + row);
	return (m0 * sign);
}

t_matrix	*matrix_inverse(t_matrix *m)
{
	t_matrix	*res;
	float		c;
	int			i;
	int			j;

	if (!is_invertible(m))
		return (0);
	res = matrix_copy(m);
	if (!res)
		return (0);
	i = -1;
	while (++i < m->cols)
	{
		j = -1;
		while (++j < m->rows)
		{
			c = cofactor(m, j, i);
			set_matrix_elem(res, i, j, c / determinant(m));
		}
	}
	return (res);
}
