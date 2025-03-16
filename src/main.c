/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/17 02:27:18 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	main(int argc, char **argv)
{
	t_rtptr	rts;

	ft_bzero(&rts, sizeof(t_rtptr));
	if (check_args(argc, argv))
		return (EXIT_FAILURE);
	if (parser(argv[1], &rts))
		cleaner(&rts);
	// float	focal_length = 1.0f;
	// float	aspect_ratio = WID/HEG;
	// float	viewport_height = 2.0f;
	// float	viewport_width = viewport_height * aspect_ratio;
	// t_tuple	*camera_center = point(0, 0, 0);
	// t_tuple	*viewport_u = vector(viewport_width, 0, 0);
	// t_tuple	*viewport_v = vector(0, -viewport_height, 0);
	// t_tuple	*pixel_delta_u = tuplesdiv(viewport_u, WID);
	// t_tuple	*pixel_delta_v = tuplesdiv(viewport_u, HEG);
	// t_tuple *viewport_upper_left = tuplesub(tuplesub(camera_center, vector(0, 0, focal_length)), tuplesdiv(viewport_u, 2)) tuplesdiv(viewport_v, 2);

	t_tuple	origin = point(0, 0, 0);
	t_tuple direction = vector(0, 0, 0.5);
	t_ray	ray = init_ray(&origin, &direction);
	t_intersections *data = sphere_intersect((t_object_entry *)rts.objs->content, &ray);
	printf("%ld\n", data->count);
	t_list *lst = data->lst;
	while (lst)
	{
		t_intersect *intersect = (t_intersect *)lst->content;
		printf("OBJ TYPE: %d\nOBJ PTR: %p\nT value: %f\n", intersect->obj_type, intersect->obj, intersect->t);
		lst = lst->next;
	}
	t_intersect	*i = get_hit(data);
	if (i)
		printf("T: %f\n", i->t);
	else
		printf("NO HIT\n");
	clear_intersections(data);
	// mlx_key_hook(rts.mlx, keyhook, &rts);
	// mlx_loop(rts.mlx);
	cleaner(&rts);
	return (0);
}
