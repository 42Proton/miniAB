/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/23 03:11:49 by amsaleh          ###   ########.fr       */
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
		normal_vec = n_tuplesub(&rhitpoint, ((t_sphere *)obj_entry->object)->pos);
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
	if (prep_objs_transform(rts))
		return (EXIT_FAILURE);
	split_objs(rts);
	return (EXIT_SUCCESS);
}

void	matrix_test(void)
{
	t_matrix	*a;
	t_matrix	*b;

	a = matrix_init(4, 4);
	set_matrix_elem(a, 0, 0, -2);
	set_matrix_elem(a, 1, 0, -8);
	set_matrix_elem(a, 2, 0, 3);
	set_matrix_elem(a, 3, 0, 5);
	set_matrix_elem(a, 0, 1, -3);
	set_matrix_elem(a, 1, 1, 1);
	set_matrix_elem(a, 2, 1, 7);
	set_matrix_elem(a, 3, 1, 3);
	set_matrix_elem(a, 0, 2, 1);
	set_matrix_elem(a, 1, 2, 2);
	set_matrix_elem(a, 2, 2, -9);
	set_matrix_elem(a, 3, 2, 6);
	set_matrix_elem(a, 0, 3, -6);
	set_matrix_elem(a, 1, 3, 7);
	set_matrix_elem(a, 2, 3, 7);
	set_matrix_elem(a, 3, 3, -9);
	b = matrix_transpose(a);
	printf("Matrix A\n");
	printf("deteminant: %f\n", determinant(b));
	printf("Before transpose:\n");
	matrix_debug(a);
	printf("\nAfter transpose:\n");
	matrix_debug(b);
	free_matrix(a);
	free_matrix(b);
}

int	main(int ac, char **av)
{
	t_rtptr	rts;

	if (prep_rt_core(ac, av, &rts))
		cleaner(&rts);
	// init_mlx is seperate from prep_rt_core for ease of debugging
	if (init_mlx(&rts))
		cleaner(&rts);
	mlx_image_to_window(rts.mlx, rts.img, 0, 0);
	float viewport_size = 12.0;
	float viewport_z = 10;
	float pixel_size = viewport_size / WID;
	float half = viewport_size / 2;
	for (int y = 0; y < HEG; y++)
	{
		float world_y = half - pixel_size * y;
		for (int x = 0; x < WID; x++)
		{
			float world_x = -half + pixel_size * x;
			t_tuple position = point(world_x, world_y, viewport_z);
			t_tuple ray_direction = n_tuplesub(&position, rts.camera->pos);
			t_ray ray = init_ray(rts.camera->pos, &ray_direction);
			t_colors color = ray_color(&rts, &ray);
			mlx_put_pixel(rts.img, x, y, colorvalue(&color));
		}
	}
	mlx_key_hook(rts.mlx, keyhook, &rts);
	mlx_loop(rts.mlx);
	cleaner(&rts);
	return (0);
}
