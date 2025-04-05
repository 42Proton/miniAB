/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:58:07 by amsaleh           #+#    #+#             */
/*   Updated: 2025/04/05 13:12:46 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rays.h>

void	add_intersection_sorted(t_intersections *res, t_list *node)
{
	t_list		*tmp;
	t_intersect	*intersect;
	float		t;

	tmp = res->lst;
	t = ((t_intersect *)node->content)->t;
	while (tmp)
	{
		intersect = tmp->content;
		if (t < intersect->t)
		{
			node->next = tmp;
			node->prev = tmp->prev;
			tmp->prev = node;
			if (node->prev)
				node->prev->next = node;
			else
				res->lst = node;
			return ;
		}
		tmp = tmp->next;
	}
	ft_lstadd_back(&res->lst, node);
}

int	add_intersection(t_intersections *res, float t, t_object_entry *obj_entry)
{
	t_list		*node;
	t_intersect	*intersect;

	intersect = malloc(sizeof(t_intersect));
	if (!intersect)
		return (0);
	intersect->obj_type = obj_entry->type;
	intersect->obj = obj_entry->object;
	intersect->t = t;
	node = ft_lstnew(intersect);
	if (!node)
	{
		free(intersect);
		return (0);
	}
	add_intersection_sorted(res, node);
	res->count += 1;
	return (1);
}

void	clear_intersections(t_intersections *data)
{
	ft_lstclear(&data->lst, free);
	free(data);
}

t_intersect	*get_hit(t_intersections *data)
{
	t_list		*lst;
	t_intersect	*intersect;

	if (!data || !data->lst)
		return (0);
	lst = data->lst;
	while (lst)
	{
		intersect = lst->content;
		if (intersect->t >= 0)
			return (intersect);
		lst = lst->next;
	}
	return (0);
}

t_intersections	*world_intersect(t_list *solid_objs, t_ray *ray)
{
	t_intersections	*insects;
	t_object_entry	*entry;
	int				res;

	insects = ft_calloc(1, sizeof(t_intersections));
	if (!insects)
		return (0);
	while (solid_objs)
	{
		entry = solid_objs->content;
		if (entry->type == SPHERE)
			res = sphere_intersect(insects, entry, ray);
		if (entry->type == PLANE)
			res = plane_intersect(insects, entry, ray);
		if (!res)
		{
			clear_intersections(insects);
			return (0);
		}
		solid_objs = solid_objs->next;
	}
	return (insects);
}
