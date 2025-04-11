/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:12:04 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/11 22:07:48 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_material	*get_material(int obj_type, void *obj)
{
	t_material	*mat;

	mat = 0;
	if (obj_type == SPHERE)
		mat = &((t_sphere *)obj)->mat;
	else if (obj_type == PLANE)
		mat = &((t_plane *)obj)->mat;
	else if (obj_type == CYLINDER)
		mat = &((t_cylinder *)obj)->mat;
	return (mat);
}

t_colors	compute_diffuse(t_shader *shader)
{
	t_colors	diffuse_c;

	if (shader->light_dot_n < 0)
	{
		diffuse_c = colorinit(0, 0, 0);
		return (diffuse_c);
	}
	diffuse_c = colormulti_f(&shader->effect_c, shader->mat->diffuse);
	diffuse_c = colormulti_f(&diffuse_c, shader->light_dot_n);
	return (diffuse_c);
}

t_colors	compute_specular(t_shader *shader, t_light *light)
{
	float		factor;
	t_colors	specular_c;

	if (shader->reflect_dot_e <= 0)
	{
		specular_c = colorinit(0, 0, 0);
		return (specular_c);
	}
	factor = pow(shader->reflect_dot_e, shader->mat->shininess);
	specular_c = colormulti_f(light->colors, light->ratio);
	specular_c = colormulti_f(&specular_c, shader->mat->specular);
	specular_c = colormulti_f(&specular_c, factor);
	return (specular_c);
}

void	compute_light_props(t_shader *shader,
	t_light *light, t_computes *comp)
{
	t_tuple	tmp;

	shader->effect_c = coloradd(&shader->mat->color, light->colors);
	shader->effect_c = coloravg(&shader->effect_c, &comp->map_color);
	shader->effect_c = colormulti_f(&shader->effect_c, light->ratio);
	shader->lightv = n_tuplesub(light->pos, &comp->hpoint);
	shader->lightv = tuplenormalize(&shader->lightv);
	shader->light_dot_n = tupledot(&shader->lightv, &comp->nv);
	tmp = tuplenegt(&shader->lightv);
	shader->reflectv = reflect_vec(&tmp, &comp->nv);
	shader->reflect_dot_e = tupledot(&shader->reflectv, &comp->eyev);
}

t_colors	shade_hit(t_alight *alight, t_computes *comp, t_list *vision_objs)
{
	t_shader	shader;
	t_colors	res;
	t_light		*light;

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
		light = ((t_object_entry *)vision_objs->content)->object;
		if (light->ratio)
		{
			compute_light_props(&shader, light, comp);
			shader.tmp_diffuse_c = compute_diffuse(&shader);
			shader.tmp_specular_c = compute_specular(&shader, light);
			shader.diffuse_c = coloradd(&shader.diffuse_c, &shader.tmp_diffuse_c);
			shader.specular_c = coloradd(&shader.specular_c, &shader.tmp_specular_c);
		}
		vision_objs = vision_objs->next;
	}	
	res = coloradd(&shader.ambient_c, &shader.diffuse_c);
	res = coloradd(&res, &shader.specular_c);
	return (res);
}
