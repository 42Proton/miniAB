/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:13:39 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/10 13:53:46 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	check_color_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '0' && str[i + 1])
		return (0);
	while (str[i])
	{
		if (i == 3)
			return (0);
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	i = ft_atoi(str);
	if (i < 0 || i > 255)
		return (0);
	return (1);
}

static int	validate_iter_color(t_parser *parser,
	char **split_color)
{
	size_t	i;

	i = 0;
	while (split_color[i])
	{
		if (!check_color_input(split_color[i]))
		{
			issue_report(parser, ERR_INVALID_COLOR);
			return (0);
		}
		i++;
		parser->problem_pos++;
	}
	return (1);
}

static char	**pre_color_validation(t_parser *parser)
{
	char	*token;
	char	**split_color;
	size_t	comma_count;

	token = ft_strtok_iter(0, parser, 1);
	if (!token)
		return (0);
	comma_count = ft_getchr_count(token, ',');
	if (!check_vec_input(token)
		|| comma_count < 2 || comma_count > 3)
	{
		issue_report(parser, ERR_INVALID_RGB);
		return (0);
	}
	split_color = ft_split(token, ',');
	if (!split_color)
	{
		perror("malloc");
		return (0);
	}
	return (split_color);
}

int	validate_color(t_parser *parser)
{
	char	**split_color;
	int		res;

	split_color = pre_color_validation(parser);
	if (!split_color)
		return (0);
	res = validate_iter_color(parser, split_color);
	free_array((void **)split_color);
	return (res);
}
