/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils_common.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:45:25 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/18 02:20:35 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	check_vec_input(char *str)
{
	while (*str)
	{
		if (*str == ',' && (*(str + 1) == ',' || !*(str + 1)))
			return (0);
		str++;
	}
	return (1);
}

static int	validate_t_norm_coeffs(t_parser *parser, int type, char *ref)
{
	float	val;

	if (type == NORM_VALD)
	{
		val = ft_atof(ref);
		if (val > 1.0f || val < -1.0f)
		{
			issue_report(parser, ERR_INVALID_NFLOAT);
			return (0);
		}
	}
	else if (type == COEFFS_VALD)
	{
		val = ft_atof(ref);
		if (val > 1000.0f || val < 0.1f)
		{
			issue_report(parser, ERR_INVALID_COEFF);
			return (0);
		}
	}
	return (1);
}

static int	validate_iter_tuple(t_parser *parser,
	char **split_vec, int type)
{
	size_t	i;

	i = 0;
	while (split_vec[i])
	{
		if (!check_float_input(split_vec[i]))
		{
			issue_report(parser, ERR_INVALID_FLOAT);
			return (0);
		}
		if (!validate_t_norm_coeffs(parser, type, split_vec[i]))
			return (0);
		i++;
		parser->problem_pos++;
	}
	return (1);
}

char	**pre_tuple_validation(t_parser *parser)
{
	char	*token;
	char	**split_vec;

	token = ft_strtok_iter(0, parser, 1);
	if (!token)
		return (0);
	if (!check_vec_input(token)
		|| ft_getchr_count(token, ',') != 2)
	{
		issue_report(parser, ERR_INVALID_TUPLE);
		return (0);
	}
	split_vec = ft_split(token, ',');
	if (!split_vec)
	{
		perror("malloc");
		return (0);
	}
	return (split_vec);
}

int	validate_tuple(t_parser *parser, int type)
{
	char	**split_vec;
	int		res;

	split_vec = pre_tuple_validation(parser);
	if (!split_vec)
		return (0);
	res = validate_iter_tuple(parser, split_vec, type);
	free_array((void **)split_vec);
	return (res);
}
