/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:10:32 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/12 00:11:26 by bismail          ###   ########.fr       */
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
	sphere->mat = init_material(colors, 1, 1, 200);
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
	plane->normal_vector = pos();
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
	cylinder->normal_axis = pos();
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
	free(colors);
	return (cylinder);
}
