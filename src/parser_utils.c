/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:18:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/07 01:14:21 by abueskander      ###   ########.fr       */
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
	if (str[i] && !(str[i] == ',' && allow_comma) && !(str[i] >= 0x9
			&& str[i] <= 0xD))
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
