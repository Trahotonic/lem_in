/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_maze_part_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:25:52 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/05/14 15:25:53 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

static int	ft_init_maze(size_t *ants_q, char **line)
{
	get_next_line(0, line);
	while (ft_is_comment(*line))
	{
		ft_invalid_command(*line);
		ft_strdel(line);
		get_next_line(0, line);
	}
	if (!ft_strlen(*line))
	{
		free(*line);
		return (ft_return_error(0));
	}
	if (ft_invalid_ants(*line, ants_q))
		return (ft_return_error(0));
	get_next_line(0, line);
	while (ft_is_comment(*line))
	{
		ft_invalid_command(*line);
		ft_strdel(line);
		get_next_line(0, line);
	}
	return (1);
}

static int	ft_init_rooms(t_room **start, char *line)
{
	char *work;

	if (ft_is_room(line))
	{
		if (ft_invalid_coordinates(line))
			return (ft_return_error(&line));
		ft_printf("%s\n", line);
		*start = ft_new_room(line, 0);
		free(line);
		return (1);
	}
	else if ((ft_strequ(line, "##start") || ft_strequ(line, "##end")))
	{
		ft_printf("%s\n", line);
		ft_skip_comments(&work);
		if (!ft_is_room(work) || ft_invalid_coordinates(work))
		{
			free(work);
			return (ft_return_error(&line));
		}
		ft_start_or_end(line, work, start);
	}
	else
		return (ft_return_error(0));
	return (1);
}

static int	ft_end(char **transfer, char **line)
{
	*transfer = ft_strdup(*line);
	ft_invalid_command(*line);
	ft_strdel(line);
	return (1);
}

static int	ft_pick_one(char **line, t_room **start)
{
	if (ft_strequ(*line, "##start"))
	{
		if (!ft_case_start(start, line))
			return (0);
	}
	if (ft_strequ(*line, "##end"))
	{
		if (!ft_case_end(start, line))
			return (0);
	}
	return (1);
}

int			ft_get_maze_part_1(t_room **start, size_t *a, char **t, char *l)
{
	if (!ft_init_maze(a, &l) || !ft_init_rooms(start, l))
		return (0);
	while (get_next_line(0, &l) && ft_strlen(l) && !ft_is_link(l))
	{
		if (ft_is_room(l) && (ft_invalid_coordinates(l) ||
				ft_room_exists(*start, l) || ft_coordinates_exist(*start, l)))
			return (ft_return_error(&l));
		if (ft_is_room(l))
			ft_add_room(start, l, 0);
		if (ft_strequ(l, "##start") || ft_strequ(l, "##end"))
		{
			if (!ft_pick_one(&l, start))
				return (0);
			continue;
		}
		if (!ft_is_room(l) && !ft_strequ(l, "##start") &&
				!ft_strequ(l, "##end") && !ft_is_comment(l))
			return (ft_return_error(&l));
		ft_shmatochok(&l);
	}
	if ((!ft_is_link(l) && !ft_is_comment(l)) ||
			!ft_start_end_present(*start) || !ft_strlen(l))
		return (ft_return_error(&l));
	return (ft_end(t, &l));
}
