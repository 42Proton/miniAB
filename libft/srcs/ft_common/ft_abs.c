/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:45:00 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/06 10:23:55 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_abs(int x)
{
	if (x < 0)
	{
		if (x == INT_MIN)
			return (x);
		x *= -1;
	}
	return (x);
}

float	ft_fabs(float val)
{
	if (val < 0)
		return (val * -1);
	return (val);
}
