/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:37:37 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/05 22:14:03 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	clear_obj(void *content)
{
	free(content);
	//to be expanded when objects properties expand
}

void	cleaner(t_rtptr *rts)
{
	if (rts->img)
		mlx_delete_image(rts->mlx, rts->img);
	if (rts->mlx)
		mlx_terminate(rts->mlx);
	ft_lstclear(&rts->objs, clear_obj);
	exit(EXIT_SUCCESS);
}

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

void	issue_report(t_parser *parser, int issue)
{
	size_t	row;
	size_t	old_row;
	char	tmp[129];

	row = goto_token_pos(parser);
	old_row = row;
	row = goto_problem_pos(parser, row);
	ft_dprintf(2, "Error\n");
	ft_dprintf(2, "%s:%lu:%lu\n", parser->file_name,
		parser->line_pos, row);
	ft_strncpy(tmp, parser->token, 128);
	ft_dprintf(2, "%s\n", tmp);
	if (row - old_row > 0)
		ft_memset(tmp, ' ', (row - old_row) - 1);
	tmp[row - old_row] = '^';
	tmp[(row - old_row) + 1] = 0;
	ft_dprintf(2, "\e[091m%s\n", tmp);
	if (issue == ERR_INVALID_FLOAT)
		ft_dprintf(2, "Invalid float input\e[39m\n");
	if (issue == ERR_OBJ_TYPE)
		ft_dprintf(2, "Unknown object\e[39m\n");
}
