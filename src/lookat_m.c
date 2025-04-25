/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookat_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:58:22 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/25 08:21:09 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

void	lookat_set_vecs(t_tuple *forward, t_tuple *up, t_tuple *left)
{
	float	fx;
	float	fy;
	float	fz;

	fx = forward->x;
	fy = forward->y;
	fz = forward->z;
	*up = vector(0, 1, 0);
	if (floatcmp(fx, 0) && floatcmp(fz, 0))
	{
		if (!floatcmp(fy, 0))
			*up = vector(0, 0, 1);
		else
			*forward = vector(0, 0, 1);
	}
	*left = tuplecross(forward, up);
	*left = tuplenormalize(left);
	*up = tuplecross(left, forward);
	*up = tuplenormalize(up);
}

int	lookat_mult_translate(t_matrix *m, t_tuple *pos)
{
	t_tuple		vec;
	t_matrix	*m2;
	int			res;

	vec = tuplenegt(pos);
	m2 = translation_m(&vec);
	if (!m2)
		return (0);
	res = matrix_multiply(m, m2);
	free_matrix(m2);
	return (res);
}

t_matrix	*lookat_m(t_tuple *pos, t_tuple *to)
{
	t_tuple		up;
	t_tuple		forward;
	t_tuple		left;
	t_matrix	*m;

	m = ident_matrix4x4();
	if (!m)
		return (0);
	forward = *to;
	lookat_set_vecs(&forward, &up, &left);
	m->data[0] = left.x;
	m->data[1] = left.y;
	m->data[2] = left.z;
	m->data[4] = up.x;
	m->data[5] = up.y;
	m->data[6] = up.z;
	m->data[8] = -forward.x;
	m->data[9] = -forward.y;
	m->data[10] = -forward.z;
	if (!lookat_mult_translate(m, pos))
	{
		free_matrix(m);
		return (0);
	}
	return (m);
}
