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

#include "../inc/lem-inc.h"

void	ft_print_maze(t_room *start)
{
	t_room *ptr;
	t_link *ptr2;

	ptr = start;
	while (ptr != NULL)
	{
		ft_printf("%s [%ld] [%ld]", ptr->room_name, ptr->x, ptr->y);
		if (ptr->start == 1)
			ft_printf(" start");
		if (ptr->end == 1)
			ft_printf(" end");
		ft_printf(" %ld\n", ptr->depth);
		ptr2 = ptr->links;
		while (ptr2 != NULL)
		{
			ft_printf("%s", ptr2->station->room_name);
			ptr2->next ? ft_printf("-") : ft_printf("\n");
			ptr2 = ptr2->next;
		}
		ft_printf("\n");
		ptr = ptr->next;
	}
}

void	ft_print_path(t_link *path)
{
	while (path)
	{
		ft_printf("%s", path->station->room_name);
		if (path->next)
			ft_printf("->");
		else
			ft_printf("\n");
		path = path->next;
	}
}

int		ft_return_error(char **line)
{
	if (line && *line)
		ft_strdel(line);
	ft_putendl_fd("Error", 1);
	return (0);
}

int		ft_invalid_command(char *line)
{
	if (ft_strlen(line) >= 3 && line[0] == '#' && line[1] == '#' &&
		line[2] != '#' && !ft_strequ(line, "##start") &&
		!ft_strequ(line, "##end"))
		return (1);
	return (0);
}