/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:59 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/23 03:13:33 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define XK_MISCELLANY
# include <MLX42/MLX42.h>
# include <colors.h>
# include <fcntl.h>
# include <libft.h>
# include <object.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <utils.h>
# include <rays.h>
# define WID 800
# define HEG 800

typedef struct s_rtptr
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_camera	*camera;
	t_list		*vision_objs;
	t_list		*objs;
}				t_rtptr;

enum			e_issues
{
	ERR_ARGS_COUNT,
	ERR_FILE_EXT,
	ERR_OPEN_FILE,
	ERR_OBJ_TYPE,
	ERR_INVALID_FLOAT,
	ERR_INVALID_NFLOAT,
	ERR_MISSING_TOK,
	ERR_EXTRA_TOK,
	ERR_INVALID_VEC,
	ERR_INVALID_RGB,
	ERR_INVALID_COLOR,
	ERR_INVALID_RATIO,
	ERR_INVALID_FOV
};

// Object Utils
void			split_objs(t_rtptr *rts);
// Parser
int				parser(char *file_name, t_rtptr *rts);
t_object_entry	*objectify(t_parser *parser, int type);
void			*ambient_light_init(void);
void			*light_init(void);
void			*camera_init(void);
void			*sphere_init(void);
void			*plane_init(void);
void			*cylinder_init(void);
// Cleaner
void			cleaner(t_rtptr *rts);
// Objects Cleaners
void			free_sphere(t_sphere *sphere);
void			free_plane(t_plane *plane);
void			free_cylinder(t_cylinder *cylinder);
// Vision Cleaners
void			free_ambient(t_alight *al);
void			free_light(t_light *light);
void			free_camera(t_camera *camera);
// Issues Reporters
void			simple_report(int issue);
void			issue_report(t_parser *parser, int issue);

// Hooks
void			keyhook(struct mlx_key_data keydata, void *rts);

// Initalization
int				check_args(int ac, char **av);
int				init_mlx(t_rtptr *rts);

// Debug Utils
void		debug_tuple(t_tuple *tuple);
void		matrix_debug(t_matrix *m);
t_colors	ray_color(t_rtptr *rts, t_ray *ray);
int			prep_transform_m(t_matrix **m);
int			prep_objs_transform(t_rtptr *rts);

// utils
t_tuple			*pos(void);
t_colors		*color(void);
#endif