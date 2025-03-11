/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:31:29 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/11 15:22:32 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	validate_object(t_parser *parser, int type)
{
	int	res;

	res = 0;
	if (type == AMBIENTLIGHT)
		res = validate_alight(parser);
	else if (type == CAMERA)
		res = validate_camera(parser);
	else if (type == LIGHT)
		res = validate_light(parser);
	else if (type == PLANE)
		res = validate_plane(parser);
	else if (type == CYLINDER)
		res = validate_cylinder(parser);
	else if (type == SPHERE)
		res = validate_sphere(parser);
	return (res);
}

int	validate_input(t_parser *parser)
{
	int	type;

	parser->token = ft_strtok_iter(parser->line, parser, 1);
	if (!parser->token)
		return (EXIT_FAILURE);
	type = switch_type(parser->token);
	if (type == -1)
	{
		issue_report(parser, ERR_OBJ_TYPE);
		return (EXIT_FAILURE);
	}
	if (!validate_object(parser, type))
		return (EXIT_FAILURE);
	free(parser->line);
	parser->line = ft_strdup(parser->line_bak);
	if (!parser->line)
	{
		perror("malloc");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
