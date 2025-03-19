/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/19 23:05:22 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	debug_tuple(t_tuple *tuple)
{
	printf("%f %f %f\n", tuple->x, tuple->y, tuple->z);
}

t_colors	ray_color(t_rtptr *rts, t_ray *ray)
{
	t_colors		res;
	t_object_entry	*obj_entry;
	t_intersections	*data;
	t_intersect		*intersect;
	t_tuple			rhitpoint;
	t_tuple			inverse_point;
	t_tuple			rhitpoint_inverse;
	t_tuple			normal_vec;
	t_tuple			unit_direction;

	ft_bzero(&res, sizeof(t_colors));
	obj_entry = rts->objs->content;
	data = sphere_intersect(obj_entry, ray);
	intersect = get_hit(data);
	if (intersect)
	{
		rhitpoint = ray_hitpoint(ray, intersect->t);
		inverse_point = point(0, 0, -1);
		rhitpoint_inverse = n_tuplesub(&rhitpoint, &inverse_point);
		normal_vec = tuplenormalize(&rhitpoint_inverse);
		res.red = normal_vec.x * 255;
		res.green = normal_vec.y * 255;
		res.blue = normal_vec.z * 255;
		res.alpha = 255;
	}
	else
	{
		unit_direction = tuplenormalize(&ray->direction);
		res.blue = unit_direction.z * 255;
		res.green = unit_direction.y * 255;
		res.red = unit_direction.x * 255;
		res.alpha = unit_direction.y * 255;
	}
	clear_intersections(data);
	return (res);
}

void	matrix_test(void)
{
	t_matrix	*a;

	// t_matrix	*b;
	a = matrix_init(2, 2);
	set_matrix_elem(a, 0, 0, 1);
	set_matrix_elem(a, 1, 0, 5);
	set_matrix_elem(a, 0, 1, -3);
	set_matrix_elem(a, 1, 1, 2);
	printf("Matrix A\n");
	printf("deteminant: %f\n", determinant2x2(a));
}
int	main(int argc, char **argv)
{
	t_rtptr	rts;

	ft_bzero(&rts, sizeof(t_rtptr));
	if (check_args(argc, argv))
		return (EXIT_FAILURE);
	if (parser(argv[1], &rts))
		cleaner(&rts);
	// mlx_image_to_window(rts.mlx, rts.img, 0, 0);
	// Leave it clean, if you want to test,
	// put it in a function then call it here.
	matrix_test();
	// mlx_key_hook(rts.mlx, keyhook, &rts);
	// mlx_loop(rts.mlx);
	cleaner(&rts);
	return (0);
}
