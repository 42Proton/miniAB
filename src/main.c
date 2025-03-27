/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/27 06:49:25 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <debug.h>

t_colors	ray_color(t_rtptr *rts, t_ray *ray)
{
	t_colors		res;
	t_object_entry	*obj_entry;
	t_intersections	*data;
	t_intersect		*intersect;
	t_tuple			rhitpoint;
	t_tuple			normal_vec;

	ft_bzero(&res, sizeof(t_colors));
	obj_entry = rts->solid_objs->content;
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
	if (handle_missing_objs(rts))
		return (EXIT_FAILURE);
	if (prep_objs_postparse(rts))
		return (EXIT_FAILURE);
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

t_tuple	*sphere_normal(t_sphere *obj, t_tuple *p)
{
	t_tuple		object_norm;
	t_tuple		*world_norm;
	t_matrix	*t_inv;
	t_matrix	*t_transpose;

	t_inv = matrix_inverse(obj->transform);
	if (!t_inv)
		return (0);
	object_norm = s_tuplesub(matrix_mult_t(t_inv, p), point(0, 0, 0));
	t_transpose = matrix_transpose(t_inv);
	free_matrix(t_inv);
	if (!t_transpose)
		return (0);
	world_norm = malloc(sizeof(t_tuple));
	if (!world_norm)
	{
		free_matrix(t_transpose);
		return (0);
	}
	*world_norm = matrix_mult_t(t_transpose, &object_norm);
	free_matrix(t_transpose);
	*world_norm = tuplenormalize(world_norm);
	world_norm->w = VECTOR;
	return (world_norm);
}

t_tuple	reflect_vec(t_tuple *vec, t_tuple *norm)
{
	float	dot;
	t_tuple	vec_mirror;
	t_tuple	r;

	dot = tupledot(vec, norm);
	dot = dot * 2;
	vec_mirror = n_tuplesmult(norm, dot);
	r = n_tuplesub(vec, &vec_mirror);
	return (r);
}

int	main(int ac, char **av)
{
	t_rtptr	rts;

	if (prep_rt_core(ac, av, &rts))
		cleaner(&rts);
	// init_mlx is seperate from prep_rt_core for ease of debugging
	// if (init_mlx(&rts))
	// 	cleaner(&rts);
	// mlx_image_to_window(rts.mlx, rts.img, 0, 0);
	// float viewport_size = 15.0;
	// float viewport_z = 0;
	// float pixel_size = viewport_size / WID;
	// float half = viewport_size / 2;
	// for (int y = 0; y < HEG; y++)
	// {
	// 	float world_y = half - pixel_size * y;
	// 	for (int x = 0; x < WID; x++)
	// 	{
	// 		float world_x = -half + pixel_size * x;
	// 		t_tuple position = point(world_x, world_y, viewport_z);
	// 		t_tuple ray_direction = n_tuplesub(&position, rts.camera->pos);
	// 		t_tuple	rd_normal = tuplenormalize(&ray_direction);
	// 		t_ray ray = init_ray(&position, &rd_normal);
	// 		t_colors color = ray_color(&rts, &ray);
	// 		mlx_put_pixel(rts.img, x, y, colorvalue(&color));
	// 	}
	// }
	// mlx_key_hook(rts.mlx, keyhook, &rts);
	// mlx_loop(rts.mlx);
	cleaner(&rts);
	return (0);
}
