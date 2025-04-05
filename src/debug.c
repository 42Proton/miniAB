/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:32:03 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/05 13:03:02 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>

void	debug_tuple(t_tuple *tuple)
{
	printf("TUPLE DEBUG:\n");
	printf("%f %f %f\n", tuple->x, tuple->y, tuple->z);
}

void	matrix_debug(t_matrix *m)
{
	int	i;
	int	j;

	i = 0;
	printf("MATRIX DEBUG:\n");
	if (m == NULL)
	{
		printf("Matrix is NULL\n");
		return ;
	}
	while (i < m->cols)
	{
		j = 0;
		while (j < m->rows)
		{
			printf("%.4f ", m->data[i * m->cols + j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
