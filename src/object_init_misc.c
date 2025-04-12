/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init_misc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:42:50 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/12 17:48:00 by amsaleh          ###   ########.fr       */
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

int	check_init_misc(char *tok, void *phong_props, void *color_map,
		void *bump_map)
{
	if (!ft_strncmp(tok, "phong:", 6))
	{
		if (!phong_props)
			return (0);
	}
	else if (!ft_strncmp(tok, "color:", 6))
	{
		if (!color_map)
			return (0);
	}
	else if (!ft_strncmp(tok, "bump:", 5))
	{
		if (!bump_map)
			return (0);
	}
	return (1);
}

int	init_misc_sphere(t_sphere *obj)
{
	char	*tok;

	tok = ft_strtok(0, " \t\r\f\v\n");
	while (tok)
	{
		if (!ft_strncmp(tok, "phong:", 6))
			obj->phong_props = phong_props(tok + 6);
		else if (!ft_strncmp(tok, "color:", 6))
			obj->color_map = ft_strdup(tok + 6);
		else if (!ft_strncmp(tok, "bump:", 5))
			obj->bump_map = ft_strdup(tok + 5);
		if (!check_init_misc(tok, obj->phong_props, obj->color_map,
				obj->bump_map))
			return (0);
		tok = ft_strtok(0, " \t\r\f\v\n");
	}
	return (1);
}

int	init_misc_plane(t_plane *obj)
{
	char	*tok;

	tok = ft_strtok(0, " \t\r\f\v\n");
	while (tok)
	{
		if (!ft_strncmp(tok, "phong:", 6))
			obj->phong_props = phong_props(tok + 6);
		else if (!ft_strncmp(tok, "color:", 6))
			obj->color_map = ft_strdup(tok + 6);
		else if (!ft_strncmp(tok, "bump:", 5))
			obj->bump_map = ft_strdup(tok + 5);
		if (!check_init_misc(tok, obj->phong_props, obj->color_map,
				obj->bump_map))
			return (0);
		tok = ft_strtok(0, " \t\r\f\v\n");
	}
	return (1);
}

int	init_misc_cylinder(t_cylinder *obj)
{
	char	*tok;

	tok = ft_strtok(0, " \t\r\f\v\n");
	while (tok)
	{
		if (!ft_strncmp(tok, "phong:", 6))
			obj->phong_props = phong_props(tok + 6);
		else if (!ft_strncmp(tok, "color:", 6))
			obj->color_map = ft_strdup(tok + 6);
		else if (!ft_strncmp(tok, "bump:", 5))
			obj->bump_map = ft_strdup(tok + 5);
		if (!check_init_misc(tok, obj->phong_props, obj->color_map,
				obj->bump_map))
			return (0);
		tok = ft_strtok(0, " \t\r\f\v\n");
	}
	return (1);
}

int	init_misc_hyper(t_hyper *obj)
{
	char	*tok;

	tok = ft_strtok(0, " \t\r\f\v\n");
	while (tok)
	{
		if (!ft_strncmp(tok, "phong:", 6))
			obj->phong_props = phong_props(tok + 6);
		else if (!ft_strncmp(tok, "color:", 6))
			obj->color_map = ft_strdup(tok + 6);
		else if (!ft_strncmp(tok, "bump:", 5))
			obj->bump_map = ft_strdup(tok + 5);
		if (!check_init_misc(tok, obj->phong_props, obj->color_map,
				obj->bump_map))
			return (0);
		tok = ft_strtok(0, " \t\r\f\v\n");
	}
	return (1);
}
