/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:07:05 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/10 15:47:41 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	validate_plane(t_parser *parser)
{
	char	*tok;

	if (!validate_pos(parser))
		return (0);
	if (!validate_normal(parser))
		return (0);
	if (!validate_color(parser))
		return (0);
	tok = ft_strtok_iter(NULL, parser, 0);
	if (tok)
		return (0);
	return (1);
}

int	validate_cylinder(t_parser *parser)
{
	char	*tok;
	short	iter;

	iter = 2;
	if (!validate_pos(parser))
		return (0);
	if (!validate_normal(parser))
		return (0);
	while (iter--)
	{
		tok = ft_strtok_iter(NULL, parser, 1);
		if (!tok)
			return (0);
		if (!check_float_input(tok) || (ft_atof(tok) < 0))
		{
			issue_report(parser, ERR_INVALID_FLOAT);
			return (0);
		}
	}
	if (!validate_color(parser))
		return (0);
	tok = ft_strtok_iter(NULL, parser, 0);
	if (tok)
		return (0);
	return (1);
}
