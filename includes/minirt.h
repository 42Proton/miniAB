/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:59 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/05 23:33:45 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define XK_MISCELLANY
# include <MLX42/MLX42.h>
# include <colors.h>
# include <libft.h>
# include <object.h>
# include <utils.h>
# define WID 1000
# define HEG 720

typedef struct s_rtptr
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_list		*objs;
}				t_rtptr;

typedef struct s_object
{
	void		*object;
	int			type;
}				t_object;

enum			e_types_of_objects
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
int				parser(char *, t_rtptr *);
t_object		*objectify(int);
void			*ambient_light(void);
// Cleaner
void			cleaner(t_rtptr *, char *);

// Hooks
void			keyhook(struct mlx_key_data, void *);

// Initalization
int				check_args(int, char **);
int				init_mlx_pointers(t_rtptr *);

// utils
void			*pos(void);
void			*color(void);
#endif