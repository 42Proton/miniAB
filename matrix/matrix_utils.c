/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:34:37 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/25 09:42:38 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

void	free_matrix(t_matrix *m)
{
	if (m && m->data)
		free(m->data);
	free(m);
}

t_matrix	*ident_matrix4x4(void)
{
	t_matrix	*m;

	m = matrix_init(4, 4);
	if (!m)
		return (0);
	set_matrix_elem(m, 0, 0, 1);
	set_matrix_elem(m, 1, 1, 1);
	set_matrix_elem(m, 2, 2, 1);
	set_matrix_elem(m, 3, 3, 1);
	return (m);
}

t_matrix	*translation_m(t_tuple *pos)
{
	t_matrix	*m;

	m = ident_matrix4x4();
	if (!m)
		return (0);
	set_matrix_elem(m, 0, 3, pos->x);
	set_matrix_elem(m, 1, 3, pos->y);
	set_matrix_elem(m, 2, 3, pos->z);
	return (m);
}

t_matrix	*scale_m(t_tuple *vec)
{
	t_matrix	*m;

	m = ident_matrix4x4();
	if (!m)
		return (0);
	set_matrix_elem(m, 0, 0, vec->x + 0.01);
	set_matrix_elem(m, 1, 1, vec->y + 0.01);
	set_matrix_elem(m, 2, 2, vec->z + 0.01);
	return (m);
}
