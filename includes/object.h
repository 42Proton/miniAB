/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:04:22 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/17 16:04:58 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

// includes
# include <MLX42/MLX42.h>
# include <colors.h>

enum			e_types_of_objects
{
	AMBIENTLIGHT,
	LIGHT,
	CAMERA,
	SPHERE,
	PLANE,
	CYLINDER,
	HYPER
};

typedef struct s_object_entry
{
	void		*object;
	int			type;
}				t_object_entry;

typedef struct s_tuple
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_tuple;

typedef struct s_matrix
{
	int			cols;
	int			rows;
	float		*data;
}				t_matrix;

typedef struct s_matrix_9
{
	int			cols;
	int			rows;
	float		data[9];
}				t_matrix_9;

typedef struct s_matrix_4
{
	int			cols;
	int			rows;
	float		data[4];
}				t_matrix_4;

typedef struct s_material
{
	t_colors	color;
	float		diffuse;
	float		specular;
	float		shininess;
}	t_material;

typedef struct s_alight
{
	float		ratio;
	t_colors	*colors;
}				t_alight;

typedef struct s_camera
{
	t_tuple		*pos;
	t_tuple		*orientation;
	t_matrix	*transform;
	t_matrix	*inv_t;
	float		fov;
	float		hwidth;
	float		hheight;
	float		pixel_size;
}				t_camera;

typedef struct s_light
{
	t_tuple		*pos;
	float		ratio;
	t_colors	*colors;
}				t_light;

typedef struct s_sphere
{
	t_tuple			*pos;
	float			dim;
	t_material		mat;
	t_tuple			*phong_props;
	char			*color_map;
	char			*bump_map;
	mlx_texture_t	*color_map_ref;
	mlx_texture_t	*bump_map_ref;
	t_matrix		*transform;
	t_matrix		*inv_t;
	t_matrix		*tpose_inv_t;
}				t_sphere;

typedef struct s_hyper
{
	t_tuple			*pos;
	t_tuple			*scale;
	t_tuple			*coeffs;
	t_tuple			coeffs2;
	t_tuple			*nv;
	t_material		mat;
	t_tuple			*phong_props;
	char			*color_map;
	char			*bump_map;
	mlx_texture_t	*color_map_ref;
	mlx_texture_t	*bump_map_ref;
	t_matrix		*transform;
	t_matrix		*inv_t;
	t_matrix		*tpose_inv_t;
}				t_hyper;

typedef struct s_plane
{
	t_tuple			*pos;
	t_tuple			*normal_vector;
	t_material		mat;
	t_tuple			*phong_props;
	char			*color_map;
	char			*bump_map;
	mlx_texture_t	*color_map_ref;
	mlx_texture_t	*bump_map_ref;
	t_matrix		*transform;
	t_matrix		*inv_t;
	t_matrix		*tpose_inv_t;
}				t_plane;

typedef struct s_cylinder
{
	t_tuple			*pos;
	t_tuple			*normal_axis;
	float			dim;
	float			height;
	t_material		mat;
	t_tuple			*phong_props;
	char			*color_map;
	char			*bump_map;
	mlx_texture_t	*color_map_ref;
	mlx_texture_t	*bump_map_ref;
	t_matrix		*transform;
	t_matrix		*inv_t;
	t_matrix		*tpose_inv_t;
}				t_cylinder;

typedef struct s_uv
{
	float	u;
	float	v;
}	t_uv;

enum			e_pov
{
	VECTOR,
	POINT
};

int				floatcmp(float a, float b);
int				tuplecmp(t_tuple *a, t_tuple *b);

// Modify Old instance
void			tuplesub(t_tuple *a, t_tuple *b);
void			tupleadd(t_tuple *a, t_tuple *b);
void			tuplesdiv(t_tuple *a, float scale);
void			tuplesmult(t_tuple *a, float scale);
// New instance
t_tuple			n_tuplesdiv(t_tuple *a, float scale);
t_tuple			n_tuplesmult(t_tuple *a, float scale);
t_tuple			n_tuplesub(t_tuple *a, t_tuple *b);
t_tuple			n_tupleadd(t_tuple *a, t_tuple *b);
t_tuple			vector(float x, float y, float z);
t_tuple			point(float x, float y, float z);
t_tuple			tuplenegt(t_tuple *a);
float			tuplemagnitude(t_tuple *a);
float			tupledot(t_tuple *a, t_tuple *b);
t_tuple			tuplecross(t_tuple *a, t_tuple *b);
t_tuple			tuplenormalize(t_tuple *a);
// Stack Argument
t_tuple			s_tuplesub(t_tuple a, t_tuple b);

// Matrix functions
int				is_invertible(t_matrix *m);
t_matrix		*matrix_inverse(t_matrix *m);
t_matrix		*get_submatrix(t_matrix *m, int skip_row, int skip_col);
t_matrix		*matrix_transpose(t_matrix *m);
t_matrix		*matrix_copy(t_matrix *m);
float			determinant(t_matrix *m);
float			determinant2x2(t_matrix *m);
float			s_determinant_3x3(t_matrix_9 *m);
int				matrix_multiply(t_matrix *a, t_matrix *b);
t_tuple			matrix_mult_t(t_matrix *m, t_tuple *t);
int				matrix_equal(t_matrix *a, t_matrix *b);
t_tuple			transform_f(t_matrix *m, t_tuple *vec);
// Matrix Utils
size_t			get_mindex(t_matrix *m, int col, int row);
float			*get_melem(t_matrix *m, int col, int row);
void			set_matrix_elem(t_matrix *m, int col, int row, float val);
float			get_matrix_elem(t_matrix *m, int col, int row);
t_matrix		*matrix_init(int cols, int rows);
void			free_matrix(t_matrix *m);
t_matrix_9		submatrix_3x3(t_matrix *m,
					int skip_col, int skip_row);
t_matrix		*ident_matrix4x4(void);
t_matrix_4		submatrix_2x2(t_matrix *m, int skip_col, int skip_row);
t_matrix		*translation_m(t_tuple *pos);
t_matrix		*rotation_m(t_tuple *vec);
t_matrix		*scale_m(t_tuple *vec);
t_matrix		*lookat_m(t_tuple *from, t_tuple *to);
// Material
t_material		init_material(t_colors *colors,
					float diffuse, float specular, float shininess);
t_material		init_material_misc(t_colors *colors, t_tuple *props);

#endif