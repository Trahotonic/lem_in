#include "../inc/lem-inc.h"

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
	char **work;
	size_t n;

	work = ft_strsplit(line, ' ');
	n = 0;
	while (work[n] != 0)
	{
		if (!ft_is_all_digit(work[n]))
		{
			free(work);
			return (0);
		}
		n += 1;
	}
	free(work);
	if (n != 3)
		return (0);
	return (1);
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

int		ft_rooms_block(t_room **start, char *line)
{
	char *work;

	if (ft_is_room(line))
	{
		*start = ft_new_room(line);
		free(line);
	}
	if (ft_strequ(line, "##start"))
	{
		free(line);
		get_next_line(0, &work);
		if (ft_is_room(work))
			ft_add_room(start, line);
	}
	return (1);
}

void		ft_get_maze(t_room **start, size_t *ants_q)
{
	char *line;

	get_next_line(0, &line);
	if (ft_invalid_ants(line, ants_q))
		return (ft_putendl_fd("Error", 2));
	get_next_line(0, &line);
	while (ft_is_comment(line))
	{
		ft_strdel(&line);
		get_next_line(0, &line);
	}
	if (!ft_is_room(line) && !ft_strequ(line, "##start") &&
			!ft_strequ(line, "##end"))
	{
		ft_strdel(&line);
		return (ft_putendl_fd("Error", 2));
	}
	ft_rooms_block(start, line);
}