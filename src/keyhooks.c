/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:42:32 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/04 16:05:01 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	keyhook(struct mlx_key_data keydata, void *rts)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		ft_printf("ESC pressed!");
		cleaner(rts, 0);
	}
}
