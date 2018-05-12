#include "../inc/lem-inc.h"

int		ft_things_to_do(t_room *room, int depth)
{
    t_link *links;

	while (room)
	{
		if (room->depth == depth)
        {
            links = room->links;
            while (links)
            {
                if (links->station->depth == -1)
                    return (1);
                links = links->next;
            }
        }
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
	while (ft_things_to_do(start, depth))
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
