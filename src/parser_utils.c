/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:18:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/12 17:45:15 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

char	*ft_strtok_iter(char *line, t_parser *parser, int expect_tok)
{
	char	*tmp;

	parser->problem_pos = 0;
	tmp = ft_strtok(line, " \t\r\f\v\n");
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
	parser->phong_done = 0;
	parser->bump_done = 0;
	parser->color_done = 0;
}

int	prep_objs_postparse(t_rtptr *rts)
{
	t_list			*tmp;
	t_object_entry	*entry;
	void			*obj;
	int				res;

	tmp = rts->solid_objs;
	while (tmp)
	{
		entry = (t_object_entry *)tmp->content;
		obj = entry->object;
		if (entry->type == SPHERE)
			res = sphere_postparse(rts, (t_sphere *)obj);
		else if (entry->type == PLANE)
			res = plane_postparse(rts, (t_plane *)obj);
		else if (entry->type == CYLINDER)
			res = cylinder_postparse(rts, (t_cylinder *)obj);
		else if (entry->type == HYPER)
			res = hyper_postparse(rts, (t_hyper *)obj);
		if (!res)
			return (EXIT_FAILURE);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
