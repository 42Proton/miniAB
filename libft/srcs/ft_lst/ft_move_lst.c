/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:11:59 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/30 00:04:32 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_move_lst(t_list *node, t_list **new_lst)
{
	node->next = 0;
	node->prev = 0;
	if (node->next)
		node->next->prev = 0;
	ft_lstadd_back(new_lst, node);
}
