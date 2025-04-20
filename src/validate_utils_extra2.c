/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils_extra2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:06:16 by bismail           #+#    #+#             */
/*   Updated: 2025/04/18 21:44:33 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	validate_iter_vec_misc(t_parser *parser,
	char **split_vec)
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
		val = ft_atof(split_vec[i]);
		if ((i != 2 && (val > 1.0f || val < 0))
			|| (i == 2 && (val > 1000.0f || val < 0)))
		{
			issue_report(parser, ERR_INVALID_RATIO);
			return (0);
		}
		i++;
		parser->problem_pos++;
	}
	return (1);
}

char	**pre_vec_validation_misc(t_parser *parser, char *token)
{
	char	**split_vec;

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

int	validate_phong(t_parser *parser, char *tok)
{
	char	**split_vec;
	int		res;

	if (parser->phong_done)
	{
		issue_report(parser, ERR_EXTRA_TOK);
		return (0);
	}
	split_vec = pre_vec_validation_misc(parser, tok + 6);
	if (!split_vec)
		return (0);
	res = validate_iter_vec_misc(parser, split_vec);
	free_array((void **)split_vec);
	parser->phong_done = 1;
	return (res);
}
