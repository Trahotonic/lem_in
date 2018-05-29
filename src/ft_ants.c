/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:52:57 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/05/23 12:52:58 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

size_t	ft_get_min(t_link *path)
{
	size_t ret;

	while (path->station->ant_nbr == 0)
		path = path->next;
	ret = path->station->ant_nbr;
	while (path)
	{
		if (path->station->ant_nbr < ret && path->station->ant_nbr != 0)
			ret = path->station->ant_nbr;
		path = path->next;
	}
	return (ret);
}

size_t	ft_get_max(t_link *path)
{
	size_t ret;

	ret = path->station->ant_nbr;
	while (path)
	{
		if (path->station->ant_nbr > ret)
			ret = path->station->ant_nbr;
		path = path->next;
	}
	return (ret);
}

void	ft_init(t_link *path, size_t ants_q)
{
	while (path)
	{
		if (path->station->ant_nbr != 0)
			path->station->ant_nbr += 1;
		if (path->station->ant_nbr > ants_q)
			path->station->ant_nbr = 0;
		path = path->next;
	}
}

void	ft_increase(t_link *path, size_t ants_q)
{
	t_link	*ptr;
	t_link	*anchor;
	size_t	checker;
	size_t	min;
	size_t	max;

	ptr = path;
	anchor = path;
	min = ft_get_min(anchor);
	ft_init(path, ants_q);
	while (ptr->station->ant_nbr != min + 1)
		ptr = ptr->next;
	if (ptr->next && ptr->next->station->ant_nbr == 0)
		ptr->next->station->ant_nbr = 1;
	min = ft_get_min(anchor);
	max = ft_get_max(anchor);
	checker = min;
	while (checker <= max)
	{
		ptr = anchor;
		while (ptr->station->ant_nbr != checker)
			ptr = ptr->next;
		ft_printf("L%zu-%s ", ptr->station->ant_nbr, ptr->station->room_name);
		checker += 1;
	}
}

int		ft_move_ants(size_t ants_q, t_link *path, t_room *rooms)
{
	path = path->next;
	path->station->ant_nbr = 1;
	ft_printf("\n");
	if (ants_q > 1)
	{
		ft_printf("L1-%s\n", path->station->room_name);
		while (ft_destination(rooms)->ant_nbr != ants_q)
		{
			ft_increase(path, ants_q);
			ft_printf("\n");
		}
	}
	else
		while (path)
		{
			ft_printf("L1-%s\n", path->station->room_name);
			path = path->next;
		}
	return (0);
}
