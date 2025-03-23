/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:10:57 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/23 03:11:18 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <libft.h>

size_t	get_mindex(t_matrix *m, int col, int row)
{
	return (col * m->rows + row);
}

float	*get_melem(t_matrix *m, int col, int row)
{
	size_t	i;

	i = get_mindex(m, col, row);
	return (m->data + i);
}

void	set_matrix_elem(t_matrix *m,
	int col, int row, float val)
{
	size_t	i;

	if (col >= m->cols || row >= m->rows)
		return ;
	i = get_mindex(m, col, row);
	m->data[i] = val;
}

float	get_matrix_elem(t_matrix *m,
	int col, int row)
{
	float res;
	size_t	i;

	if (col >= m->cols || row >= m->rows)
		return (0);
	i = get_mindex(m, col, row);
	res = m->data[i];
	return (res);
}

t_matrix	*matrix_init(int cols, int rows)
{
	t_matrix	*matrix;

	matrix = malloc(sizeof(t_matrix));
	if (!matrix)
		return (0);
	matrix->cols = cols;
	matrix->rows = rows;
	matrix->data = ft_calloc(cols * rows, sizeof(float));
	if (!matrix->data)
	{
		free(matrix);
		return (0);
	}
	return (matrix);
}
