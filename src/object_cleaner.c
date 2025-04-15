/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:59:44 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/15 23:10:09 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	free_sphere(t_sphere *sphere)
{
	free(sphere->pos);
	free(sphere->phong_props);
	free(sphere->color_map);
	free(sphere->bump_map);
	free_matrix(sphere->transform);
	free_matrix(sphere->inv_t);
	free_matrix(sphere->tpose_inv_t);
	free(sphere);
}

void	free_plane(t_plane *plane)
{
	free(plane->pos);
	free(plane->normal_vector);
	free(plane->phong_props);
	free(plane->color_map);
	free(plane->bump_map);
	free_matrix(plane->transform);
	free_matrix(plane->inv_t);
	free_matrix(plane->tpose_inv_t);
	free(plane);
}

void	free_cylinder(t_cylinder *cylinder)
{
	free(cylinder->pos);
	free(cylinder->normal_axis);
	free(cylinder->phong_props);
	free(cylinder->color_map);
	free(cylinder->bump_map);
	free_matrix(cylinder->transform);
	free_matrix(cylinder->inv_t);
	free_matrix(cylinder->tpose_inv_t);
	free(cylinder);
}

void	free_hyper(t_hyper *hyper)
{
	free(hyper->pos);
	free(hyper->scale);
	free(hyper->nv);
	free(hyper->coeffs);
	free(hyper->phong_props);
	free(hyper->color_map);
	free(hyper->bump_map);
	free_matrix(hyper->transform);
	free_matrix(hyper->inv_t);
	free_matrix(hyper->tpose_inv_t);
	free(hyper);
}
