/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:59:44 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/23 03:00:01 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	free_sphere(t_sphere *sphere)
{
	free(sphere->pos);
	free(sphere->colors);
	free_matrix(sphere->transform);
	free(sphere);
}

void	free_plane(t_plane *plane)
{
	free(plane->pos);
	free(plane->normal_vector);
	free(plane->colors);
	free_matrix(plane->transform);
	free(plane);
}

void	free_cylinder(t_cylinder *cylinder)
{
	free(cylinder->pos);
	free(cylinder->normal_axis);
	free(cylinder->colors);
	free_matrix(cylinder->transform);
	free(cylinder);
}
