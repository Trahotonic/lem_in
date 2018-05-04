#include "../inc/lem-inc.h"

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

int 		ft_is_room(char *line)
{
    char	**work;
    size_t	n;

    work = ft_strsplit(line, ' ');
    n = 0;
    while (work[n] != 0)
        n += 1;
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

