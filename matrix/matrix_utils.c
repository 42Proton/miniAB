/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:34:37 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/30 08:29:51 by bismail          ###   ########.fr       */
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
	set_matrix_elem(m, 0, 0, vec->x);
	set_matrix_elem(m, 1, 1, vec->y);
	set_matrix_elem(m, 2, 2, vec->z);
	return (m);
}

t_matrix	*rotaion_m(t_tuple *vec)
{
	t_matrix	*m;

	// This is not logical at all
	m = ident_matrix4x4();
	if (!m)
		return (0);
	m->data[0] = cos(vec->z) * cos(vec->y);
	m->data[1] = cos(vec->z) * sin(vec->y) * sin(vec->x) - sin(vec->z)
		* cos(vec->x);
	m->data[2] = cos(vec->z) * sin(vec->y) * cos(vec->x) + sin(vec->z)
		* sin(vec->x);
	m->data[4] = sin(vec->z) * cos(vec->y);
	m->data[5] = sin(vec->z) * sin(vec->y) * sin(vec->x) + cos(vec->z)
		* cos(vec->x);
	m->data[6] = sin(vec->z) * sin(vec->y) * cos(vec->x) - cos(vec->z)
		* sin(vec->x);
	m->data[8] = sin(vec->y) * -1;
	m->data[9] = cos(vec->y) * sin(vec->x);
	m->data[10] = cos(vec->y) * cos(vec->x);
	return (m);
}
