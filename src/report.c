/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:38:08 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/07 00:38:35 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static size_t	goto_token_pos(t_parser *parser)
{
	size_t	i;
	int		pos;

	pos = 0;
	i = 0;
	while (pos != parser->tok_pos)
	{
		while (ft_isspace(parser->line_bak[i]))
			i++;
		while (!ft_isspace(parser->line_bak[i]))
			i++;
		pos++;
	}
	while (ft_isspace(parser->line_bak[i]))
		i++;
	return (i);
}

static size_t	goto_problem_pos(t_parser *parser, size_t row)
{
	size_t	i;
	int		pos;

	i = row;
	pos = 0;
	while (pos != parser->problem_pos)
	{
		while (parser->line_bak[i] != ',')
			i++;
		i++;
		pos++;
	}
	return (i);
}

void	simple_report(int issue)
{
	char	*msg;

	msg = "Unknown error";
	if (issue == ERR_FILE_EXT)
		msg = "Incorrect file extension";
	if (issue == ERR_ARGS_COUNT)
		msg = "Incorrect arguments count";
	if (issue == ERR_OPEN_FILE)
		msg = "Error opening file";
	ft_dprintf(2, "\e[091mError\n%s\e[039m\n", msg);
}

void	issue_report_highlight(size_t row, char *tmp, t_parser *parser)
{
	if (row > 80)
		ft_strncpy(tmp, parser->line_bak + row, ft_strlen(parser->line_bak
				+ row) - 1);
	else
		ft_strncpy(tmp, parser->line_bak, ft_strlen(parser->line_bak) - 1);
	ft_dprintf(2, "%s\n", tmp);
	if (row < 80)
	{
		ft_memset(tmp, ' ', row);
		tmp[row] = '^';
		tmp[row + 1] = 0;
	}
	else
	{
		tmp[0] = '^';
		tmp[1] = 0;
	}
}

void	issue_report(t_parser *parser, int issue)
{
	size_t row;
	char tmp[81];

	row = goto_token_pos(parser);
	row = goto_problem_pos(parser, row);
	ft_dprintf(2, "Error\n");
	ft_dprintf(2, "%s:%lu:%lu\n", parser->file_name, parser->line_pos, row);
	issue_report_highlight(row, tmp, parser);
	ft_dprintf(2, "\e[091m%s\n", tmp);
	if (issue == ERR_INVALID_FLOAT)
		ft_dprintf(2, "Invalid float input\e[39m\n");
	if (issue == ERR_OBJ_TYPE)
		ft_dprintf(2, "Unknown object\e[39m\n");
}