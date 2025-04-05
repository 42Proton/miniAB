/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:12:04 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/05 13:12:25 by amsaleh          ###   ########.fr       */
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

	diffuse_c = colormulti_f(&shader->effect_c, shader->mat->diffuse);
	diffuse_c = colormulti_f(&diffuse_c, shader->light_dot_n);
	return (diffuse_c);
}

t_colors	compute_specular(t_shader *shader, t_light *light)
{
	float		factor;
	t_colors	specular_c;

	factor = pow(shader->reflect_dot_e, shader->mat->shininess);
	specular_c = colormulti_f(light->colors, light->ratio);
	specular_c = colormulti_f(&specular_c, shader->mat->specular);
	specular_c = colormulti_f(&specular_c, factor);
	return (specular_c);
}

t_colors	shade_hit(t_alight *alight, t_computes *comp, t_light *light)
{
	t_shader	shader;
	t_colors	res;

	shader.mat = get_material(comp->insect->obj_type, comp->insect->obj);
	shader.effect_c = colormulti_f(&shader.mat->color, light->ratio);
	shader.ambient_c = colormulti_f(&shader.mat->color, alight->ratio);
	shader.lightv = n_tuplesub(light->pos, &comp->hpoint);
	shader.lightv = tuplenormalize(&shader.lightv);
	shader.light_dot_n = tupledot(&shader.lightv, &comp->nv);
	if (shader.light_dot_n < 0)
		shader.diffuse_c = colorinit(0, 0, 0);
	else
		shader.diffuse_c = compute_diffuse(&shader);
	shader.lightv = tuplenegt(&shader.lightv);
	shader.reflectv = reflect_vec(&shader.lightv, &comp->nv);
	shader.reflect_dot_e = tupledot(&shader.reflectv, &comp->eyev);
	if (shader.reflect_dot_e <= 0)
		shader.specular_c = colorinit(0, 0, 0);
	else
		shader.specular_c = compute_specular(&shader, light);
	res = coloradd(&shader.ambient_c, &shader.diffuse_c);
	res = coloradd(&res, &shader.specular_c);
	return (res);
}
