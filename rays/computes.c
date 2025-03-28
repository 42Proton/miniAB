/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 08:22:16 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/28 09:24:52 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_computes	*init_computes(t_intersect *insect, t_ray *ray)
{
	t_computes	*computes;
	t_tuple		*nv;

	computes = malloc(sizeof(t_computes));
	if (!computes)
		return (0);
	computes->isect = insect;
	computes->hpoint = ray_hitpoint(ray, insect->t);
	computes->eyev = tuplenegt(&ray->direction);
	nv = normal_at(insect->obj, insect->obj_type, &computes->hpoint);
	if (!nv)
	{
		free(computes);
		return (0);
	}
	computes->nv = *nv;
	free(nv);
	return (computes);
}
