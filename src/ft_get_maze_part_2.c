#include "../inc/lem-inc.h"

void    ft_add(char *line, t_room **start)
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

    ft_add(transfer, start);
    while (get_next_line(0, &line))
    {
        if (!ft_is_link(line) && !ft_is_comment(line))
        {
            ft_strdel(&line);
            ft_putendl_fd("Error", 2);
            return (0);
        }
        if (ft_is_comment(line))
        {
            ft_strdel(&line);
            continue;
        }
        ft_add(line, start);
        ft_strdel(&line);
    }
    ft_strdel(&line);
    return (1);
}