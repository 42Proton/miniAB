/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:59 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/04 01:50:25 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define XK_MISCELLANY
# include <X11/X.h>
# include <X11/keysymdef.h>
# include <colors.h>
# include <mlx.h>
# include <object.h>
# include <utils.h>
# define WID 1000
# define HEG 720

typedef struct s_image
{
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
}			t_image;

typedef struct s_rtptr
{
	void	*mlx;
	void	*win;
	t_image	img_st;
	t_list	*objs;
}			t_rtptr;

typedef struct s_object
{
	void	*object;
	int		type;
}			t_object;

enum		e_types_of_objects
{
	AMBIENTLIGHT,
	LIGHT,
	CAMERA,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	HYPER,
	PARA
};

// Parser
int			parser(char *, t_rtptr *);
t_object	*objectify(int);
void		*ambient_light(void);
// Cleaner
void		cleaner(t_rtptr *, char *);

// Hooks
int			keyhook(int, void *);

// Initalization
int			check_args(int, char **);
int			init_mlx_pointers(t_rtptr *);

#endif