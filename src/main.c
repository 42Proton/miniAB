/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/16 23:46:52 by amsaleh          ###   ########.fr       */
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
	// t_tuple	*origin = point(0, 0, 0);
	// t_tuple *direction = vector(0, 0, 0.5);
	// t_ray	*ray = init_ray(origin, direction);
	// t_intersections *data = sphere_intersect((t_object_entry *)rts.objs->content, ray);
	// printf("%ld\n", data->count);
	// t_list *lst = data->lst;
	// while (lst)
	// {
	// 	t_intersect *intersect = (t_intersect *)lst->content;
	// 	printf("OBJ TYPE: %d\nOBJ PTR: %p\nT value: %f\n", intersect->obj_type, intersect->obj, intersect->t);
	// 	lst = lst->next;
	// }
	// t_intersect	*i = get_hit(data);
	// if (i)
	// 	printf("T: %f\n", i->t);
	// else
	// 	printf("NO HIT\n");
	t_matrix *m = matrix_init(4, 4);
	set_matrix_elem(m, 0, 0, 1);
	set_matrix_elem(m, 1, 1, 1);
	set_matrix_elem(m, 2, 2, 1);
	set_matrix_elem(m, 3, 3, 1);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%f ", get_matrix_elem(m, i, j));
		printf("\n");
	}
	free_matrix(m);
	// mlx_key_hook(rts.mlx, keyhook, &rts);
	// mlx_loop(rts.mlx);
	cleaner(&rts);
	return (0);
}
