/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:07:05 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/10 15:10:41 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	validate_plane(t_parser *parser)
{
	char *tok;

	// tok = ft_strtok_iter(NULL, parser, 1);
	// if (!tok)
	// 	return (0);
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