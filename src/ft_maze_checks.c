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
    ft_printf("%s\n", line);
    free(line);
    if (*ants_q == 0 || *ants_q > 2147483647)
		return (1);
    return (0);
}

int 		ft_is_all_digit(char *line)
{
    size_t	n;

    n = 0;
    while (line[n] != '\0')
	{
		if (!ft_isdigit(line[n]))
		{
			return (0);
		}
		n += 1;
	}
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
