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

static size_t 	ft_init_path_search(t_paths *paths)
{
	t_paths	*paths_ptr;
	t_road	*road_ptr;
	size_t 	ret;

	paths_ptr = paths;
	while (paths_ptr->path->dead_end)
		paths_ptr = paths_ptr->next;
	road_ptr = paths_ptr->path->road;
	ret = 0;
	while (road_ptr)
	{
		ret += 1;
		road_ptr = road_ptr->next;
	}
	return (ret);
}

t_path	*ft_get_shortest_path(t_paths *paths)
{
	t_paths	*paths_ptr;
	t_road	*road_ptr;
	size_t 	length;
	size_t 	tmp;
	t_path	*ret;

	paths_ptr = paths;
	length = ft_init_path_search(paths);
	ret = paths->path;
	while (paths_ptr)
	{
		road_ptr = paths_ptr->path->road;
		if (paths_ptr->path->dead_end == 0)
		{
			tmp = 0;
			while (road_ptr) {
				road_ptr = road_ptr->next;
				tmp += 1;
			}
			if (tmp <= length)
				ret = paths_ptr->path;
		}
		paths_ptr = paths_ptr->next;
	}
	return (ret);
}