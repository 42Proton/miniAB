/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:10:32 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/07 01:15:11 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	*sphere_init(void)
{
	t_sphere	*sphere;

	sphere = ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
		return (0);
	sphere->pos = pos();
	sphere->dim = ft_atof(ft_strtok(0, " \t\r\f\v"));
	sphere->colors = color();
	if (!sphere->colors || !sphere->pos)
	{
		free_sphere(sphere);
		return (0);
	}
	return (sphere);
}

void	*plane_init(void)
{
	t_plane	*plane;

	plane = ft_calloc(1, sizeof(t_plane));
	if (!plane)
		return (0);
	plane->pos = pos();
	plane->normal_vector = pos();
	plane->colors = color();
	if (!plane->colors || !plane->normal_vector || !plane->pos)
	{
		free_plane(plane);
		return (0);
	}
	return (plane);
}

void	*cylinder_init(void)
{
	t_cylinder	*cylinder;

	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
		return (0);
	cylinder->pos = pos();
	cylinder->normal_axis = pos();
	cylinder->dim = ft_atof(ft_strtok(0, " \t\r\f\v"));
	cylinder->height = ft_atof(ft_strtok(0, " \t\r\f\v"));
	cylinder->colors = color();
	if (!cylinder->colors || !cylinder->normal_axis || !cylinder->pos)
	{
		free_cylinder(cylinder);
		return (0);
	}
	return (cylinder);
}
