/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 02:04:39 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/08 19:18:48 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

t_material	init_material(t_colors *colors,
	float diffuse, float specular, float shininess)
{
	t_material	mat;

	mat.color = *colors;
	mat.diffuse = diffuse;
	mat.specular = specular;
	mat.shininess = shininess;
	return (mat);
}

t_material	init_material_misc(t_colors *colors, t_tuple *props)
{
	t_material	mat;

	mat.color = *colors;
	mat.diffuse = props->x;
	mat.specular = props->y;
	mat.shininess = props->z;
	return (mat);
}
