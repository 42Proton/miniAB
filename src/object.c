/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 00:06:15 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/04 16:07:03 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

// USE mlx_put_pixel with image

// void	sphere_draw(double radius, double res, t_rtptr *rts)
// // {
// // 	double i;
// // 	// double j;
// // 	t_tuple *pnt = point(WID, HEG, 0);
// // 	// t_tuple *gravity = vector(0,-1,0);
// // 	// t_tuple *wind = vector(-1,0,0);
// // 	t_tuple *vec = tuplenormalize(vector(-1.25, -1.8 * 1.25, 0));
// // 	t_colors *a = colorinit(-200, -233, 0xFF, 0xFF);
// // 	//        t_colors *b = colorinit(-200,-233,0xFF,0xFF);
// // 	//	colors = colorinit(0xFF,0xAA,0xFF,0xAA);
// // 	i = 0;
// // 	while (i < 100)
// // 	{
// // 		pnt = tupleadd(pnt, vec);
// // 		// vec = tuplesub(vec,wind);
// // 		// vec = tuplesub(vec,gravity);
// // 		mlx_pixel_put(rts->mlx, rts->win, pnt->X, pnt->Y, colorvalue(a));
// // 		i += res;
// // 	}
// // 	//  mlx_put_image_to_window(rts->mlx, rts->win, rts->img_st.img, 0, 0);
// // 	free(vec);
// // 	free(a);
// // 	free(pnt);
// }