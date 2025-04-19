/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils_extra.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:23:21 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/19 23:12:05 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

char	*ft_strtok_iter_nr(t_parser *parser)
{
	char	*tmp;

	parser->problem_pos = 0;
	tmp = ft_strtok(NULL, " \t\r\f\v\n");
	parser->tok_pos++;
	return (tmp);
}

int	check_textures_list(char *str, t_list *textures_list)
{
	while (textures_list)
	{
		if (!ft_strcmp(str, textures_list->content))
			return (1);
		textures_list = textures_list->next;
	}
	return (0);
}

int	validate_map(t_parser *parser, char *tok)
{
	int	type;

	type = 0;
	if (!ft_strncmp(tok, "color:", 6))
		type = 1;
	if ((type && parser->color_done)
		|| (!type && parser->bump_done))
	{
		issue_report(parser, ERR_EXTRA_TOK);
		return (0);
	}
	tok = ft_strchr(tok, ':');
	tok++;
	if (!check_textures_list(tok, parser->textures_list))
	{
		simple_report(ERR_UNKNOWN_TEXTURE);
		return (0);
	}
	if (type)
		parser->color_done = 1;
	else
		parser->bump_done = 1;
	return (1);
}

int	validate_reflect(t_parser *parser, char *tok)
{
	float	val;

	if (parser->reflect_done)
	{
		issue_report(parser, ERR_EXTRA_TOK);
		return (0);
	}
	tok = ft_strchr(tok, ':');
	tok++;
	if (!check_float_input(tok))
	{
		issue_report(parser, ERR_INVALID_FLOAT);
		return (0);
	}
	val = ft_atof(tok);
	if (val < 0 || val > 1)
	{
		issue_report(parser, ERR_INVALID_RATIO);
		return (0);
	}
	parser->reflect_done = 1;
	return (1);
}

int	validate_misc(t_parser *parser)
{
	char	*tok;
	int		res;

	tok = ft_strtok_iter_nr(parser);
	while (tok)
	{
		res = 0;
		if (!ft_strncmp(tok, "phong:", 6))
			res = validate_phong(parser, tok);
		else if (!ft_strncmp(tok, "color:", 6)
			|| !ft_strncmp(tok, "bump:", 5))
			res = validate_map(parser, tok);
		else if (!ft_strncmp(tok, "reflect:", 8))
			res = validate_reflect(parser, tok);
		else
			simple_report(ERR_UNKNOWN_MISC);
		if (!res)
			return (0);
		tok = ft_strtok_iter_nr(parser);
	}
	return (1);
}
