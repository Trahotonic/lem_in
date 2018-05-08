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

size_t ft_road_length(t_path *path)
{
	t_road	*ptr;
	size_t	ret;

	ptr = path->road;
	ret = 0;
	while (ptr)
	{
		ret += 1;
		ptr = ptr->next;
	}
	return (ret);
}

t_path	*ft_get_shortest_path(t_paths *paths)
{
	t_paths	*paths_ptr;
	size_t 	length;
	size_t 	tmp;
	t_path	*ret;

	paths_ptr = paths;
	length = ft_init_path_search(paths);
	ret = paths->path;
	while (paths_ptr)
	{
		if (paths_ptr->path->dead_end == 0)
		{
			tmp = ft_road_length(paths_ptr->path);
			if (tmp <= length)
			{
				length = tmp;
				ret = paths_ptr->path;
			}
		}
		paths_ptr = paths_ptr->next;
	}
	return (ret);
}

size_t ft_get_paths_q(t_paths *paths)
{
	size_t n;

	n = 0;
	while (paths)
	{
		n += 1;
		paths = paths->next;
	}
	return (n);
}

void	ft_sort_paths(t_paths *ret)
{
	size_t 	q;
	size_t 	n;
	t_paths	*ptr;
	t_path	*buff;

	q = ft_get_paths_q(ret);
	n = 0;
	while (n < q)
	{
		ptr = ret;
		while (ptr->next)
		{
			if (ft_road_length(ptr->path) > ft_road_length(ptr->next->path))
			{
				buff = ptr->path;
				ptr->path = ptr->next->path;
				ptr->next->path = buff;
			}
			ptr = ptr->next;
		}
		n += 1;
	}
}

t_paths	*ft_other_short_paths(t_paths *paths, t_path *shortest)
{
	t_paths	*ret;
	t_paths	*ptr;
	t_paths	*anchor;
	size_t	n;
	size_t	m;


	m = ft_road_length(shortest);
	ret = (t_paths*)malloc(sizeof(t_paths));
	ret->path = shortest;
	ret->next = NULL;
	ptr = paths;
	anchor = ret;
	while (ptr)
	{
		if (ptr->path->dead_end == 0)
		{
			n = ft_road_length(ptr->path);
			if (n <= m + 1)
			{
				ret->next = (t_paths*)malloc(sizeof(t_paths));
				ret->next->path = ptr->path;
				ret->next->next = NULL;
				ret = ret->next;
			}
		}
		ptr = ptr->next;
	}
	ft_sort_paths(anchor);
	return (anchor);
}
