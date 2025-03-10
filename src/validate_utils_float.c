/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils_float.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:21:31 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/09 23:00:10 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	check_float_input_prep(const char *str,
	int *digits, int *is_zero_start)
{
	int	i;

	i = 0;
	*digits = 0;
	*is_zero_start = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '0')
		*is_zero_start = 1;
	while (str[i] == '0')
		i++;
	return (i);
}

static int	check_float_decimals(const char *str,
	int *i, int *digits)
{
	int	old_digits;

	old_digits = *digits;
	if (str[*i] == '.')
	{
		(*i)++;
		if (str[*i] && !ft_isdigit(str[*i]))
			return (0);
		while (ft_isdigit(str[*i]))
		{
			if (*digits > old_digits + 5)
				return (0);
			*digits += 1;
			(*i)++;
		}
	}
	return (1);
}

int	check_float_input(const char *str)
{
	int	i;
	int	digits;
	int	is_zero_start;

	i = check_float_input_prep(str, &digits, &is_zero_start);
	while (ft_isdigit(str[i]))
	{
		if (digits == 6)
			return (0);
		digits++;
		i++;
	}
	if (!check_float_decimals(str, &i, &digits))
		return (0);
	if (str[i] && !ft_isspace(str[i]))
		return (0);
	if (!digits && !is_zero_start)
		return (0);
	return (1);
}
