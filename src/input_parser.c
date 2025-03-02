/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abueskander <abueskander@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 23:41:06 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/02 11:37:39 by abueskander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	switch_object(char *obj)
{
	if (!ft_strcmp(obj, "A"))
		return (AMBIENTLIGHT);
	else if (!ft_strcmp(obj, "L"))
		return (LIGHT);
	else if (!ft_strcmp(obj, "C"))
		return (CAMERA);
	else if (!ft_strcmp(obj, "sp"))
		return (SPHERE);
	else if (!ft_strcmp(obj, "pl"))
		return (PLANE);
	else if (!ft_strcmp(obj, "cy"))
		return (CYLINDER);
	else if (!ft_strcmp(obj, "hy"))
		return (HYPER);
	else if (!ft_strcmp(obj, "par"))
		return (PARA);
	return (-1);
}

int	get_type(char *object, t_rtptr *rts)
{
	char		*splited;
	int			type;
	t_object	*obj;

	splited = ft_strtok(object, " \t\b\r\f\v\n");
	type = switch_object(splited);
	obj = objectify(type);
	if (type == -1)
		cleaner(rts, "Invalid Type");
	ft_lstadd_back(&rts->objs, ft_lstnew(obj));
	return (EXIT_SUCCESS);
}

int	read_file(char *file_name, int fd, t_rtptr *rts)
{
	char	*process;
	int		errorflag;

	while (1)
	{
		process = get_next_line(fd, 0, &errorflag);
		if (!errorflag)
		{
			get_next_line(fd, 1, &errorflag);
			return (EXIT_FAILURE);
		}
		if (get_type(process, rts))
			return (EXIT_FAILURE);
	}
}
int	parser(char *file_name, t_rtptr *rts)
{
	int fd;

	fd = open(file_name, R_OK);
	if (fd == -1)
		return (EXIT_FAILURE);
	if (!read_file(file_name, fd, rts))
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}