/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/02/05 18:11:02 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#define PI 3.14
int main(void)
{
  void *mlx;
  void *win;

  mlx = mlx_init();
  win = mlx_new_window(mlx, 1000, 1000, "Lenovo");

  for (double t = 0; t < 2 * PI; t += 0.0001)
  {
    mlx_pixel_put(mlx, win, cos(t) * 100 + 500, sin(t) * 100 + 500, 0xFFFFFF);
  }

  mlx_loop(mlx);
  return 0;
}
