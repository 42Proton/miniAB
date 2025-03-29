/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/29 20:53:03 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <debug.h>

t_intersections	*world_intersect(t_list *solid_objs, t_ray *ray)
{
	t_intersections	*insects;
	t_object_entry	*entry;
	int				res;

	insects = ft_calloc(1, sizeof(t_intersections));
	if (!insects)
		return (0);
	while (solid_objs)
	{
		entry = solid_objs->content;
		if (entry->type == SPHERE)
			res = sphere_intersect(insects, entry, ray);
		if (!res)
		{
			clear_intersections(insects);
			return (0);
		}
		solid_objs = solid_objs->next;
	}
	return (insects);
}

t_colors	ray_color(t_rtptr *rts, t_ray *ray)
{
	t_colors		res;
	t_intersections	*insects;
	t_intersect		*insect;
	//t_computes		comp;

	insects = world_intersect(rts->solid_objs, ray);
	insect = get_hit(insects);
	if (insect)
	{
		//comp = init_computes(insect, ray);
		res = ((t_sphere *)insect->obj)->mat.color;
	}
	else
		res = colorinit(ft_fabs(ray->direction.y) * 200, 200, 200);
	clear_intersections(insects);
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

int	main(int ac, char **av)
{
	t_rtptr	rts;

	if (prep_rt_core(ac, av, &rts))
		cleaner(&rts);
	// init_mlx is seperate from prep_rt_core for ease of debugging
	if (init_mlx(&rts))
		cleaner(&rts);
	mlx_image_to_window(rts.mlx, rts.img, 0, 0);
	float viewport_size = 15.0;
	float viewport_z = 0;
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
			t_tuple	rd_normal = tuplenormalize(&ray_direction);
			t_ray ray = init_ray(&position, &rd_normal);
			t_colors color = ray_color(&rts, &ray);
			mlx_put_pixel(rts.img, x, y, colorvalue(&color));
		}
	}
	mlx_key_hook(rts.mlx, keyhook, &rts);
	mlx_loop(rts.mlx);
	cleaner(&rts);
	return (0);
}
