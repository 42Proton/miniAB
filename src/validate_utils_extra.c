/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils_extra.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:23:21 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/10 02:16:54 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	validate_iter_vec_misc(t_parser *parser,
	char **split_vec)
{
	size_t	i;
	float	val;

	i = 0;
	while (split_vec[i])
	{
		if (!check_float_input(split_vec[i]))
		{
			issue_report(parser, ERR_INVALID_FLOAT);
			return (0);
		}
		val = ft_atof(split_vec[i]);
		if ((i != 2 && (val > 1.0f || val < 0))
			|| (i == 2 && (val > 1000.0f || val < 0)))
		{
			issue_report(parser, ERR_INVALID_RATIO);
			return (0);
		}
		i++;
		parser->problem_pos++;
	}
	return (1);
}

char	**pre_vec_validation_misc(t_parser *parser, char *token)
{
	char	**split_vec;

	if (!check_vec_input(token)
		|| ft_getchr_count(token, ',') != 2)
	{
		issue_report(parser, ERR_INVALID_VEC);
		return (0);
	}
	split_vec = ft_split(token, ',');
	if (!split_vec)
	{
		perror("malloc");
		return (0);
	}
	return (split_vec);
}

int	validate_phong(t_parser *parser, char *tok)
{
	char	**split_vec;
	int		res;

	if (parser->phong_done)
	{
		issue_report(parser, ERR_EXTRA_TOK);
		return (0);
	}
	split_vec = pre_vec_validation_misc(parser, tok + 6);
	if (!split_vec)
		return (0);
	res = validate_iter_vec_misc(parser, split_vec);
	free_array((void **)split_vec);
	parser->phong_done = 1;
	return (res);
}

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

int	validate_misc(t_parser *parser)
{
	char	*tok;
	int		res;

	tok = ft_strtok_iter_nr(parser);
	while (tok)
	{
		if (parser->phong_done && parser->bump_done && parser->color_done)
		{
			simple_report(ERR_EXTRA_TOK);
			return (0);
		}
		res = 0;
		if (!ft_strncmp(tok, "phong:", 6))
			res = validate_phong(parser, tok);
		else if (!ft_strncmp(tok, "color:", 6)
			|| !ft_strncmp(tok, "bump:", 5))
			res = validate_map(parser, tok);
		else
			simple_report(ERR_UNKNOWN_MISC);
		if (!res)
			return (0);
		tok = ft_strtok_iter_nr(parser);
	}
	return (1);
}
