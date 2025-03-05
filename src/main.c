/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:55:48 by abueskander       #+#    #+#             */
/*   Updated: 2025/03/05 22:19:00 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	main(int argc, char **argv)
{
	t_rtptr	rts;

	ft_bzero(&rts, sizeof(t_rtptr));
	if (check_args(argc, argv))
		return (EXIT_FAILURE);
	// float testing
	// printf("TEST 1: %d\n", check_float_input(ft_strdup("123131.213213.231231"), 0));
	// printf("TEST 2: %d\n", check_float_input(ft_strdup("1000000"), 0));
	// printf("TEST 3: %d\n", check_float_input(ft_strdup("999999"), 0));
	// printf("TEST 4: %d\n", check_float_input(ft_strdup("-999999.21434"), 0));
	// printf("TEST 5: %d\n", check_float_input(ft_strdup("-1000000"), 0));
	// printf("TEST 6: %d\n", check_float_input(ft_strdup("9-9"), 0));
	// printf("TEST 7: %d\n", check_float_input(ft_strdup("         \t\r9,8"), 1));
	// printf("TEST 8: %d\n", check_float_input(ft_strdup(""), 0));

	// printf("TEST 1: %f\n", ft_atof(ft_strdup("123131.213213.231231")));
	// printf("TEST 2: %f\n", ft_atof(ft_strdup("1000000")));
	// printf("TEST 3: %f\n", ft_atof(ft_strdup("999999")));
	// printf("TEST 4: %f\n", ft_atof(ft_strdup("-999999.21434")));
	// printf("TEST 5: %f\n", ft_atof(ft_strdup("-1000000")));
	// printf("TEST 6: %f\n", ft_atof(ft_strdup("9-9")));
	// printf("TEST 7: %f\n", ft_atof(ft_strdup("         \t\r9,8")));
	// printf("TEST 8: %f\n", ft_atof(ft_strdup("")));
	if (parser(argv[1], &rts) || init_mlx_pointers(&rts))
		cleaner(&rts);
	mlx_key_hook(rts.mlx, keyhook, &rts);
	// mlx_loop(rts.mlx);
	cleaner(&rts);
	return (0);
}
