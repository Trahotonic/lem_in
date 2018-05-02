#include "../inc/lem-inc.h"

void	ft_print_maze(t_room *start)
{
	t_room *ptr;
	t_link *ptr2;
	ptr = start;
	while (ptr != NULL)
	{
		ft_printf("%s\n", ptr->room_name);
		ptr2 = ptr->links;
		while (ptr2 != NULL)
		{
			ft_printf("%s", ptr2->name);
			if (ptr2->next)
				ft_printf("-");
			else
				ft_printf("\n");
			ptr2 = ptr2->next;
		}
		ft_printf("\n");
		ptr = ptr->next;
	}
}

void	ft_print_path(t_path *path)
{
	t_road *ptr;
	ptr = path->road;
	while (ptr)
	{
		ft_printf("%s", ptr->name);
		if (ptr->next)
			ft_printf("-");
		else
		{
			if (path->closed)
				ft_printf(" closed");
			ft_printf("\n");
		}
		ptr = ptr->next;
	}
}

void	ft_print_paths(t_paths *paths)
{
	t_paths *ptr;

	ptr = paths;
	while (ptr)
	{
		ft_print_path(ptr->path);
		ptr = ptr->next;
	}
}