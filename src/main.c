/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/10 16:47:58 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int init_mlx_pointers(t_rtptr *rts)
{
	rts->mlx = mlx_init();
	if (!rts->mlx)
		return (EXIT_FAILURE);
	rts->win = mlx_new_window(rts->mlx, WID, HEG, "miniAB");
	if (!rts->win)
	{
		mlx_destroy_display(rts->mlx);
		return (EXIT_FAILURE);
	}
	rts->img_st.img = mlx_new_image(rts->mlx, WID, HEG);
	rts->img_st.data = mlx_get_data_addr(rts->img_st.img, &rts->img_st.bpp, &rts->img_st.size_line, &rts->img_st.endian);
	mlx_put_image_to_window(rts->mlx, rts->win, rts->img_st.img, 0, 0);
	return (EXIT_SUCCESS);
}

int main()
{
	float *tuble;
	float *pnt;
	float *vec;

	tuble = malloc(sizeof(float) * 4);
	pnt = point(3, -4.2, -1.1);
	vec = vector(-3, 4.2, 1.1);
	tuble = tuplesub(pnt, vec);
	printf("point X %f  Y %f Z %f  W %f\n", tuble[X], tuble[Y], tuble[Z], tuble[W]);
	// printf("vector X %f  Y %f Z %f  W %f\n", vec[X], vec[Y], vec[Z], vec[W]);
}
