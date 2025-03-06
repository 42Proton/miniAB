/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:58:26 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/06 23:47:25 by amsaleh          ###   ########.fr       */
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
}	t_parser;

int			check_float_input(const char *str, int allow_comma);
char		*ft_strtok_iter(t_parser *parser, int expect_tok);
int			read_iter_line(int fd, t_parser *parser);
void		reset_parser_props(t_parser *parser);
t_tuple		*init_vector();
t_colors	*init_colors();

#endif