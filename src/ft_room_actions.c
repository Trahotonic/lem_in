/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:23:47 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/05/14 15:23:49 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem-inc.h"

t_room	*ft_new_room(char *name, int n)
{
	t_room	*ret;
	char	**dump;

	dump = ft_strsplit(name, ' ');
	ret = (t_room*)malloc(sizeof(t_room));
	ret->room_name = ft_strdup(dump[0]);
	ret->x = ft_atoi(dump[1]);
	ret->y = ft_atoi(dump[2]);
	ret->ant_nbr = 0;
	ret->links = NULL;
	ret->next = NULL;
	ret->start = 0;
	ret->depth = -1;
	if (n == 1)
		ret->start = 1;
	ret->end = 0;
	if (n == 2)
		ret->end = 1;
	ft_free_dump(dump);
	return (ret);
}

void	ft_add_room(t_room **rooms, char *name, int n)
{
	t_room	*add;
	t_room	*ptr;

	add = ft_new_room(name, n);
	ptr = *rooms;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = add;
}

void	ft_add_link(char *from, char *to, t_room **rooms)
{
	t_room	*ptr_to;
	t_room	*ptr_from;
	t_link	*l_new;

	ptr_to = *rooms;
	while (!ft_strequ(ptr_to->room_name, to))
		ptr_to = ptr_to->next;
	l_new = (t_link*)malloc(sizeof(t_link));
	l_new->station = ptr_to;
	ptr_from = *rooms;
	while (!ft_strequ(ptr_from->room_name, from))
		ptr_from = ptr_from->next;
	if (ptr_from->links)
	{
		l_new->next = ptr_from->links;
		ptr_from->links = l_new;
	}
	else
	{
		l_new->next = NULL;
		ptr_from->links = l_new;
	}
}
