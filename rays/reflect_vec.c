/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:15:20 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/28 09:15:38 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>

t_tuple	reflect_vec(t_tuple *vec, t_tuple *norm)
{
	float	dot;
	t_tuple	vec_mirror;
	t_tuple	r;

	dot = tupledot(vec, norm);
	dot = dot * 2;
	vec_mirror = n_tuplesmult(norm, dot);
	r = n_tuplesub(vec, &vec_mirror);
	return (r);
}
