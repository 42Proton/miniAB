/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:33:42 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/05 02:56:59 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_object	*objectify(int type)
{
	t_object *object;

	object = ft_calloc(1, sizeof(t_object));
	if (!object)
		return (NULL);
	if (type == AMBIENTLIGHT)
		object->object = ambient_light();
	return (object);
}
