/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:13:44 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/24 01:19:57 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <utils.h>

int	matrix_equal(t_matrix *a, t_matrix *b)
{
	size_t	items;

	if (a->cols != b->cols || a->rows != b->rows)
		return (0);
	items = -1;
	while (++items < (a->cols * a->rows))
		if (a->data[items] != b->data[items])
			return (0);
	return (1);
}

t_matrix	*matrix_copy(t_matrix *m)
{
	t_matrix	*copy;
	size_t		i;

	copy = matrix_init(m->cols, m->rows);
	if (!copy)
		return (0);
	i = 0;
	while (i < m->cols * m->rows)
	{
		copy->data[i] = m->data[i];
		i++;
	}
	return (copy);
}

t_matrix	*matrix_transpose(t_matrix *m)
{
	t_matrix	*transposed;
	size_t		i;
	size_t		j;

	transposed = matrix_init(m->rows, m->cols);
	if (!transposed)
		return (0);
	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->cols)
		{
			transposed->data[j * transposed->cols + i] = m->data[i * m->cols
				+ j];
			j++;
		}
		i++;
	}
	return (transposed);
}
