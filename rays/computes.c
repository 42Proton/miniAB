/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 08:22:16 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/28 20:43:53 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_computes	init_computes(t_intersect *insect, t_ray *ray)
{
	t_computes	computes;

	computes.isect = insect;
 	computes.hpoint = ray_hitpoint(ray, insect->t);
 	computes.eyev = tuplenegt(&ray->direction);
 	computes.nv = normal_at(insect->obj, insect->obj_type, &computes.hpoint);
	return (computes);
}
