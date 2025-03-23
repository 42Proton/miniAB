/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:32:03 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/23 05:39:41 by amsaleh          ###   ########.fr       */
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
	printf("MATRIX DEBUG:\n");
	if (m == NULL)
	{
		printf("Matrix is NULL\n");
		return ;
	}
	for (int i = 0; i < m->cols; i++)
	{
		for (int j = 0; j < m->rows; j++)
			printf("%.4f ", m->data[i * m->cols + j]);
		printf("\n");
	}
}
