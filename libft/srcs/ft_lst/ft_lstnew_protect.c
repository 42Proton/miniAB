/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_protect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:35:58 by amsaleh           #+#    #+#             */
/*   Updated: 2025/03/09 20:39:31 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew_protect(void *content, void (*del)(void *))
{
	t_list	*node;

	node = ft_calloc(1, sizeof(t_list));
	if (!node)
	{
		del(content);
		return (0);
	}
	node->content = content;
	return (node);
}
