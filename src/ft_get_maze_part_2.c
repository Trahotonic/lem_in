/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_maze_part_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:49:19 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/05/23 12:49:20 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

static int	ft_ret_er(char **line)
{
	ft_strdel(line);
	return (0);
}

static int	ft_ret_dump(char **dump)
{
	ft_free_dump(dump);
	return (0);
}

int			ft_both_rooms_exist(char *line, t_room *start)
{
	char	**dump;
	t_room	*ptr;
	int		ret;

	dump = ft_strsplit(line, '-');
	ptr = start;
	ret = 0;
	while (ptr)
	{
		if (ft_strequ(ptr->room_name, dump[0]))
			ret = 1;
		ptr = ptr->next;
	}
	if (!ret || ft_strequ(dump[0], dump[1]))
		return (ft_ret_dump(dump));
	ret = 0;
	ptr = start;
	while (ptr)
	{
		if (ft_strequ(ptr->room_name, dump[1]))
			ret = 1;
		ptr = ptr->next;
	}
	ft_free_dump(dump);
	return (ret);
}

static int	ft_add(char *line, t_room **start)
{
	char **dump;

	dump = ft_strsplit(line, '-');
	if (ft_link_exists(*start, dump[0], dump[1]))
	{
		ft_free_dump(dump);
		return (0);
	}
	ft_add_link(dump[0], dump[1], start);
	ft_add_link(dump[1], dump[0], start);
	ft_free_dump(dump);
	return (1);
}

int			ft_get_maze_part_2(t_room **start, char *transfer)
{
	char *line;

	if (!ft_both_rooms_exist(transfer, *start))
		return (ft_ret_er(&transfer));
	ft_add(transfer, start);
	while (get_next_line(0, &line))
	{
		if (!ft_is_link(line) && !ft_is_comment(line))
			return (ft_ret_er(&line));
		if (ft_is_comment(line))
		{
			ft_invalid_command(line);
			ft_strdel(&line);
			continue;
		}
		if (!ft_both_rooms_exist(line, *start))
			return (ft_ret_er(&line));
		if (!ft_add(line, start))
			return (ft_ret_er(&line));
		ft_invalid_command(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}
