/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:42:32 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/23 19:59:07 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	keyhook(struct mlx_key_data keydata, void *rtptr)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		cleaner(rtptr);
}