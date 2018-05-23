#include "../inc/lem-inc.h"

void    ft_skip_comments(char **work)
{
	get_next_line(0, work);
	while (ft_is_comment(*work))
	{
		ft_printf("%s\n", *work);
		ft_strdel(work);
		get_next_line(0, work);
	}
}

void    ft_start_or_end(char *line, char *work, t_room **start)
{
	if (ft_strequ(line, "##start"))
		*start = ft_new_room(work, 1);
	if (ft_strequ(line, "##end"))
		*start = ft_new_room(work, 2);
	ft_printf("%s\n", line);
	ft_printf("%s\n", work);
	free(line);
	free(work);
}

int		ft_case_start(t_room **start, char **line)
{
	ft_printf("we here\n");
	ft_printf("%s\n", *line);
	if (!ft_start_exists(*start))
	{
		ft_strdel(line);
		get_next_line(0, line);
		while (ft_is_comment(*line))
		{
			ft_printf("%s\n", *line);
			ft_strdel(line);
			get_next_line(0, line);
		}
		if (ft_is_room(*line))
		{
			ft_printf("%s\n", *line);
			ft_add_room(start, *line, 1);
			ft_strdel(line);
		}
		else
			return (ft_return_error(line));
	}
	else
		return (ft_return_error(line));
	return (1);
}

int		ft_case_end(t_room **start, char **line)
{
	ft_printf("%s\n", *line);
	if (!ft_end_exists(*start))
	{
		ft_strdel(line);
		get_next_line(0, line);
		while (ft_is_comment(*line))
		{
			ft_printf("%s\n", *line);
			ft_strdel(line);
			get_next_line(0, line);
		}
		if (ft_is_room(*line))
		{
			ft_printf("%s\n", *line);
			ft_add_room(start, *line, 2);
			ft_strdel(line);
		}
		else
			return (ft_return_error(line));
	}
	else
		return (ft_return_error(line));
	return (1);
}

void    ft_shmatochok(char **line)
{
	ft_printf("%s\n", *line);
	ft_strdel(line);
}