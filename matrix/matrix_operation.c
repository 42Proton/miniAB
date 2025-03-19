/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:13:44 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/19 22:22:33 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <utils.h>

int	matrix_add(t_matrix *a, t_matrix *b)
{
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
