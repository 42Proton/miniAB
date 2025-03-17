/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:00:36 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/17 22:00:51 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

#include <libft.h>
#include <object.h>

typedef struct s_intersect
{
	int		obj_type;
	void	*obj;
	float	t;
}	t_intersect;

typedef struct s_intersections
{
	size_t	count;
	t_list	*lst;
}	t_intersections;

typedef struct s_quad_eq
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
}	t_quad_eq;

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

//Intersection Utils
void			add_intersection_sorted(t_intersections *res,
					t_list *node);
int				add_intersection(t_intersections *res,
					float t, t_object_entry *obj_entry);
void			clear_intersections(t_intersections *data);
t_intersections	*sphere_intersect(t_object_entry *obj_entry, t_ray *ray);
t_intersect		*get_hit(t_intersections *data);
//Ray Utils
t_ray			init_ray(t_tuple *origin, t_tuple *direction);
t_tuple			ray_hitpoint(t_ray *ray, float t);

#endif