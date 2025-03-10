/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:58:26 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/10 03:43:53 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <object.h>

typedef struct s_parser
{
	char	*file_name;
	char	*line;
	char	*line_bak;
	size_t	line_pos;
	char	*token;
	int		tok_pos;
	int		problem_pos;
	int		errorflag;
}			t_parser;

int			check_float_input(const char *str);
char		*ft_strtok_iter(char *line,
				t_parser *parser, int expect_tok);
int			read_iter_line(int fd, t_parser *parser);
void		reset_parser_props(t_parser *parser);
void		object_cleanup(void *content);
int			validate_pos(t_parser *parser);
int			validate_normal(t_parser *parser);
int			validate_color(t_parser *parser);
int			validate_input(t_parser *parser);
int			validate_alight(t_parser *parser);
int			switch_type(char *obj);
int			check_vec_input(char *str);

#endif