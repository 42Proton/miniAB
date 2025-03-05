/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 01:17:49 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/05 21:39:18 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	al_prep_ratio(t_alight *al, t_parser *parser)
{
	parser->token = ft_strtok_iter(parser, 1);
	if (!parser->token)
	{
		free(al);
		return (0);
	}
	if (!check_float_input(parser->token, 0))
	{
		issue_report(parser, ERR_INVALID_FLOAT);
		free(al);
		return (0);
	}
	al->ratio = ft_atof(parser->token);
	return (1);
}

// static int	al_prep_color(t_alight *al, t_parser *parser)
// {
// 	char	*tmp;

// 	tmp = ft_strtok_iter(parser, 1);
// 	if (!tmp)
// 	{
// 		free(al);
// 		return (0);
// 	}
// 	return (1);
// }

void	*ambient_light(t_parser *parser, int *type)
{
	t_alight *al;

	*type = AMBIENTLIGHT;
	al = malloc(sizeof(t_alight));
	if (!al)
	{
		perror("malloc");
		return (NULL);
	}
	if (!al_prep_ratio(al, parser))
		return (0);
	return (al);
}
