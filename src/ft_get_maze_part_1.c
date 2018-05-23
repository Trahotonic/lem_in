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

#include "../inc/lem-inc.h"

static int	ft_init_maze(size_t *ants_q, char **line)
{
	get_next_line(0, line);
	while (ft_is_comment(*line))
	{
		ft_printf("%s\n", *line);
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
		ft_printf("%s\n", *line);
		ft_strdel(line);
		get_next_line(0, line);
	}
	return (1);
}

static int  ft_init_rooms(t_room **start, char *line)
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
		ft_skip_comments(&work);
		if (!ft_is_room(work))
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

static int ft_end(char **transfer, char **line)
{
	*transfer = ft_strdup(*line);
	ft_printf("%s\n", *line);
	ft_strdel(line);
	return (1);
}

static int ft_pick_one(char **line, t_room **start)
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

int		ft_get_maze_part_1(t_room **start, size_t *ants_q, char **transfer)
{
	char *line;

	if (!ft_init_maze(ants_q, &line) || !ft_init_rooms(start, line))
		return (0);
	while (get_next_line(0, &line) && ft_strlen(line) && !ft_is_link(line))
	{
		if (ft_is_room(line) && (ft_invalid_coordinates(line) ||
				ft_room_exists(*start, line) || ft_coordinates_exist(*start, line)))
			return (ft_return_error(&line));
		if (ft_is_room(line))
			ft_add_room(start, line, 0);
		if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
		{
			if (!ft_pick_one(&line, start))
				return (0);
			continue;
		}
		if (!ft_is_room(line) && !ft_strequ(line, "##start") &&
				!ft_strequ(line, "##end") && !ft_is_comment(line))
			return (ft_return_error(&line));
		ft_shmatochok(&line);
	}
	if ((!ft_is_link(line) && !ft_is_comment(line)) ||
			!ft_start_end_present(*start) || !ft_strlen(line))
		return (ft_return_error(&line));
	return (ft_end(transfer, &line));
}
