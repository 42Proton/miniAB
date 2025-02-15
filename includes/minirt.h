/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:59 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/15 13:00:27 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

#define XK_MISCELLANY
#include <libft.h>
#include <utils.h>
#include <colors.h>
#include <object.h>
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysymdef.h>
#define WID 1000
#define HEG 720
typedef struct s_image
{
        void *img;
        int bpp;
        int size_line;
        int endian;
        char *data;
} t_image;
typedef struct s_rtptr
{
        void *mlx;
        void *win;
        t_image img_st;
} t_rtptr;

void cleaner(t_rtptr *rts, char *error);
int keyhook(int keycode, void *param);
void sphere_draw(double radius, double res, t_rtptr *rts);
int init_mlx_pointers(t_rtptr *rts);

#endif
