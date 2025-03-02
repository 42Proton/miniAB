/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:04:22 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/02 10:48:14 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

// includes
# include <math.h>
# include <utils.h>
// defintions
# define EPSILON 0.00001
# define PI 3.14159

typedef struct s_tuple
{
	float	X;
	float	Y;
	float	Z;
	float	W;
}			t_tuple;

typedef struct s_matrix
{
}			t_matrix;

enum		e_pov
{
	VECTOR,
	POINT
};
int			floatcmp(float a, float b);
int			tuplecmp(t_tuple *a, t_tuple *b);
t_tuple		*tuplesub(t_tuple *a, t_tuple *b);
t_tuple		*tupleadd(t_tuple *a, t_tuple *b);
t_tuple		*vector(float x, float y, float z);
t_tuple		*point(float x, float y, float z);
t_tuple		*tuplesdiv(t_tuple *a, float scale);
t_tuple		*tuplesmult(t_tuple *a, float scale);
t_tuple		*tuplenegt(t_tuple *a);
float		tuplemagnitude(t_tuple *a);
float		tupledot(t_tuple *a, t_tuple *b);
t_tuple		*tuplecross(t_tuple *a, t_tuple *b);
t_tuple		*tuplenormalize(t_tuple *a);
#endif