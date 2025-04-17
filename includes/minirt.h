/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:59 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/17 23:20:56 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define XK_MISCELLANY
# include <colors.h>
# include <debug.h>
# include <fcntl.h>
# include <object.h>
# include <rays.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <utils.h>
# include <debug.h>
# include <sys/types.h>
# include <dirent.h>
# define WID 800
# define HEG 600
# define SSAA 2

typedef struct s_rtptr
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_alight	*alight;
	t_camera	*camera;
	t_list		*vision_objs;
	t_list		*solid_objs;
	t_list		*objs;
	t_list		*textures_list;
	t_list		*textures;
	int			is_err;
}				t_rtptr;

typedef struct s_shader
{
	t_colors	ambient_c;
	t_colors	effect_c;
	t_colors	diffuse_c;
	t_colors	specular_c;
	t_colors	tmp_diffuse_c;
	t_colors	tmp_specular_c;
	t_tuple		lightv;
	t_tuple		reflectv;
	t_material	*mat;
	float		light_dot_n;
	float		reflect_dot_e;
}				t_shader;

typedef struct s_texture
{
	char			*name;
	mlx_texture_t	*map;
}	t_texture;

enum			e_issues
{
	ERR_ARGS_COUNT,
	ERR_FILE_EXT,
	ERR_OPEN_FILE,
	ERR_OBJ_TYPE,
	ERR_INVALID_FLOAT,
	ERR_INVALID_NFLOAT,
	ERR_INVALID_COEFF,
	ERR_MISSING_TOK,
	ERR_EXTRA_TOK,
	ERR_INVALID_TUPLE,
	ERR_INVALID_RGB,
	ERR_INVALID_COLOR,
	ERR_INVALID_RATIO,
	ERR_INVALID_FOV,
	ERR_UNKNOWN_MISC,
	ERR_UNKNOWN_TEXTURE,
	WARN_CAMERA_MISSING,
	WARN_ALIGHT_MISSING
};

enum			e_validate_tuple
{
	DEFAULT_VALD,
	NORM_VALD,
	COEFFS_VALD
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
void			*hyper_init(void);
// Parser validation
char			**pre_tuple_validation(t_parser *parser);
int				validate_misc(t_parser *parser);
int				validate_iter_vec_misc(t_parser *parser,
					char **split_vec);
char			**pre_vec_validation_misc(t_parser *parser, char *token);
int				validate_phong(t_parser *parser, char *tok);

// Cleaner
void			cleaner(t_rtptr *rts);
// Objects Cleaners
void			free_sphere(t_sphere *sphere);
void			free_plane(t_plane *plane);
void			free_cylinder(t_cylinder *cylinder);
void			free_hyper(t_hyper *hyper);
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
int				prep_transform_m(t_matrix **m);
int				sphere_transform_m(t_sphere *obj);
int				plane_transform_m(t_plane *obj);
int				cylinder_transform_m(t_cylinder *obj);
int				hyper_transform_m(t_hyper *obj);
int				camera_transform_m(t_camera *obj);
int				sphere_postparse(t_rtptr *rts, t_sphere *obj);
int				plane_postparse(t_rtptr *rts, t_plane *obj);
int				cylinder_postparse(t_rtptr *rts, t_cylinder *obj);
int				hyper_postparse(t_rtptr *rts, t_hyper *obj);
int				camera_portparse(t_camera *obj);
int				prep_objs_postparse(t_rtptr *rts);
void			prep_lights_postparse(t_rtptr *rts);
int				handle_missing_objs(t_rtptr *rts);
int				init_misc_sphere(t_sphere *obj);
int				init_misc_plane(t_plane *obj);
int				init_misc_cylinder(t_cylinder *obj);
int				init_misc_hyper(t_hyper *obj);
t_tuple			*phong_props(char *tok);
int				check_init_misc(char *tok,
					void *phong_props, void *color_map, void *bump_map);

// Textures
int				load_textures(t_rtptr *rts);
mlx_texture_t	*get_texture_ref(char *str, t_rtptr *rts);
void			*get_color_map_name(t_object_entry *entry);
void			*get_bump_map_name(t_object_entry *entry);
int				prep_textures_iter(DIR *dir, t_rtptr *rts);
int				prep_textures(t_rtptr *rts);
int				prep_rt_core(int ac, char **av, t_rtptr *rts);

// Render
t_colors		shade_hit(t_alight *alight,
					t_computes *comp, t_list *vision);
int				render_viewport(t_rtptr *rts);
// SSAA

// utils
t_tuple			*pos(void);
t_colors		*color(void);
t_tuple			norm_to_radian(t_tuple *vec);
float			deg_to_rad(float deg);
// Ray utils
t_computes		init_computes(t_rtptr *rts, t_intersect *insect, t_ray *ray);
int				is_shadow(t_rtptr *rts, t_tuple *p);
t_colors		ray_color(t_rtptr *rts, t_ray *ray);
t_uv			compute_plane_uv(t_plane *obj, t_tuple *p);
t_uv			compute_sphere_uv(t_sphere *obj, t_computes *comps);
t_uv			compute_hyper_uv(t_hyper *obj, t_tuple *p);
// Shader Utils
void			shader_vision_iter(t_shader *shader,
					t_computes *comp, t_list *vision_objs);
void			compute_light_props(t_shader *shader,
					t_light *light, t_computes *comp);
t_colors		compute_specular(t_shader *shader, t_light *light);
t_material		*get_material(int obj_type, void *obj);
t_colors		compute_diffuse(t_shader *shader);
t_colors		get_pixel_color(mlx_texture_t *texture, t_uv *uv);
t_colors		get_map_color(void *obj, int obj_type, t_computes *comps);
t_uv			get_uv_coords(void *obj, int obj_type, t_computes *comps);
mlx_texture_t	*get_bump_ref(void *obj, int obj_type);
t_tuple			bump_normal(void *obj, int obj_type, t_computes *comps);

#endif