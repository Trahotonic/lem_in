#include "../inc/lem-inc.h"

int 		ft_invalid_coordinates(char *line)
{
	char **dump;

	dump = ft_strsplit(line , ' ');
	if (dump[0][0] == 'L')
	{
		ft_free_dump(dump);
		return (1);
	}
	if (!ft_is_all_digit(dump[1]) || !ft_is_all_digit(dump[2]))
		return (1);
	ft_free_dump(dump);
	return (0);
}

int 		ft_room_exists(t_room *start, char *line)
{
	t_room	*ptr;
	char 	**dump;

	ptr = start;
	dump = ft_strsplit(line, ' ');
	while (ptr)
	{
		if (ft_strequ(ptr->room_name, dump[0]))
		{
			ft_free_dump(dump);
			return (1);
		}
		ptr = ptr->next;
	}
	ft_free_dump(dump);
	return (0);
}

int 		ft_coordinates_exist(t_room *start, char *line)
{
	t_room	*ptr;
	char 	**dump;

	ptr = start;
	dump = ft_strsplit(line, ' ');
	while (ptr)
	{
		if (ptr->x == ft_atoi(dump[1]) && ptr->y == ft_atoi(dump[2]))
		{
			ft_free_dump(dump);
			return (1);
		}
		ptr = ptr->next;
	}
	ft_free_dump(dump);
	return (0);
}