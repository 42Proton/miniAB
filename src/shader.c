/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:12:04 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/19 23:18:29 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_colors	phong_shader(t_alight *alight, t_computes *comp, t_list *vision_objs)
{
	t_phong_shader	shader;
	t_colors		res;

	shader.mat = get_material(comp->insect->obj_type, comp->insect->obj);
	shader.ambient_c = coloradd(&shader.mat->color, alight->colors);
	shader.ambient_c = coloradd(&shader.ambient_c, &comp->map_color);
	shader.ambient_c = colormulti_f(&shader.ambient_c, alight->ratio);
	if (comp->is_shadow)
		return (shader.ambient_c);
	shader.specular_c = colorinit(0, 0, 0);
	shader.diffuse_c = colorinit(0, 0, 0);
	while (vision_objs)
	{
		shader_vision_iter(&shader, comp, vision_objs);
		vision_objs = vision_objs->next;
	}
	res = coloradd(&shader.ambient_c, &shader.diffuse_c);
	res = coloradd(&res, &shader.specular_c);
	return (res);
}

t_colors	reflect_shade(t_rtptr *rts,
	t_computes *comp, t_material *mat, int depth)
{
	t_ray		r_ray;
	t_colors	res;

	r_ray = init_ray(&comp->over_point, &comp->reflectv);
	res = ray_color(rts, &r_ray, depth + 1);
	res = colormulti_f(&res, mat->reflect);
	return (res);
}

t_colors	shade_hit(t_rtptr *rts, t_computes *comp, int depth)
{
	t_colors	phong_res;
	t_colors	res;
	t_material	*mat;

	res = color_black();
	phong_res = phong_shader(rts->alight, comp, rts->vision_objs);
	mat = get_material(comp->insect->obj_type, comp->insect->obj);
	if (mat->reflect > EPSILON && !comp->is_shadow)
		res = reflect_shade(rts, comp, mat, depth);
	res = coloradd(&res, &phong_res);
	res = colorpow_f(&res, 1.0f/GAMMA);
	return (res);
}
