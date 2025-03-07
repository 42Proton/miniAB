/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:33:42 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/04 01:57:04 by abueskander      ###   ########.fr       */
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