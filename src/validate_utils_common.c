/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils_common.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:45:25 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/27 17:49:27 by amsaleh          ###   ########.fr       */
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

static int	validate_iter_vec(t_parser *parser,
	char **split_vec, int is_norm)
{
	size_t	i;
	float	val;

	i = 0;
	while (split_vec[i])
	{
		if (!check_float_input(split_vec[i]))
		{
			issue_report(parser, ERR_INVALID_FLOAT);
			return (0);
		}
		if (is_norm)
		{
			val = ft_atof(split_vec[i]);
			if (val > 1.0f || val < -1.0f)
			{
				issue_report(parser, ERR_INVALID_NFLOAT);
				return (0);
			}
		}
		i++;
		parser->problem_pos++;
	}
	return (1);
}

static char	**pre_vec_validation(t_parser *parser)
{
	char	*token;
	char	**split_vec;

	token = ft_strtok_iter(0, parser, 1);
	if (!token)
		return (0);
	if (!check_vec_input(token)
		|| ft_getchr_count(token, ',') != 2)
	{
		issue_report(parser, ERR_INVALID_VEC);
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

int	validate_pos(t_parser *parser)
{
	char	**split_vec;
	int		res;

	split_vec = pre_vec_validation(parser);
	if (!split_vec)
		return (0);
	res = validate_iter_vec(parser, split_vec, 0);
	free_array((void **)split_vec);
	return (res);
}

int	validate_normal(t_parser *parser)
{
	char	**split_vec;
	int		res;

	split_vec = pre_vec_validation(parser);
	if (!split_vec)
		return (0);
	res = validate_iter_vec(parser, split_vec, 1);
	free_array((void **)split_vec);
	return (res);
}
