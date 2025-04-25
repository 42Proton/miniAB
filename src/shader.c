/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:12:04 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/25 03:57:14 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	phong_shader_iter(t_rtptr *rts,
	t_computes *comp, t_phong_shader *shader)
{
	int		shadow_res;
	t_list	*vision_objs;

	vision_objs = rts->vision_objs;
	while (vision_objs)
	{
		shadow_res = is_shadow(rts, &comp->over_point,
				((t_object_entry *)vision_objs->content)->object);
		if (shadow_res == -1)
			return (0);
		if (!shadow_res)
			shader_vision_iter(shader, comp, vision_objs);
		vision_objs = vision_objs->next;
	}
	return (1);
}

t_colors	phong_shader(t_rtptr *rts, t_computes *comp)
{
	t_phong_shader	shader;
	t_colors		res;

	res = color_black();
	shader.mat = get_material(comp->insect->obj_type, comp->insect->obj);
	shader.ambient_c = coloradd(&shader.mat->color, rts->alight->colors);
	shader.ambient_c = coloradd(&shader.ambient_c, &comp->map_color);
	shader.ambient_c = colormulti_f(&shader.ambient_c, rts->alight->ratio);
	shader.specular_c = color_black();
	shader.diffuse_c = color_black();
	if (!phong_shader_iter(rts, comp, &shader))
	{
		comp->is_err = 1;
		return (res);
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
	phong_res = phong_shader(rts, comp);
	if (comp->is_err)
		return (res);
	mat = get_material(comp->insect->obj_type, comp->insect->obj);
	if (mat->reflect > EPSILON)
		res = reflect_shade(rts, comp, mat, depth);
	res = coloradd(&res, &phong_res);
	return (res);
}
