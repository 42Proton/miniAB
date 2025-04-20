/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_mapping_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:39:39 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/20 19:42:10 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

// To get the tangent of the plane we use an arbitary
// tangent vector for specify direction which most of
// the time will be the x axis unless if the plane normal
// is aligned on x axis, then using this vector we will project
// it on the plane using the normal vector to get the true tangent
t_tuple	get_tangent_plane(t_tuple *nv)
{
	t_tuple	vec;
	t_tuple	t_v;
	float	vn_d;

	if (!floatcmp(nv->x, 0))
		vec = vector(0, 0, 1);
	else
		vec = vector(1, 0, 0);
	vn_d = tupledot(&vec, nv);
	t_v = n_tuplesmult(nv, vn_d);
	t_v = n_tuplesub(&vec, &t_v);
	t_v = tuplenormalize(&t_v);
	return (t_v);
}

// Function to obtain a tangent vector for
// hyperboloid of one sheet with the derivative
// of parameterized hyperboloid with respect to u
t_tuple	get_tangent_hyper(t_uv *uv)
{
	t_tuple	vec;
	float	chv;
	float	su;
	float	cu;

	chv = cosh(uv->v);
	su = sin(uv->u);
	cu = cos(uv->u);
	vec = vector(chv * su, 0, chv * cu);
	vec = tuplenormalize(&vec);
	return (vec);
}

// Function to obtain a tangent vector for sphere with the derivative
// of parameterized sphere with differential geometry with respect to u
t_tuple	get_tangent_sphere(t_uv *uv)
{
	t_tuple	vec;
	float	su;
	float	sv;
	float	cu;

	su = sin(uv->u);
	sv = sin(uv->v);
	cu = cos(uv->u);
	vec = vector(-sv * su, 0, sv * cu);
	vec = tuplenormalize(&vec);
	return (vec);
}

t_tuple	get_tangent_cylinder(t_uv *uv)
{
	t_tuple	vec;
	float	su;
	float	cu;

	su = sin(uv->u);
	cu = cos(uv->u);
	vec = vector(-su, 0, cu);
	vec = tuplenormalize(&vec);
	return (vec);
}
