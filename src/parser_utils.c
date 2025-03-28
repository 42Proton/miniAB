/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:18:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/10 13:53:31 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

char	*ft_strtok_iter(char *line,
	t_parser *parser, int expect_tok)
{
	char	*tmp;

	parser->problem_pos = 0;
	if (line)
		tmp = ft_strtok(line, " \t\r\f\v\n");
	else
		tmp = ft_strtok(NULL, " \t\r\f\v\n");
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
	parser->tok_pos = -1;
	parser->problem_pos = 0;
	parser->token = 0;
}
