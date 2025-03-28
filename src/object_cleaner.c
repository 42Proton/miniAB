/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:59:44 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/28 09:29:31 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	free_sphere(t_sphere *sphere)
{
	free(sphere->pos);
	free_matrix(sphere->transform);
	free_matrix(sphere->inv_t);
	free(sphere);
}

void	free_plane(t_plane *plane)
{
	free(plane->pos);
	free(plane->normal_vector);
	free_matrix(plane->transform);
	free_matrix(plane->inv_t);
	free(plane);
}

void	free_cylinder(t_cylinder *cylinder)
{
	free(cylinder->pos);
	free(cylinder->normal_axis);
	free_matrix(cylinder->transform);
	free_matrix(cylinder->inv_t);
	free(cylinder);
}
