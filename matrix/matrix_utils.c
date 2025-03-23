/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:34:37 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/23 02:51:42 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

void	free_matrix(t_matrix *m)
{
	free(m->data);
	free(m);
}

t_matrix	*ident_matrix4x4()
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

t_matrix	*translation_m(float x, float y, float z)
{
	t_matrix	*m;

	m = ident_matrix4x4();
	if (!m)
		return (0);
	set_matrix_elem(m, 0, 3, x);
	set_matrix_elem(m, 1, 3, y);
	set_matrix_elem(m, 2, 3, z);
	return (m);
}