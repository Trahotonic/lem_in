#include "../inc/lem-inc.h"

void	ft_print_maze(t_room *start)
{
	t_room *ptr;
	t_link *ptr2;
	ptr = start;
	while (ptr != NULL)
	{
		ft_printf("%s", ptr->room_name);
		if (ptr->start == 1)
			ft_printf(" start");
		if (ptr->end == 1)
			ft_printf(" end");
		ft_printf("\n");
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
	ft_printf("____________\n");
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
			if (path->closed && !path->dead_end)
				ft_printf(" arrived");
			if (path->closed && path->dead_end)
				ft_printf(" dead end");
			ft_printf("\n\n");
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
