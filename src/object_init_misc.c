/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init_misc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:42:50 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/19 23:14:23 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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
		else if (!ft_strncmp(tok, "reflect:", 8))
			obj->reflect = ft_atof(tok + 8);
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
		else if (!ft_strncmp(tok, "reflect:", 8))
			obj->reflect = ft_atof(tok + 8);
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
		else if (!ft_strncmp(tok, "reflect:", 8))
			obj->reflect = ft_atof(tok + 8);
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
		else if (!ft_strncmp(tok, "reflect:", 8))
			obj->reflect = ft_atof(tok + 8);
		if (!check_init_misc(tok, obj->phong_props, obj->color_map,
				obj->bump_map))
			return (0);
		tok = ft_strtok(0, " \t\r\f\v\n");
	}
	return (1);
}
