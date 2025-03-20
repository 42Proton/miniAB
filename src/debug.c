/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:32:03 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/21 01:34:50 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	debug_tuple(t_tuple *tuple)
{
	printf("TUPLE DEBUG:\n");
	printf("%f %f %f\n", tuple->x, tuple->y, tuple->z);
}

void	matrix_debug(t_matrix *m)
{
	printf("MATRIX DEBUG:\n");
	for (int i = 0; i < m->cols; i++)
	{
		for (int j = 0; j < m->rows; j++)
			printf("%.1f ", m->data[i * m->cols + j]);
		printf("\n");
	}
}
