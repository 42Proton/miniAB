/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:10:57 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/20 00:30:39 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <libft.h>

size_t	get_mindex(t_matrix *m, size_t col, size_t row)
// Not sure if the norm is going to like this but I think it looks much better this way.
{
	return (col * m->rows + row);
}

float	*get_melem(t_matrix *m, size_t col, size_t row)
{
	return (m->data + get_mindex(m, col, row));
}

void	set_matrix_elem(t_matrix *m,
	size_t col, size_t row, float val)
{
	if (col >= m->cols || row >= m->rows)
		return ;
	m->data[get_mindex(m, col, row)] = val;
}

float	get_matrix_elem(t_matrix *m,
	size_t col, size_t row)
{
	float res;
	if (col >= m->cols || row >= m->rows)
		return (0);
	res = m->data[get_mindex(m, col, row)];
	return (res);
}

t_matrix	*matrix_init(size_t cols, size_t rows)
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