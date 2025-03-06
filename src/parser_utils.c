/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:18:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/06 23:59:55 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	check_float_input_prep(const char *str, int *digits)
{
	int	i;

	i = 0;
	*digits = 0;
	while (ft_isspace(str[i]))
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

char	*ft_strtok_iter(t_parser *parser, int expect_tok)
{
	char	*tmp;

	tmp = ft_strtok(NULL, " \t\r\f\v");
	parser->tok_pos++;
	if (!tmp && expect_tok)
		issue_report(parser, ERR_MISSING_TOK);
	if (tmp && !expect_tok)
		issue_report(parser, ERR_EXTRA_TOK);
	return (tmp);
}

int	read_iter_line(int fd, t_parser *parser)
{
	parser->line_pos++;
	parser->line = get_next_line(fd, 0, &parser->errorflag);
	if (parser->errorflag)
	{
		perror("malloc");
		get_next_line(fd, 1, &parser->errorflag);
		reset_parser_props(parser);
		return (EXIT_FAILURE);
	}
	if (!parser->line)
		return (EXIT_SUCCESS);
	parser->line_bak = ft_strdup(parser->line);
	if (!parser->line_bak)
	{
		perror("malloc");
		get_next_line(fd, 1, &parser->errorflag);
		reset_parser_props(parser);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	reset_parser_props(t_parser *parser)
{
	free(parser->line);
	free(parser->line_bak);
	parser->line = 0;
	parser->line_bak = 0;
	parser->tok_pos = 0;
	parser->problem_pos = 0;
	parser->token = 0;
}

t_tuple	*init_vector()
{
	char	**split_vec;
	t_tuple	*res;

	split_vec = ft_split(ft_strtok(0, " \t\r\f\v"), ',');
	if (!split_vec)
		return (0);
	res = point(ft_atof(split_vec[0]),
		ft_atof(split_vec[1]), ft_atof(split_vec[2]));
	free_array((void **)split_vec);
	return (res);
}

t_colors	*init_colors()
{
	char		**split_colors;
	t_colors	*res;
	int			red;
	int			green;
	int			blue;
	float		alpha;

	split_colors = ft_split(ft_strtok(0, " \t\r\f\v"), ',');
	if (!split_colors)
		return (0);
	red = ft_atoi(split_colors[0]);
	green = ft_atoi(split_colors[1]);
	blue = ft_atoi(split_colors[2]);
	alpha = 1;
	if (ft_arrlen((void **)split_colors) > 3)
		alpha = alpha_ftos(ft_atof(split_colors[3]));
	res = colorinit(red, green, blue, alpha);
	free_array((void **)split_colors);
	return (res);
}