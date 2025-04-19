/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:00:36 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/19 01:41:02 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# define POINT_BIAS 0.2

# include <object.h>

typedef struct s_intersect
{
	int			obj_type;
	void		*obj;
	float		t;
}				t_intersect;

typedef struct s_intersections
{
	size_t		count;
	t_list		*lst;
}				t_intersections;

typedef struct s_computes
{
	t_intersect	*insect;
	t_tuple		hpoint;
	t_tuple		eyev;
	t_tuple		nv;
	t_tuple		p_nv;
	t_tuple		over_point;
	t_colors	map_color;
	t_uv		uv;
	int			is_shadow;
	int			is_err;
}				t_computes;

typedef struct s_quad_eq
{
	float		a;
	float		b;
	float		c;
	float		discriminant;
}				t_quad_eq;

typedef struct s_ray
{
	t_tuple		origin;
	t_tuple		direction;
}				t_ray;

typedef struct s_ray_pixel
{
	float	world_x;
	float	world_y;
	t_tuple	world_origin;
	t_tuple	world_point;
	t_ray	ray;
	t_tuple	ray_direction;
}	t_ray_pixel;

typedef struct s_shadow
{
	t_intersections	*insects;
	t_intersect		*insect;
	t_tuple			v;
	t_tuple			direction;
	t_light			*light;
	t_list			*vision_objs;
	t_ray			ray;
	float			dist;
}	t_shadow;

// Intersection Utils
void			add_intersection_sorted(t_intersections *res, t_list *node);
int				add_intersection(t_intersections *res, float t,
					t_object_entry *obj_entry);
void			clear_intersections(t_intersections *data);
int				sphere_intersect(t_intersections *insects,
					t_object_entry *obj_entry, t_ray *ray);
int				plane_intersect(t_intersections *insects,
					t_object_entry *object, t_ray *ray);
int				hyper_intersect(t_intersections *insects,
					t_object_entry *obj_entry, t_ray *ray);
t_intersect		*get_hit(t_intersections *data);
t_intersections	*world_intersect(t_list *solid_objs, t_ray *ray);
// Ray Utils
t_ray			init_ray(t_tuple *origin, t_tuple *direction);
t_tuple			ray_hitpoint(t_ray *ray, float t);
t_ray			transform_ray(t_matrix *m, t_ray *ray);
t_tuple			sphere_normal(t_sphere *obj, t_tuple *p);
t_tuple			reflect_vec(t_tuple *vec, t_tuple *norm);
t_tuple			normal_at(void *obj, int obj_type, t_tuple *p);

#endif