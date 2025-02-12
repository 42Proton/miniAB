/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/12 15:12:48 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int main()
{
	t_tuple *tuble;
	t_tuple *pnt;
	t_tuple *vec;

	tuble = point(1, 2, 3);
	pnt = point(3, -4.2, -1.1);
	vec = vector(-3, 4.2, 1.1);
	tuble = tuplesub(pnt, vec);

	printf("point X %f  Y %f Z %f  W %f\n", tuble->X, tuble->Y, tuble->Z, tuble->W);

	printf("Mag = %f \n", tuplemagnitude(pnt));
	tuble = tupledot(tuble, tuble);
	printf("point X %f  Y %f Z %f  W %f\n", tuble->X, tuble->Y, tuble->Z, tuble->W);
	// printf("vector X %f  Y %f Z %f  W %f\n", vec[X], vec[Y], vec[Z], vec[W]);
}
