/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/17 18:17:42 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_colors	ray_color(t_rtptr *rts, t_ray *ray)
{
	t_colors	res;
	t_object_entry	*obj_entry;

	ft_bzero(&res, sizeof(t_colors));
	obj_entry = rts->objs->content;
	t_intersections *data = sphere_intersect(obj_entry, ray);
	t_intersect *intersect = get_hit(data);
	if (intersect)
		res = *((t_sphere *)obj_entry->object)->colors;
	clear_intersections(data);
	return (res);
}

void debug_tuple(t_tuple *tuple)
{
	printf("%f %f %f\n", tuple->x, tuple->y, tuple->z);
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
	// float viewport_height = 2.0f;
	// float viewport_width = viewport_height * (float)WID/HEG;
	// t_tuple camera_center = point(0, 0, 0);
	// t_tuple viewport_u = vector(viewport_width, 0, 0);
	// t_tuple viewport_v = vector(0, -viewport_height, 0);
	// t_tuple pixel_delta_u = tuplesdiv(&viewport_u, WID);
	// t_tuple pixel_delta_v = tuplesdiv(&viewport_v, HEG);
	// t_tuple viewport_u_half = tuplesdiv(&viewport_u, 2);
	// t_tuple viewport_v_half = tuplesdiv(&viewport_v, 2);
	// t_tuple camera_center_half_u = n_tuplesub(&camera_center, &viewport_u_half);
	// t_tuple viewport_upper_left = n_tuplesub(&camera_center_half_u, &viewport_v_half);
	// t_tuple pixel_delta_uv = tupleadd(&pixel_delta_u, &pixel_delta_v);
	// t_tuple pixel_delta_uv_half = tuplesmult(&pixel_delta_uv, 0.5);
	// t_tuple pixel00_loc = tupleadd(&viewport_upper_left, &pixel_delta_uv_half);
	
	// for (int i = 0; i < HEG; i++)
	// {
	// 	for (int j = 0; j < WID; j++)
	// 	{
	// 		t_tuple pixel_delta_v_offset = tuplesmult(&pixel_delta_v, i);
	// 		t_tuple pixel_delta_u_offset = tuplesmult(&pixel_delta_u, j);
	// 		t_tuple pixel_delta_uv_offset_sum = tupleadd(&pixel_delta_u_offset, &pixel_delta_v_offset);
	// 		t_tuple pixel_center = tupleadd(&pixel00_loc, &pixel_delta_uv_offset_sum);
	// 		t_tuple ray_direction = n_tuplesub(&pixel_center, &camera_center);
	// 		t_ray ray = init_ray(&pixel_center, &ray_direction);
	// 		t_colors color = ray_color(&rts, &ray);
	// 		mlx_put_pixel(rts.img, j, i, colorvalue(&color));
	// 	}
	// }
	// mlx_key_hook(rts.mlx, keyhook, &rts);
	mlx_loop(rts.mlx);
	cleaner(&rts);
	return (0);
}
