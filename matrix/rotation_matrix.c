/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:18:51 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/05 13:13:56 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

t_matrix	*rotation_x(float x)
{
	t_matrix	*m;
	float		cx;
	float		sx;

	m = ident_matrix4x4();
	if (!m)
		return (0);
	cx = cos(x);
	sx = sin(x);
	m->data[5] = cx;
	m->data[6] = sx;
	m->data[9] = -sx;
	m->data[10] = cx;
	return (m);
}

t_matrix	*rotation_y(float y)
{
	t_matrix	*m;
	float		cy;
	float		sy;

	m = ident_matrix4x4();
	if (!m)
		return (0);
	cy = cos(y);
	sy = sin(y);
	m->data[0] = cy;
	m->data[2] = -sy;
	m->data[8] = sy;
	m->data[10] = cy;
	return (m);
}

t_matrix	*rotation_z(float z)
{
	t_matrix	*m;
	float		cz;
	float		sz;

	m = ident_matrix4x4();
	if (!m)
		return (0);
	cz = cos(z);
	sz = sin(z);
	m->data[0] = cz;
	m->data[1] = -sz;
	m->data[4] = sz;
	m->data[5] = cz;
	return (m);
}

int	rotation_m_multi(t_matrix *m_z,
	t_matrix *m_y, t_matrix *m_x)
{
	int	res;

	res = matrix_multiply(m_z, m_y);
	free_matrix(m_y);
	if (!res)
	{
		free_matrix(m_z);
		free_matrix(m_x);
		return (0);
	}
	res = matrix_multiply(m_z, m_x);
	free_matrix(m_x);
	if (!res)
	{
		free_matrix(m_z);
		return (0);
	}
	return (1);
}

t_matrix	*rotation_m(t_tuple *vec)
{
	t_matrix	*m_z;
	t_matrix	*m_y;
	t_matrix	*m_x;

	m_z = rotation_z(vec->z);
	if (!m_z)
		return (0);
	m_y = rotation_y(vec->y);
	if (!m_y)
	{
		free_matrix(m_z);
		return (0);
	}
	m_x = rotation_x(vec->x);
	if (!m_x)
	{
		free_matrix(m_z);
		free_matrix(m_y);
		return (0);
	}
	if (!rotation_m_multi(m_z, m_y, m_x))
		return (0);
	return (m_z);
}
