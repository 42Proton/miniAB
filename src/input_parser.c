/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 23:41:06 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/01 00:11:33 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

char	**read_file(char *file_name)
{
	int	fd;

	// char	**file;
	fd = open(file_name, R_OK);
	if (fd == -1)
		return (NULL);
	else
		return (EXIT_SUCCESS);
}
int	parser(char *file_name)
{
	char **file;

	file = read_file(file_name);
	if (!file)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}