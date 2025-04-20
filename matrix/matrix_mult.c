/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:19:21 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/20 18:09:10 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <stdio.h>

float	m_dot_product(t_matrix *a,
	t_matrix *b, int i_a, int i_b)
{
	int		i;
	float	res;

	i = 0;
	res = 0;
	while (i < b->cols)
	{
		res += a->data[i_a * a->cols + i] * b->data[i * b->cols + i_b];
		i++;
	}
	return (res);
}

void	m_mult_iter(t_matrix *res,
	t_matrix *a, t_matrix *b)
{
	int		i;
	int		j;
	float	dot_p;

	i = 0;
	while (i < a->rows)
	{
		j = 0;
		while (j < b->cols)
		{
			dot_p = m_dot_product(a, b, i, j);
			set_matrix_elem(res, i, j, dot_p);
			j++;
		}
		i++;
	}
}

int	matrix_multiply(t_matrix *a, t_matrix *b)
{
	t_matrix	*res;

	if (a->cols != b->rows || a->rows != b->cols)
		return (0);
	res = matrix_init(b->cols, a->rows);
	if (!res)
		return (0);
	m_mult_iter(res, a, b);
	free(a->data);
	a->data = res->data;
	free(res);
	return (1);
}
