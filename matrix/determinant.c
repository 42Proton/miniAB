/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:59:56 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/19 23:13:55 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
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

t_matrix	*get_submatrix(t_matrix *m, int skip_row, int skip_col)
{
	t_matrix	*sub;
	int			i;
	int			j;
	int			new_i;
	int			new_j;

	sub = matrix_init(m->cols - 1, m->rows - 1);
	new_i = 0;
	i = -1;
	while (++i < m->rows)
	{
		if (i == skip_row)
			continue ;
		new_j = 0;
		j = -1;
		while (++j < m->cols)
		{
			if (j == skip_col)
				continue ;
			sub->data[new_i * sub->cols + new_j++] = m->data[i * m->cols + j];
		}
		new_i++;
	}
	return (sub);
}

float	determinant(t_matrix *m)
{
	float	det;
	float	cofactor;
	int		i;

	if (m->rows == 2 && m->cols == 2)
		return (determinant2x2(m));
	det = 0;
	i = -1;
	while (++i < m->cols)
	{
		cofactor = m->data[0 * m->cols + i] * determinant(get_submatrix(m, 0,
					i));
		if (i % 2)
			cofactor *= -1;
		det += cofactor;
	}
	return (det);
}

// float	determinant3x3(t_matrix *m)
// {
// 	float res;

//         if (m->rows != 3 || m->cols != 3)
//                 return (0);

// }