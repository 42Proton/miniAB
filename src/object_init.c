/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:10:32 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/22 14:01:59 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	*sphere_init(void)
{
	t_sphere	*sphere;
	t_colors	*colors;

	sphere = ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
		return (0);
	sphere->pos = pos();
	sphere->dim = ft_atof(ft_strtok(0, " \t\r\f\v\n"));
	colors = color();
	if (!colors || !sphere->pos || !init_misc_sphere(sphere))
	{
		free_sphere(sphere);
		free(colors);
		return (0);
	}
	if (sphere->phong_props)
		sphere->mat = init_material_misc(colors, sphere->phong_props);
	else
		sphere->mat = init_material(colors, 1, 1, 200);
	sphere->mat.reflect = sphere->reflect;
	free(colors);
	return (sphere);
}

void	*plane_init(void)
{
	t_plane		*plane;
	t_colors	*colors;

	plane = ft_calloc(1, sizeof(t_plane));
	if (!plane)
		return (0);
	plane->pos = pos();
	plane->normal_vector = norm_vec();
	colors = color();
	if (!colors || !plane->normal_vector
		|| !plane->pos || !init_misc_plane(plane))
	{
		free_plane(plane);
		free(colors);
		return (0);
	}
	if (plane->phong_props)
		plane->mat = init_material_misc(colors, plane->phong_props);
	else
		plane->mat = init_material(colors, 1, 1, 200);
	plane->mat.reflect = plane->reflect;
	free(colors);
	return (plane);
}

void	*cylinder_init(void)
{
	t_cylinder	*cylinder;
	t_colors	*colors;

	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
		return (0);
	cylinder->pos = pos();
	cylinder->normal_axis = norm_vec();
	cylinder->dim = ft_atof(ft_strtok(0, " \t\r\f\v\n"));
	cylinder->height = ft_atof(ft_strtok(0, " \t\r\f\v\n"));
	colors = color();
	if (!colors || !cylinder->normal_axis
		|| !cylinder->pos || !init_misc_cylinder(cylinder))
	{
		free_cylinder(cylinder);
		free(colors);
		return (0);
	}
	cylinder->mat = init_material(colors, 1, 1, 200);
	cylinder->mat.reflect = cylinder->reflect;
	free(colors);
	return (cylinder);
}

void	*hyper_init(void)
{
	t_hyper		*hyper;
	t_colors	*colors;

	hyper = ft_calloc(1, sizeof(t_hyper));
	if (!hyper)
		return (0);
	hyper->pos = pos();
	hyper->scale = pos();
	hyper->nv = norm_vec();
	hyper->coeffs = pos();
	colors = color();
	if (!colors || !hyper->pos
		|| !hyper->scale || !hyper->nv || !init_misc_hyper(hyper))
	{
		free_hyper(hyper);
		free(colors);
		return (0);
	}
	if (hyper->phong_props)
		hyper->mat = init_material_misc(colors, hyper->phong_props);
	else
		hyper->mat = init_material(colors, 1, 1, 200);
	hyper->mat.reflect = hyper->reflect;
	free(colors);
	return (hyper);
}
