/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 06:17:05 by bismail           #+#    #+#             */
/*   Updated: 2025/04/10 07:35:45 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int     render_init(t_rtptr *rts)
{
        u_int32_t     *render;

        render = malloc(sizeof(render) * wid_res * heg_res);
        if(!render)
                return(1);
        rts->rendered_image = render;
        return (0);
}

void    set_rendered(t_rtptr *rts, u_int32_t x, u_int32_t y, u_int32_t color_v)
{
        rts->rendered_image[y * wid_res + x] = color_v;
}

void    render(t_rtptr *rts)
{
        u_int32_t x;
        u_int32_t y;
        u_int32_t color;

        y = 0;
        while (y < heg_res)
        {
                x = 0;
                while (x < wid_res)
                {
                        color = rts->rendered_image[y * wid_res + x];
                        mlx_put_pixel(rts->img, x, y, color);
                        x++;
                }
                y++;
        }
}