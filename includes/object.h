/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:04:22 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/04 01:50:54 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

// includes
# include <colors.h>
# include <math.h>
# include <utils.h>
// defintions
# define EPSILON 0.00001
# define PI 3.14159

typedef struct s_tuple
{
	float		X;
	float		Y;
	float		Z;
	float		W;
}				t_tuple;

typedef struct s_matrix
{
	// TODO
}				t_matrix;

typedef struct s_alight
{
	float		ratio;
	t_colors	colors;
}				t_alight;

typedef struct s_camera
{
	t_tuple		pos;
	t_tuple		orientation;
	float		fov;
}				t_camera;

typedef struct s_light
{
	t_tuple		pos;
	float		brightness;
	t_colors	colors;
}				t_light;

typedef struct s_sphere
{
	t_tuple		pos;
	float		dim;
	t_colors	colors;
}				t_sphere;

typedef struct s_plane
{
	t_tuple		pos;
	t_tuple		normal_vector;
	t_colors	colors;
}				t_plane;

typedef struct s_cylinder
{
	t_tuple		pos;
	t_tuple		normal_axis;
	float		dim;
	float		height;
	t_colors	colors;
}				t_cylinder;

enum			e_pov
{
	VECTOR,
	POINT
};

int				floatcmp(float a, float b);
int				tuplecmp(t_tuple *a, t_tuple *b);
t_tuple			*tuplesub(t_tuple *a, t_tuple *b);
t_tuple			*tupleadd(t_tuple *a, t_tuple *b);
t_tuple			*vector(float x, float y, float z);
t_tuple			*point(float x, float y, float z);
t_tuple			*tuplesdiv(t_tuple *a, float scale);
t_tuple			*tuplesmult(t_tuple *a, float scale);
t_tuple			*tuplenegt(t_tuple *a);
float			tuplemagnitude(t_tuple *a);
float			tupledot(t_tuple *a, t_tuple *b);
t_tuple			*tuplecross(t_tuple *a, t_tuple *b);
t_tuple			*tuplenormalize(t_tuple *a);

#endif