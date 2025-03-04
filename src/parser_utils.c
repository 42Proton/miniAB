/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:18:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/05 02:19:31 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	check_float_input_prep(const char *str, int *digits)
{
	int	i;

	i = 0;
	*digits = 0;
	while ((str[i] >= 0x9 && str[i] <= 0xD) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	return (i);
}

static int	check_float_decimals(const char *str, int *i, int *digits)
{
	if (str[*i] == '.')
	{
		(*i)++;
		if (str[*i] && !ft_isdigit(str[*i]))
			return (0);
		while (ft_isdigit(str[*i]))
		{
			*digits += 1;
			(*i)++;
		}
	}
	return (1);
}

int	check_float_input(const char *str, int allow_comma)
{
	int	i;
	int	digits;

	i = check_float_input_prep(str, &digits);
	while (ft_isdigit(str[i]))
	{
		if (digits == 6)
			return (0);
		digits++;
		i++;
	}
	if (!check_float_decimals(str, &i, &digits))
		return (0);
	if (str[i] && !(str[i] == ',' && allow_comma)
		&& !(str[i] >= 0x9 && str[i] <= 0xD))
		return (0);
	if (!digits)
		return (0);
	return (1);
}
