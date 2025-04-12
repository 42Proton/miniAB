/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:12:04 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/12 12:43:02 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_colors	shade_hit(t_alight *alight, t_computes *comp, t_list *vision_objs)
{
	t_shader	shader;
	t_colors	res;

	shader.mat = get_material(comp->insect->obj_type, comp->insect->obj);
	shader.ambient_c = coloradd(&shader.mat->color, alight->colors);
	shader.ambient_c = coloravg(&shader.ambient_c, &comp->map_color);
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
