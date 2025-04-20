/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_vision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:32:34 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/14 21:05:33 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	check_ratio_input(t_parser *parser)
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
		issue_report(parser, ERR_INVALID_RATIO);
		return (0);
	}
	return (1);
}

static int	check_fov_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '0' && str[i + 1])
		return (0);
	while (str[i])
	{
		if (i == 3)
			return (0);
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	i = ft_atoi(str);
	if (i < 0 || i > 180)
		return (0);
	return (1);
}

int	validate_alight(t_parser *parser)
{
	char	*tok;

	if (!check_ratio_input(parser))
		return (0);
	if (!validate_color(parser))
		return (0);
	tok = ft_strtok_iter(NULL, parser, 0);
	if (tok)
		return (0);
	return (1);
}

int	validate_camera(t_parser *parser)
{
	char	*tok;

	if (!validate_tuple(parser, DEFAULT_VALD))
		return (0);
	if (!validate_tuple(parser, NORM_VALD))
		return (0);
	tok = ft_strtok_iter(NULL, parser, 1);
	if (!tok)
		return (0);
	if (!check_fov_input(tok))
	{
		issue_report(parser, ERR_INVALID_FOV);
		return (0);
	}
	tok = ft_strtok_iter(NULL, parser, 0);
	if (tok)
		return (0);
	return (1);
}

int	validate_light(t_parser *parser)
{
	char	*tok;

	if (!validate_tuple(parser, DEFAULT_VALD))
		return (0);
	if (!check_ratio_input(parser))
		return (0);
	if (!validate_color(parser))
		return (0);
	tok = ft_strtok_iter(NULL, parser, 0);
	if (tok)
		return (0);
	return (1);
}
