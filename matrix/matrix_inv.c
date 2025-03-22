/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 01:51:25 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/23 02:10:36 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minirt.h>
#include <utils.h>

int	is_invertible(t_matrix *m)
{
	if (determinant(m) != 0)
	{
		printf("Matrix is invertible\n");
		return (1);
	}
	printf("Matrix is not invertible\n");
	return (0);
}

t_matrix	*matrix_inverse(t_matrix *m)
{
	t_matrix	*res;
	float		det;
	int			i;
	int			j;

	if (!is_invertible(m))
		return (NULL);
	res = matrix_copy(m);
	det = determinant(m);
	i = -1;
	while (++i < m->cols)
	{
		j = -1;
		while (++j < m->rows)
		{
			res->data[j * m->cols + i] = (determinant(get_submatrix(m, i, j))
					/ det);
			if ((i + j) % 2)
				res->data[j * m->cols + i] *= -1;
		}
	}
	matrix_debug(res);
	return (res);
}
