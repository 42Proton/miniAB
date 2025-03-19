/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:13:44 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/19 22:36:17 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <utils.h>

static int	matrix_helper(t_matrix *a, t_matrix *b, t_matrix *res)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (i < a->rows)
	{
		j = 0;
		while (j < b->cols)
		{
			k = 0;
			while (k < a->cols)
			{
				res->data[i * res->cols + j] += a->data[i * a->cols + k]
					* b->data[k * b->cols + j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	matrix_multiply(t_matrix *a, t_matrix *b)
{
	t_matrix	*res;
	size_t		i;

	if (a->cols != b->rows)
		return (0);
	res = matrix_init(b->cols, a->rows);
	if (!res)
		return (0);
	i = 0;
	while (i < a->rows)
	{
		matrix_helper(a, b, res);
		i++;
	}
	free(a->data);
	a->data = res->data;
	free(res);
	return (1);
}

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
