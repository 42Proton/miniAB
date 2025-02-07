/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/08 00:49:43 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	init_mlx_pointers(t_rtptr *rts)
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
	rts->img_st.img = mlx_new_image(rts->mlx,WID,HEG);
	rts->img_st.data = mlx_get_data_addr(rts->img_st.img,&rts->img_st.bpp,&rts->img_st.size_line,&rts->img_st.endian);
	mlx_put_image_to_window(rts->mlx, rts->win, rts->img_st.img, 0, 0);
	return (EXIT_SUCCESS);
}

int	main(void)
{
	t_rtptr	rts;

	if (init_mlx_pointers(&rts))
		cleaner(&rts, "Error initialaizing!");


	sphere_draw(100,0.1,&rts);

	
	mlx_key_hook(rts.win, &keyhook, &rts);
	mlx_loop(rts.mlx);
	perror("Loop:");
}
