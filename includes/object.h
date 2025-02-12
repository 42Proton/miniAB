/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:04:22 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/12 10:45:34 by bismail          ###   ########.fr       */
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
        double X;
        double Y;
        double Z;
        double W;
}       t_tuple;

enum e_pov
{
        VECTOR,
        POINT
};
int floatcmp(double a, double b);
int tuplecmp(t_tuple *a, t_tuple *b);
t_tuple *tuplesub(t_tuple *a, t_tuple *b);
t_tuple *tupleadd(t_tuple *a, t_tuple *b);
t_tuple *vector(double x, double y, double z);
t_tuple *point(double x, double y, double z);
t_tuple *tupleSdiv(t_tuple *a, double scale);
t_tuple *tupleSmult(t_tuple *a, double scale);
t_tuple *tuplenegt(t_tuple *a);
double tuplemagnitude(t_tuple *a);
t_tuple *tuplenormalize(t_tuple *a);

#endif