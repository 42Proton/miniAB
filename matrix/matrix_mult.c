/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:19:21 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/01 10:08:30 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

float	m_dot_product(t_matrix *a,
	t_matrix *b, int i_a, int i_b)
{
	int		i;
	float	res;

	i = 0;
	res = 0;
	while (i < a->cols)
	{
		res += a->data[i_a * a->cols + i] * b->data[i * b->cols + i_b];
		i++;
	}
	return (res);
}

void	m_mult_iter(t_matrix* res,
	t_matrix *a, t_matrix *b)
{
	int		i;
	int		j;
	float	dot_p;

	i = 0;
	while (i < b->rows)
	{
		j = 0;
		while (j < a->cols)
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

	if (a->cols != b->rows)
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

t_tuple	matrix_mult_t(t_matrix *m, t_tuple *t)
{
	t_tuple	res;

	res.x = m->data[0] * t->x + m->data[1] * t->y
		+ m->data[2] * t->z + m->data[3] * t->w;
	res.y = m->data[4] * t->x + m->data[5] * t->y
		+ m->data[6] * t->z + m->data[7] * t->w;
	res.z = m->data[8] * t->x + m->data[9] * t->y
		+ m->data[10] * t->z + m->data[11] * t->w;
	res.w = m->data[12] * t->x + m->data[13] * t->y
		+ m->data[14] * t->z + m->data[15] * t->w;
	return (res);
}
