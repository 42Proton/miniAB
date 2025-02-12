/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:04:22 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/12 14:25:15 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
#define OBJECT_H

// includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// defintions
#define EPSILON 0.00001
#define PI 3.14159

typedef struct s_tuple
{
        float X;
        float Y;
        float Z;
        float W;
} t_tuple;
enum e_pov
{
        VECTOR,
        POINT
};
int floatcmp(float a, float b);
int tuplecmp(t_tuple *a, t_tuple *b);
t_tuple *tuplesub(t_tuple *a, t_tuple *b);
t_tuple *tupleadd(t_tuple *a, t_tuple *b);
t_tuple *vector(float x, float y, float z);
t_tuple *point(float x, float y, float z);
t_tuple *tupleSdiv(t_tuple *a, float scale);
t_tuple *tupleSmult(t_tuple *a, float scale);
t_tuple *tuplenegt(t_tuple *a);
float tuplemagnitude(t_tuple *a);
t_tuple *tupledot(t_tuple *a, t_tuple *b);
#endif