/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/15 15:08:54 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int main()
{
	t_rtptr rts;

	init_mlx_pointers(&rts);
	
	sphere_draw(10,0.01,&rts);
	mlx_loop(rts.mlx);
}
