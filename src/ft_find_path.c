/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:52:19 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/05/23 12:52:19 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int		ft_finish_has_connection_to_start(t_link *links)
{
	while (links)
	{
		if (links->station->depth != -1)
			return (1);
		links = links->next;
	}
	return (0);
}

t_room	*ft_get_best_room(t_link *links)
{
	t_room *ret;

	ret = links->station;
	while (links)
	{
		if (links->station->depth != -1 && links->station->depth < ret->depth)
			ret = links->station;
		links = links->next;
	}
	return (ret);
}

t_link	*ft_find_path(t_room *rooms)
{
	t_link	*links;
	t_room	*room;
	t_link	*ret;
	t_link	*new;

	links = ft_destination(rooms)->links;
	if (!ft_finish_has_connection_to_start(links))
		return (NULL);
	room = ft_get_best_room(links);
	ret = (t_link*)malloc(sizeof(t_link));
	ret->station = ft_destination(rooms);
	ret->next = NULL;
	new = (t_link*)malloc(sizeof(t_link));
	new->station = room;
	new->next = ret;
	ret = new;
	while (ret->station->depth > 0)
	{
		new = (t_link*)malloc(sizeof(t_link));
		new->station = ft_get_best_room(ret->station->links);
		new->next = ret;
		ret = new;
	}
	return (ret);
}
