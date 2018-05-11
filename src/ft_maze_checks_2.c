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

	if (ft_is_room(line))
		return (0);
    work = ft_strsplit(line, '-');
    n = 0;
    while (work[n] != 0)
        n += 1;
    ft_free_dump(work);
    if (n != 2)
        return (0);
    return (1);
}

int 		ft_start_end_present(t_room *start)
{
	t_room	*ptr;
	int 	ret;

	ptr = start;
	ret = 0;
	while (ptr)
	{
		if (ptr->start == 1)
			ret += 1;
		if (ptr->end == 1)
			ret += 1;
		ptr = ptr->next;
	}
	if (ret != 2)
		return (0);
	return (1);
}
