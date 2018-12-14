/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:52:33 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/05/23 12:52:34 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void	ft_print_maze(t_room *start)
{
	t_room *p;
	t_link *ptr2;

	p = start;
	while (p != NULL)
	{
		ft_printf("\033[0;36m%s\e[m [%ld] [%ld]", p->room_name, p->x, p->y);
		if (p->start == 1)
			ft_printf(" \033[1;34mstart\e[m");
		if (p->end == 1)
			ft_printf(" \033[1;34mend\e[m");
		p->depth == -1 ? ft_printf("\n\033[0;31mNot connected to start\e[m") :
		ft_printf("\nDepth = %ld", p->depth);
		ft_printf("\nLinks: ");
		ptr2 = p->links;
		while (ptr2 != NULL)
		{
			ft_printf("\033[0;33m%s\e[m", ptr2->station->room_name);
			if (ptr2->next)
				ft_printf(", ");
			ptr2 = ptr2->next;
		}
		ft_printf("\n\n");
		p = p->next;
	}
}

void	ft_print_path(t_link *path)
{
	ft_printf("\n\033[1;32mShortest path:\e[m ");
	while (path)
	{
		ft_printf("\033[1;32m%s\e[m", path->station->room_name);
		if (path->next)
			ft_printf("->");
		else
			ft_printf("\n\n");
		path = path->next;
	}
}

int		ft_return_error(char **line)
{
	if (line && *line)
		ft_strdel(line);
	ft_putendl_fd("\033[1;31mERROR\e[m", 1);
	return (0);
}

int		ft_invalid_command(char *line)
{
	if (ft_strlen(line) >= 3 && line[0] == '#' && line[1] == '#' &&
		line[2] != '#' && !ft_strequ(line, "##start") &&
		!ft_strequ(line, "##end"))
		return (1);
	ft_printf("%s\n", line);
	return (0);
}

int		ft_is_one_station(t_link *path)
{
	int length;

	length = 0;
	while (path)
	{
		length += 1;
		path = path->next;
	}
	if (length == 1)
		return (1);
	return (0);
}
