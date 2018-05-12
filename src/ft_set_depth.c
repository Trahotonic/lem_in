#include "../inc/lem-inc.h"

int		ft_things_to_do(t_room *room)
{
	while (room)
	{
		if (room->depth == -1)
			return (1);
		room = room->next;
	}
	return (0);
}

void	ft_set_depth(t_room *start)
{
	t_link	*link;
	t_room	*ptr;
	int 	depth;

	ft_start_location(start)->depth = 0;
	depth = 0;
	while (ft_things_to_do(start))
	{
		ptr = start;
		while (ptr)
		{
			if (ptr->depth == depth)
			{
				link = ptr->links;
				while (link)
				{
					if (link->station->depth == -1)
						link->station->depth = depth + 1;
                    link = link->next;
				}
			}
			ptr = ptr->next;
		}
		depth += 1;
	}
}
