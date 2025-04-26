/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 23:13:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/26 05:50:09 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	get_tangent(void *obj, int obj_type, t_computes *comps)
{
	t_tuple	tangent;

	if (obj_type == PLANE)
		tangent = get_tangent_plane(&comps->nv);
	else if (obj_type == SPHERE)
		tangent = get_tangent_sphere(&comps->uv);
	else if (obj_type == CYLINDER)
		tangent = get_tangent_cylinder(comps);
	else
		tangent = get_tangent_hyper(&comps->uv);
	return (tangent);
}

void	normal_to_world(t_tuple *t_vec, t_tuple *nv, t_computes *comps)
{
	t_tuple		bt_vec;
	t_matrix	*m;

	bt_vec = tuplecross(&comps->nv, t_vec);
	m = ident_matrix4x4();
	if (!m)
	{
		comps->is_err = 1;
		return ;
	}
	m->data[0] = t_vec->x;
	m->data[1] = bt_vec.x;
	m->data[2] = comps->nv.x;
	m->data[4] = t_vec->y;
	m->data[5] = bt_vec.y;
	m->data[6] = comps->nv.y;
	m->data[8] = t_vec->z;
	m->data[9] = bt_vec.z;
	m->data[10] = comps->nv.z;
	*nv = transform_f(m, nv);
	*nv = tuplenormalize(nv);
	free_matrix(m);
}

t_tuple	bump_normal(void *obj, int obj_type, t_computes *comps)
{
	mlx_texture_t	*ref;
	t_colors		tex;
	t_tuple			t_vec;
	t_tuple			nv;

	ref = get_bump_ref(obj, obj_type);
	if (!ref)
		return (comps->nv);
	tex = get_pixel_color(ref, &comps->uv);
	tex = colormulti_f(&tex, 2);
	nv = vector(tex.red - 1, tex.green - 1, tex.blue - 1);
	t_vec = get_tangent(obj, obj_type, comps);
	normal_to_world(&t_vec, &nv, comps);
	return (nv);
}
