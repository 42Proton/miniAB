/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/23 02:15:54 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_colors	ray_color(t_rtptr *rts, t_ray *ray)
{
	t_colors		res;
	t_object_entry	*obj_entry;
	t_intersections	*data;
	t_intersect		*intersect;
	t_tuple			rhitpoint;
	t_tuple			normal_vec;

	ft_bzero(&res, sizeof(t_colors));
	obj_entry = rts->objs->content;
	data = sphere_intersect(obj_entry, ray);
	intersect = get_hit(data);
	if (intersect)
	{
		rhitpoint = ray_hitpoint(ray, intersect->t);
		normal_vec = n_tuplesub(&rhitpoint,
				((t_sphere *)obj_entry->object)->pos);
		res.red = normal_vec.x * 255;
		res.green = normal_vec.y * 255;
		res.blue = 255;
		res.alpha = 255;
	}
	else
	{
		normal_vec = tuplenormalize(&ray->direction);
		res.blue = normal_vec.z * 255;
		res.green = normal_vec.y * 255;
		res.red = normal_vec.x * 255;
		res.alpha = normal_vec.y * 255;
	}
	clear_intersections(data);
	return (res);
}

int	prep_rt_core(int ac, char **av, t_rtptr *rts)
{
	ft_bzero(rts, sizeof(t_rtptr));
	if (check_args(ac, av))
		return (EXIT_FAILURE);
	if (parser(av[1], rts))
		return (EXIT_FAILURE);
	split_objs(rts);
	return (EXIT_SUCCESS);
}

void	testinverse(void)
{
	t_matrix	*mat;
	t_matrix	*inv;

	mat = matrix_init(4, 4);
	set_matrix_elem(mat, 0, 0, 8);
	set_matrix_elem(mat, 0, 1, -5);
	set_matrix_elem(mat, 0, 2, 9);
	set_matrix_elem(mat, 0, 3, 2);
	set_matrix_elem(mat, 1, 0, 7);
	set_matrix_elem(mat, 1, 1, 5);
	set_matrix_elem(mat, 1, 2, 6);
	set_matrix_elem(mat, 1, 3, 1);
	set_matrix_elem(mat, 2, 0, -6);
	set_matrix_elem(mat, 2, 1, 0);
	set_matrix_elem(mat, 2, 2, 9);
	set_matrix_elem(mat, 2, 3, 6);
	set_matrix_elem(mat, 3, 0, -3);
	set_matrix_elem(mat, 3, 1, 0);
	set_matrix_elem(mat, 3, 2, -9);
	set_matrix_elem(mat, 3, 3, -4);
	matrix_debug(mat);
	inv = matrix_inverse(mat);
	matrix_debug(inv);
	free_matrix(mat);
	free_matrix(inv);
}
int	main(int ac, char **av)
{
	t_rtptr	rts;

	if (prep_rt_core(ac, av, &rts))
		cleaner(&rts);
	// if (init_mlx(&rts))
	// 	cleaner(&rts);
	// mlx_image_to_window(rts.mlx, rts.img, 0, 0);
	// init_mlx is seperate from prep_rt_core for ease of debugging
	testinverse();
	cleaner(&rts);
	return (0);
}
