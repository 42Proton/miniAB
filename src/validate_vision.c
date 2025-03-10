/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_vision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:32:34 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/10 03:59:03 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	validate_alight(t_parser *parser)
{
	char	*tok;
	float	val;

	tok = ft_strtok_iter(NULL, parser, 1);
	if (!tok)
		return (0);
	if (!check_float_input(tok))
	{
		issue_report(parser, ERR_INVALID_FLOAT);
		return (0);
	}
	val = ft_atof(tok);
	if (val < 0.0f || val > 1.0f)
	{
		printf("%d\n", parser->tok_pos);
		issue_report(parser, ERR_INVALID_RATIO);
		return (0);
	}
	if (!validate_color(parser))
		return (0);
	tok = ft_strtok_iter(NULL, parser, 0);
	if (tok)
		return (0);
	return (1);
}
