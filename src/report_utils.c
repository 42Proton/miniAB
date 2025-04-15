/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:09:09 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/14 21:08:57 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	issue_report_msg(int issue)
{
	if (issue == ERR_INVALID_FLOAT)
		ft_dprintf(2, "Invalid float input\e[39m\n");
	else if (issue == ERR_INVALID_NFLOAT)
		ft_dprintf(2, "Invalid normal float input\e[39m\n");
	else if (issue == ERR_INVALID_TUPLE)
		ft_dprintf(2, "Invalid tuple input\e[39m\n");
	else if (issue == ERR_INVALID_RGB)
		ft_dprintf(2, "Invalid RGB input\e[39m\n");
	else if (issue == ERR_INVALID_COLOR)
		ft_dprintf(2, "Invalid color input\e[39m\n");
	else if (issue == ERR_OBJ_TYPE)
		ft_dprintf(2, "Unknown object\e[39m\n");
	else if (issue == ERR_INVALID_RATIO)
		ft_dprintf(2, "Invalid ratio input\e[39m\n");
	else if (issue == ERR_MISSING_TOK)
		ft_dprintf(2, "Missing token input\e[39m\n");
	else if (issue == ERR_EXTRA_TOK)
		ft_dprintf(2, "Extra token input\e[39m\n");
	else if (issue == ERR_INVALID_FOV)
		ft_dprintf(2, "Invalid fov input\e[39m\n");
	else if (issue == ERR_INVALID_COEFF)
		ft_dprintf(2, "Invalid coefficient input\e[39m\n");
}
