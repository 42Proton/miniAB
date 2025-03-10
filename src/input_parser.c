/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 23:41:06 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/10 03:50:48 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	switch_type(char *obj)
{
	if (!ft_strcmp(obj, "A"))
		return (AMBIENTLIGHT);
	else if (!ft_strcmp(obj, "L"))
		return (LIGHT);
	else if (!ft_strcmp(obj, "C"))
		return (CAMERA);
	else if (!ft_strcmp(obj, "sp"))
		return (SPHERE);
	else if (!ft_strcmp(obj, "pl"))
		return (PLANE);
	else if (!ft_strcmp(obj, "cy"))
		return (CYLINDER);
	else if (!ft_strcmp(obj, "hy"))
		return (HYPER);
	else if (!ft_strcmp(obj, "par"))
		return (PARA);
	return (-1);
}

int	process_line_data(t_parser *parser, t_rtptr *rts)
{
	int				type;
	t_object_entry	*entry;
	t_list			*lst;

	parser->token = ft_strtok(parser->line, " \t\r\f\v");
	type = switch_type(parser->token);
	entry = objectify(parser, type);
	if (!entry)
	{
		perror("malloc");
		return (EXIT_FAILURE);
	}
	lst = ft_lstnew_protect(entry, object_cleanup);
	if (!lst)
	{
		perror("malloc");
		return (EXIT_FAILURE);
	}
	ft_lstadd_back(&rts->objs, lst);
	return (EXIT_SUCCESS);
}

int	read_file(char *file_name, int fd, t_rtptr *rts)
{
	t_parser	parser;

	ft_bzero(&parser, sizeof(t_parser));
	parser.file_name = file_name;
	parser.tok_pos = -1;
	while (1)
	{
		if (read_iter_line(fd, &parser))
			return (EXIT_FAILURE);
		if (!parser.line)
			return (EXIT_SUCCESS);
		if (validate_input(&parser) || process_line_data(&parser, rts))
		{
			reset_parser_props(&parser);
			return (EXIT_FAILURE);
		}
		reset_parser_props(&parser);
	}
}

int	parser(char *file_name, t_rtptr *rts)
{
	int	fd;

	fd = open(file_name, R_OK);
	if (fd == -1)
	{
		simple_report(ERR_OPEN_FILE);
		return (EXIT_FAILURE);
	}
	if (read_file(file_name, fd, rts) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
