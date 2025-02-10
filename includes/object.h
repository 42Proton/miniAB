/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:04:22 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/10 16:20:22 by abueskander      ###   ########.fr       */
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

enum e_axis
{
        X,
        Y,
        Z,
        W
};
enum e_pov
{
        VECTOR,
        POINT
};
int floatcmp(float a, float b);
float *floatadd(float *a, float *b);
float *vector(float x, float y, float z);
float *point(float x, float y, float z);

#endif