#include "../inc/lem-inc.h"

int 		ft_start_exists(t_room *start)
{
	t_room	*ptr;

	ptr = start;
	while (ptr)
	{
		if (ptr->start == 1)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int 		ft_end_exists(t_room *start)
{
	t_room	*ptr;

	ptr = start;
	while (ptr)
	{
		if (ptr->end == 1)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void		ft_free_dump(char **dump)
{
	size_t n;

	n = 0;
	while (dump[n] != 0)
	{
		free(dump[n]);
		n += 1;
	}
	free(dump);
}

int 		ft_invalid_ants(char *line, size_t *ants_q)
{
	size_t	n;
	char 	*work;

	n = 0;
	work = ft_strtrim(line);
	while (work[n] != '\0')
		if (!ft_isdigit(work[n++]))
		{
			free(work);
			free(line);
			return (1);
		}
	free(work);
	*ants_q = (size_t)ft_atoi(line);
	free(line);
	return (0);
}

int 		ft_is_all_digit(char *line)
{
	size_t	n;
	char 	*work;

	n = 0;
	work = ft_strtrim(line);
	while (work[n] != '\0')
		if (!ft_isdigit(work[n++]))
		{
			free(work);
			return (0);
		}
	free(work);
	return (1);
}

int 		ft_is_comment(char *line)
{
	char 	*work;

	work = ft_strtrim(line);
	if (work[0] == '#' && !ft_strequ("##start", work) &&
		!ft_strequ("##end", work))
	{
		free(work);
		return (1);
	}
	free(work);
	return (0);
}

int 		ft_is_room(char *line)
{
	char	**work;
	size_t	n;

	work = ft_strsplit(line, ' ');
	n = 0;
	while (work[n] != 0)
	{
		if (n != 0 && !ft_is_all_digit(work[n]))
		{
			ft_free_dump(work);
			return (0);
		}
		n += 1;
	}
	ft_free_dump(work);
	if (n != 3)
		return (0);
	return (1);
}

int 		ft_is_link(char *line)
{
	char	**work;
	size_t	n;

	work = ft_strsplit(line, '-');
	n = 0;
	while (work[n] != 0)
		n += 1;
	ft_free_dump(work);
	if (n != 2)
		return (0);
	return (1);
}


int 		ft_init_maze(size_t *ants_q, char **line)
{
	get_next_line(0, line);
	if (!ft_strlen(*line))
	{
		free(*line);
		ft_putendl_fd("Error", 2);
		return (0);
	}
	if (ft_invalid_ants(*line, ants_q))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	get_next_line(0, line);
	while (ft_is_comment(*line))
	{
		ft_strdel(line);
		get_next_line(0, line);
	}
	return (1);
}

int		ft_init_rooms(t_room **start, char *line)
{
	char *work;

	if (ft_is_room(line))
	{
		*start = ft_new_room(line, 0);
		free(line);
		return (1);
	}
	if ((ft_strequ(line, "##start") || ft_strequ(line, "##end")))
	{
		get_next_line(0, &work);
		if (!ft_is_room(work))
		{
			free(work);
			free(line);
			return (0);
		}
		if (ft_strequ(line, "##start"))
			*start = ft_new_room(work, 1);
		if (ft_strequ(line, "##end"))
			*start = ft_new_room(work, 2);
		free(line);
		free(work);
	}
	return (1);
}

int		ft_get_maze(t_room **start, size_t *ants_q)
{
	char *line;

	if (!ft_init_maze(ants_q, &line))
		return (0);
	if (!ft_init_rooms(start, line))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	get_next_line(0, &line);
	while (!ft_is_link(line))
	{
		if (ft_is_room(line))
			ft_add_room(start, line, 0);
		if (ft_strequ(line, "##start"))
		{
			if (!ft_start_exists(*start))
			{
				ft_strdel(&line);
				get_next_line(0, &line);
				if (ft_is_room(line))
				{
					ft_add_room(start, line, 1);
					ft_strdel(&line);
				}
				else
				{
					ft_strdel(&line);
					ft_putendl_fd("Error", 2);
					return (0);
				}
			}
			else
			{
				ft_strdel(&line);
				ft_putendl_fd("Error", 2);
				return (0);
			}
		}
		if (ft_strequ(line, "##end"))
		{
			if (!ft_end_exists(*start))
			{
				ft_strdel(&line);
				get_next_line(0, &line);
				if (ft_is_room(line))
				{
					ft_add_room(start, line, 2);
					ft_strdel(&line);
				}
				else
				{
					ft_strdel(&line);
					ft_putendl_fd("Error", 2);
					return (0);
				}
			}
			else
			{
				ft_strdel(&line);
				ft_putendl_fd("Error", 2);
				return (0);
			}
		}
		ft_strdel(&line);
		get_next_line(0, &line);
	}
	ft_strdel(&line);
	return (1);
}