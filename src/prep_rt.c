/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:40:43 by bismail           #+#    #+#             */
/*   Updated: 2025/04/14 14:41:05 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	prep_textures_iter(DIR *dir, t_rtptr *rts)
{
	struct dirent	*entry;
	char			*str;
	t_list			*node;

	entry = readdir(dir);
	while (entry)
	{
		str = ft_strdup(entry->d_name);
		if (!str)
			return (EXIT_FAILURE);
		node = ft_lstnew_protect(str, free);
		if (!node)
			return (EXIT_FAILURE);
		ft_lstadd_back(&rts->textures_list, node);
		entry = readdir(dir);
	}
	return (EXIT_SUCCESS);
}

int	prep_textures(t_rtptr *rts)
{
	DIR	*dir;
	int	res;

	dir = opendir("./textures");
	if (!dir)
		return (EXIT_SUCCESS);
	res = prep_textures_iter(dir, rts);
	closedir(dir);
	if (res)
		perror("malloc");
	return (res);
}

int	prep_rt_core(int ac, char **av, t_rtptr *rts)
{
	ft_bzero(rts, sizeof(t_rtptr));
	if (check_args(ac, av))
		return (EXIT_FAILURE);
	if (prep_textures(rts))
		return (EXIT_FAILURE);
	if (parser(av[1], rts))
		return (EXIT_FAILURE);
	split_objs(rts);
	if (handle_missing_objs(rts))
		return (EXIT_FAILURE);
	if (load_textures(rts))
		return (EXIT_FAILURE);
	if (prep_objs_postparse(rts))
		return (EXIT_FAILURE);
	if (!camera_portparse(rts->camera))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}