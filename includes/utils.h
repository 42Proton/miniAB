/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:58:26 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/14 21:02:28 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <object.h>

typedef struct s_parser
{
	t_list	*textures_list;
	char	*file_name;
	char	*line;
	char	*line_bak;
	size_t	line_pos;
	char	*token;
	int		tok_pos;
	int		problem_pos;
	int		errorflag;
	int		phong_done;
	int		color_done;
	int		bump_done;
}			t_parser;

int			check_float_input(const char *str);
char		*ft_strtok_iter(char *line, t_parser *parser, int expect_tok);
int			read_iter_line(int fd, t_parser *parser);
void		reset_parser_props(t_parser *parser);
void		object_cleanup(void *content);
// Validations set
int			validate_tuple(t_parser *parser, int type);
int			validate_color(t_parser *parser);
int			validate_input(t_parser *parser);
int			validate_alight(t_parser *parser);
int			validate_camera(t_parser *parser);
int			validate_light(t_parser *parser);
int			validate_plane(t_parser *parser);
int			validate_cylinder(t_parser *parser);
int			validate_sphere(t_parser *parser);
int			validate_hyper(t_parser *parser);
// Rest
int			switch_type(char *obj);
int			check_vec_input(char *str);
//Report utils
void		issue_report_msg(int issue);

#endif