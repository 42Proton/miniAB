/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/04/08 19:23:31 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>
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
	{
		perror("opendir");
		return (EXIT_FAILURE);
	}
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
	if (prep_objs_postparse(rts))
		return (EXIT_FAILURE);
	if (!camera_portparse(rts->camera))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_rtptr		rts;

	if (prep_rt_core(ac, av, &rts))
		cleaner(&rts);
	if (init_mlx(&rts))
		cleaner(&rts);
	mlx_image_to_window(rts.mlx, rts.img, 0, 0);
	render_viewport(&rts);
	mlx_key_hook(rts.mlx, keyhook, &rts);
	mlx_loop(rts.mlx);
	cleaner(&rts);
	return (0);
}
