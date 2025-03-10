/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:31:29 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/10 15:56:39 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	validate_object(t_parser *parser, int type)
{
	int	res;

	res = 0;
	printf("TYPE %d\n", type);
	if (type == AMBIENTLIGHT)
		res = validate_alight(parser);
	else if (type == PLANE)
		res = validate_plane(parser);
	else if (type == CYLINDER)
		res = validate_cylinder(parser);
	else if (type == SPHERE)
		res = validate_sphere(parser);
	printf("res %d \n---------\n", res);
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
