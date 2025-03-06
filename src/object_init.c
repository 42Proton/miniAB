/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:10:32 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/07 00:17:19 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	*sphere_init()
{
	t_sphere	*sphere;
	
	sphere = ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
		return (0);
	sphere->pos = init_vector();
	sphere->dim = ft_atof(ft_strtok(0, " \t\r\f\v"));
	sphere->colors = init_colors();
	if (!sphere->colors || !sphere->pos)
	{
		free_sphere(sphere);
		return (0);
	}
	return (sphere);
}

void	*plane_init()
{
	t_plane	*plane;

	plane = ft_calloc(1, sizeof(t_plane));
	if (!plane)
		return (0);
	plane->pos = init_vector();
	plane->normal_vector = init_vector();
	plane->colors = init_colors();
	if (!plane->colors || !plane->normal_vector || !plane->pos)
	{
		free_plane(plane);
		return (0);
	}
	return (plane);
}

void	*cylinder_init()
{
	t_cylinder	*cylinder;

	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
		return (0);
	cylinder->pos = init_vector();
	cylinder->normal_axis = init_vector();
	cylinder->dim = ft_atof(ft_strtok(0, " \t\r\f\v"));
	cylinder->height = ft_atof(ft_strtok(0, " \t\r\f\v"));
	cylinder->colors = init_colors();
	if (!cylinder->colors || !cylinder->normal_axis || !cylinder->pos)
	{
		free_cylinder(cylinder);
		return (0);
	}
	return (cylinder);
}
