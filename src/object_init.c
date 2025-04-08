/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:10:32 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/08 19:42:12 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	*phong_props(char *tok)
{
	char	**split_vec;
	t_tuple	*res;

	split_vec = ft_split(tok, ',');
	if (!split_vec)
		return (0);
	res = malloc(sizeof(t_tuple));
	if (!res)
	{
		free_array((void **)split_vec);
		return (0);
	}
	*res = point(ft_atof(split_vec[0]), ft_atof(split_vec[1]),
			ft_atof(split_vec[2]));
	free_array((void **)split_vec);
	return (res);
}

int		init_misc_plane(t_plane *obj)
{
	char	*tok;

	tok = ft_strtok(0, " \t\r\f\v\n");
	while (tok)
	{
		if (!ft_strncmp(tok, "phong:", 6))
		{
			obj->phong_props = phong_props(tok + 6);
			if (!obj->phong_props)
				return (0);
		}
		if (!ft_strncmp(tok, "color:", 6))
		{
			obj->color_map = ft_strdup(tok + 6);
			if (!obj->color_map)
				return (0);
		}
		if (!ft_strncmp(tok, "bump:", 5))
		{
			obj->bump_map = ft_strdup(tok + 5);
			if (!obj->bump_map)
				return (0);
		}
		tok = ft_strtok(0, " \t\r\f\v\n");
	}
	return (1);
}

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
	if (!colors || !sphere->pos)
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
	{
		debug_tuple(plane->phong_props);
		plane->mat = init_material_misc(colors, plane->phong_props);
	}
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
	if (!colors || !cylinder->normal_axis || !cylinder->pos)
	{
		free_cylinder(cylinder);
		free(colors);
		return (0);
	}
	cylinder->mat = init_material(colors, 1, 1, 200);
	free(colors);
	return (cylinder);
}
