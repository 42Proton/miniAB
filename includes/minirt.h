/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:59 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/07 00:23:22 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#define XK_MISCELLANY
#include <libft.h>
#include <utils.h>
#include <colors.h>
#include <object.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <MLX42/MLX42.h>
#include <stdio.h>
#define WID 1000
#define HEG 720

typedef struct s_rtptr
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_list		*objs;
}	t_rtptr;

typedef struct s_object_entry
{
	void	*object;
	int		type;
}	t_object_entry;

enum		e_types_of_objects
{
	AMBIENTLIGHT,
	LIGHT,
	CAMERA,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	HYPER,
	PARA
};

enum	e_issues
{
	ERR_ARGS_COUNT,
	ERR_FILE_EXT,
	ERR_OPEN_FILE,
	ERR_OBJ_TYPE,
	ERR_INVALID_FLOAT,
	ERR_MISSING_TOK,
	ERR_EXTRA_TOK,
};

// Parser
int		parser(char *, t_rtptr *);
t_object_entry	*objectify(t_parser *, int);
void		*ambient_light(t_parser *, int *);
void		*sphere_init();
void		*plane_init();
void		*cylinder_init();
// Cleaner
void		cleaner(t_rtptr *);
// Objects Cleaners
void	free_sphere(t_sphere *sphere);
void	free_plane(t_plane *plane);
void	free_cylinder(t_cylinder *cylinder);
// Issues Reporters
void	simple_report(int);
void	issue_report(t_parser *, int);

// Hooks
void    keyhook(struct mlx_key_data, void *);

// Initalization
int			check_args(int, char **);
int			init_mlx_pointers(t_rtptr *);

#endif