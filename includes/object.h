/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:04:22 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/21 01:24:17 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

// includes
# include <colors.h>

// defintions
# define EPSILON 0.00001

enum			e_types_of_objects
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
	int		cols;
	int		rows;
	float	*data;
}				t_matrix;

typedef struct s_matrix_9
{
	int		cols;
	int		rows;
	float	data[9];
}				t_matrix_9;

typedef struct s_alight
{
	float		ratio;
	t_colors	*colors;
}				t_alight;

typedef struct s_camera
{
	t_tuple		*pos;
	t_tuple		*orientation;
	float		fov;
}				t_camera;

typedef struct s_light
{
	t_tuple		*pos;
	float		brightness;
	t_colors	*colors;
}				t_light;

typedef struct s_sphere
{
	t_tuple		*pos;
	float		dim;
	t_colors	*colors;
}				t_sphere;

typedef struct s_plane
{
	t_tuple		*pos;
	t_tuple		*normal_vector;
	t_colors	*colors;
}				t_plane;

typedef struct s_cylinder
{
	t_tuple		*pos;
	t_tuple		*normal_axis;
	float		dim;
	float		height;
	t_colors	*colors;
}				t_cylinder;

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

// Matrix functions
t_matrix		*get_submatrix(t_matrix *m, int skip_row, int skip_col);
t_matrix		*matrix_transpose(t_matrix *m);
t_matrix		*matrix_copy(t_matrix *m);
float			determinant(t_matrix *m);
float			determinant2x2(t_matrix *m);
int				matrix_multiply(t_matrix *a, t_matrix *b);
int				matrix_equal(t_matrix *a, t_matrix *b);
t_tuple			transform_f(t_matrix *tmatrix, t_tuple *vec);
// Matrix Utils
size_t			get_mindex(t_matrix *m, size_t col, size_t row);
float			*get_melem(t_matrix *m, size_t col, size_t row);
void			set_matrix_elem(t_matrix *m, size_t col, size_t row, float val);
float			get_matrix_elem(t_matrix *m, size_t col, size_t row);
t_matrix		*matrix_init(size_t cols, size_t rows);
void			free_matrix(t_matrix *m);
t_matrix_9		submatrix_3x3(t_matrix *m,
	int skip_col, int skip_row);

#endif