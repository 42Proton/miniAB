/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:41:23 by bismail           #+#    #+#             */
/*   Updated: 2025/04/17 16:01:57 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>
#include <debug.h>

int     disk_intersection(t_intersections *insects,t_object_entry *object, t_ray *ray)
{
        t_plane plane;

        plane.inv_t = ((t_cylinder*)(object->object))->inv_t;
        plane.pos = ((t_cylinder*)(object->object))->pos;
        plane.pos->y += ((t_cylinder*)(object->object))->height / 2;
        
}