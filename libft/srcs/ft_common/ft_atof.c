/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:44:42 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/05 02:15:05 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	atof_prep_value(const char *str,
	int *n_digits, int *sign, double *res)
{
	int	i;

	i = 0;
	*n_digits = 0;
	*sign = 1;
	*res = 0;
	while ((str[i] >= 0x9 && str[i] <= 0xD) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		*sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i]))
	{
		*res = *res * 10 + (str[i] - 0x30);
		i++;
		*n_digits += 1;
	}
	return (i);
}

static int	atof_prep_decimals(const char *str,
	int *n_digits, int *i, double *res)
{
	int	n_decimals;

	n_decimals = 0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (ft_isdigit(str[*i]))
		{
			*res = *res * 10 + (str[*i] - 0x30);
			(*i)++;
			n_digits += 1;
			n_decimals++;
		}
	}
	return (n_decimals);
}

static double	atof_pow_calc(int n_decimals)
{
	double	pow_val;

	pow_val = 10;
	while (--n_decimals)
		pow_val *= 10;
	return (pow_val);
}

float	ft_atof(const char *str, char **endptr)
{
	double	res;
	int		i;
	int		sign;
	int		n_digits;
	int		n_decimals;

	i = atof_prep_value(str, &n_digits, &sign, &res);
	n_decimals = atof_prep_decimals(str, &n_digits, &i, &res);
	if (!n_digits)
	{
		if (endptr)
			*endptr = (char *)str + i;
		return (0);
	}
	if (n_decimals)
		res /= atof_pow_calc(n_decimals);
	if (endptr)
		*endptr = (char *)str + i;
	return (res * sign);
}
