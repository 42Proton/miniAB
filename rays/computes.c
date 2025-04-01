/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 08:22:16 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/01 15:33:16 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_computes	init_computes(t_intersect *insect, t_ray *ray)
{
	t_computes	computes;
	float		dot_nv_e;

	computes.insect = insect;
 	computes.hpoint = ray_hitpoint(ray, insect->t);
 	computes.eyev = tuplenegt(&ray->direction);
 	computes.nv = normal_at(insect->obj, insect->obj_type, &computes.hpoint);
	dot_nv_e = tupledot(&computes.nv, &computes.eyev);
	if (dot_nv_e < 0)
		computes.nv = tuplenegt(&computes.nv);
	computes.eyev = tuplenormalize(&computes.eyev);
	return (computes);
}
