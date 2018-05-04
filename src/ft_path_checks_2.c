#include "../inc/lem-inc.h"

int 	ft_open_paths(t_paths *paths)
{
	t_paths *ptr;

	ptr = paths;
	while (ptr)
	{
		if (ptr->path->closed == 0)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int 	ft_successful_roads(t_paths *paths)
{
	t_paths *ptr;

	ptr = paths;
	while (ptr)
	{
		if (!ptr->path->dead_end)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

//t_path	*ft_get_shortest_path(t_paths *paths)
//{
//	t_paths	*paths_ptr;
//	t_road	*road_ptr;
//	size_t 	length;
//	size_t 	tmp;
//
//	paths_ptr = paths;
//	while (paths_ptr)
//	{
//		road_ptr = paths_ptr->path->road;
//		paths_ptr = paths_ptr->next;
//	}
//}