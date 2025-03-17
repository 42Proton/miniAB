/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/17 23:16:41 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void debug_tuple(t_tuple *tuple)
{
	printf("%f %f %f\n", tuple->x, tuple->y, tuple->z);
}

t_colors	ray_color(t_rtptr *rts, t_ray *ray)
{
	t_colors	res;
	t_object_entry	*obj_entry;

	ft_bzero(&res, sizeof(t_colors));
	obj_entry = rts->objs->content;
	t_intersections *data = sphere_intersect(obj_entry, ray);
	t_intersect *intersect = get_hit(data);
	if (intersect)
	{
		t_tuple rhitpoint = ray_hitpoint(ray, intersect->t);
		t_tuple inverse_point = point(0, 0, -1);
		t_tuple rhitpoint_inverse = n_tuplesub(&rhitpoint, &inverse_point);
		t_tuple normal_vec = tuplenormalize(&rhitpoint_inverse);
		res.red = normal_vec.x * 255;
		res.green = normal_vec.y * 255;
		res.blue = normal_vec.z * 255;
		res.alpha = 255;
	}
	else
	{
		t_tuple unit_direction = tuplenormalize(&ray->direction);
		res.blue = unit_direction.z * 255;
		res.green = unit_direction.y * 255;
		res.red = unit_direction.x * 255;
		res.alpha = unit_direction.y * 255;
	}
	clear_intersections(data);
	return (res);
}

int	main(int argc, char **argv)
{
	t_rtptr	rts;

	ft_bzero(&rts, sizeof(t_rtptr));
	if (check_args(argc, argv))
		return (EXIT_FAILURE);
	if (parser(argv[1], &rts) || init_mlx(&rts))
		cleaner(&rts);
	mlx_image_to_window(rts.mlx, rts.img, 0, 0);
	float viewport_size = 7.0;
	float viewport_z = 10;
	t_tuple ray_origin = point(0, 0, -5);
	float pixel_size = viewport_size / WID;
	float half = viewport_size / 2;
	for (int y = 0; y < HEG; y++)
	{
		float world_y = half - pixel_size * y;
		for (int x = 0; x < WID; x++)
		{
			float world_x = -half + pixel_size * x;
			t_tuple position = point(world_x, world_y, viewport_z);
			t_tuple ray_direction = n_tuplesub(&position, &ray_origin);
			t_ray ray = init_ray(&ray_origin, &ray_direction);
			t_colors color = ray_color(&rts, &ray);
			mlx_put_pixel(rts.img, x, y, colorvalue(&color));
		}
	}
	mlx_key_hook(rts.mlx, keyhook, &rts);
	mlx_loop(rts.mlx);
	cleaner(&rts);
	return (0);
}
