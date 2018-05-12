#include "../inc/lem-inc.h"

int 		ft_both_rooms_exist(char *line, t_room *start)
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
	if (!ret)
	{
		ft_free_dump(dump);
		return (0);
	}
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

void		ft_add(char *line, t_room **start)
{
    char **dump;

    dump = ft_strsplit(line, '-');
    ft_add_link(dump[0], dump[1], start);
    ft_add_link(dump[1], dump[0], start);
    ft_free_dump(dump);
}

int     ft_get_maze_part_2(t_room **start, char *transfer)
{
    char *line;

	if (!ft_both_rooms_exist(transfer, *start))
	{
		ft_strdel(&line);
		return (0);
	}
    ft_add(transfer, start);
    while (get_next_line(0, &line))
    {
		if (!ft_is_link(line) && !ft_is_comment(line))
        {
            ft_strdel(&line);
            return (0);
        }
        if (ft_is_comment(line))
        {
			ft_printf("%s\n", line);
            ft_strdel(&line);
            continue;
        }
		if (!ft_both_rooms_exist(line, *start))
		{
			ft_strdel(&line);
			return (0);
		}
        ft_add(line, start);
		ft_printf("%s\n", line);
        ft_strdel(&line);
    }
    ft_strdel(&line);
    return (1);
}