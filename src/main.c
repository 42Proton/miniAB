/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/17 03:45:39 by abueskander      ###   ########.fr       */
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

	t_tuple		pos;
	t_matrix 	*matrix;

	pos = vector(1,1,1);
	matrix = matrix_init(3, 3);
	set_matrix_elem(matrix,0,0,2);
	set_matrix_elem(matrix,0,1,1);
	set_matrix_elem(matrix,0,2,0);

	set_matrix_elem(matrix,1,0,-1);
	set_matrix_elem(matrix,1,1,3);
	set_matrix_elem(matrix,1,2,0);

	set_matrix_elem(matrix,2,0,0);
	set_matrix_elem(matrix,2,1,0);
	set_matrix_elem(matrix,2,2,4);
	
	pos = transform_f(matrix, &pos);
	printf("x: %f, y: %f, z: %f\n", pos.x, pos.y, pos.z);
	// mlx_key_hook(rts.mlx, keyhook, &rts);
	// mlx_loop(rts.mlx);
	cleaner(&rts);
	return (0);
}
