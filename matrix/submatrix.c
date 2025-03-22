/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 02:43:44 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/23 02:04:28 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <utils.h>

static void	submatrix_copy(t_matrix *m, t_matrix *new_m, int skip_col,
		int skip_row)
{
	int	i;
	int	j;
	int	new_i;
	int	new_j;

	new_i = 0;
	i = -1;
	while (++i < m->cols)
	{
		if (i == skip_col)
			continue ;
		new_j = 0;
		j = -1;
		while (++j < m->rows)
		{
			if (j == skip_row)
				continue ;
			new_m->data[new_i * new_m->cols + new_j] = m->data[i * m->cols + j];
			new_j++;
		}
		new_i++;
	}
}

t_matrix_9	submatrix_3x3(t_matrix *m, int skip_col, int skip_row)
{
	t_matrix_9	m_9;
	t_matrix	tmp_m;

	m_9.cols = 3;
	m_9.rows = 3;
	tmp_m.cols = 3;
	tmp_m.rows = 3;
	tmp_m.data = m_9.data;
	submatrix_copy(m, &tmp_m, skip_col, skip_row);
	return (m_9);
}


t_matrix	*get_submatrix(t_matrix *m, int skip_col, int skip_row)
{
	t_matrix	*new_m;

	new_m = matrix_init(m->cols - 1, m->rows - 1);
	if (!new_m)
		return (NULL);
	submatrix_copy(m, new_m, skip_col, skip_row);
	return (new_m);
}
