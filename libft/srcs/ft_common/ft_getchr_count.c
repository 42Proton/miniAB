/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:52:44 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/09 22:52:59 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_getchr_count(char *str, char c)
{
	size_t	res;

	res = 0;
	while (*str)
	{
		if (*str == c)
			res++;
		str++;
	}
	return (res);
}
