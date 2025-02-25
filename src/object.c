/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 00:06:15 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/15 13:45:21 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void put_pixel(int x, int y, int color, t_image *img)
{
        if (x >= WID || y >= HEG || x < 0 || y < 0)
                return;
        int index = y * img->size_line + x * img->bpp / 8;
        img->data[index] = color & 0xFF;
        img->data[index + 1] = (color >> 8) & 0xFF;
        img->data[index + 2] = (color >> 16) & 0xFF;
}
void 	sphere_draw(double radius, double res,  t_rtptr *rts)
{
        double  i;
        double j;
        t_colors *colors;
	
	colors = colorinit(0xFF,0xAA,0xFF,0xAA);
        i = 0;
        while (i < 2 * M_PI)
        {
                j = 0;
                while( j < radius)
                {
                        mlx_pixel_put(rts->mlx,rts->win,cos(i) * j + (WID / 2), sin(i) * j +( HEG /2) ,colorvalue(colors));
                        //put_pixel(cos(i) * j + WID /2,sin(i) * j + HEG /2 ,0xFF0F00,&rts->img_st);
                        j+= res;
                }
                i+= res;
        }
      //  mlx_put_image_to_window(rts->mlx, rts->win, rts->img_st.img, 0, 0);

}