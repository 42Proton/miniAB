/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/07 00:00:56 by amsaleh          ###   ########.fr       */
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
	// mlx_key_hook(rts.mlx, keyhook, &rts);
	// mlx_loop(rts.mlx);
	
	// Sphere Test
	// t_sphere *sphere = (t_sphere *)((t_object_entry *)rts.objs->content)->object;
	// printf("Sphere pos: %f,%f,%f\n", sphere->pos->X, sphere->pos->Y, sphere->pos->Z);
	// printf("Sphere color: %d,%d,%d,%d\n", sphere->colors->red, sphere->colors->green, sphere->colors->blue, sphere->colors->alpha);
	// printf("Sphere diameter: %f\n", sphere->dim);
	cleaner(&rts);
	return (0);
}
