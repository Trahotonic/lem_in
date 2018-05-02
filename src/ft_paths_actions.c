#include "../inc/lem-inc.h"

t_room	*ft_find_last_room(t_path *path, t_room *start)
{
	t_road	*road_ptr;
	t_room	*room_ptr;

	road_ptr = path->road;
	room_ptr = start;
	while (road_ptr->next)
		road_ptr = road_ptr->next;
	while (ft_strcmp(road_ptr->name, room_ptr->room_name))
		room_ptr = room_ptr->next;
	return (room_ptr);
}

t_road		*ft_duplicate_road(t_road *road, t_link *link)
{
	t_road	*ret;
	t_road	*ptr;
	t_road	*ptr2;

	ret = (t_road*)malloc(sizeof(t_road));
	ret->name = ft_strdup(road->name);
	ret->next = NULL;
	ptr = road;
	ptr2 = ret;
	while (ptr->next->next)
	{
		ptr2->next = (t_road*)malloc(sizeof(t_road));
		ptr2->next->name = ft_strdup(ptr->next->name);
		ptr2->next->next = NULL;
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}
	ptr2->next = (t_road*)malloc(sizeof(t_road));
	ptr2->next->name = ft_strdup(link->name);
	return (ret);
}

void		ft_create_new_paths(t_paths *paths, t_link *links, t_path *p)
{
	t_paths	*paths_ptr;
	t_link	*link_ptr;
	t_path	*path;

	paths_ptr = paths;
	link_ptr = links;
	while (paths_ptr->next)
		paths_ptr = paths_ptr->next;
	while (link_ptr)
	{
		if (!ft_check_back(p, link_ptr->name))
		{
			path = (t_path *) malloc(sizeof(t_path));
			path->closed = 0;
			path->road = ft_duplicate_road(p->road, link_ptr);
			paths_ptr->next = (t_paths*) malloc(sizeof(t_paths));
			paths_ptr->next->next = NULL;
			paths_ptr->next->path = path;
			paths_ptr = paths_ptr->next;
		}
		link_ptr = link_ptr->next;
	}
}

void		ft_get_paths(t_paths *paths, t_room *start)
{
	t_link	*room_to_add;
    t_tools tools;

	tools.paths_tool = paths;
	while (tools.paths_tool->path->closed)
        tools.paths_tool = tools.paths_tool->next;
	tools.room_tool = ft_find_last_room(tools.paths_tool->path, start);
	tools.road_tool = tools.paths_tool->path->road;
	while (tools.road_tool->next)
		tools.road_tool = tools.road_tool->next;
	room_to_add = tools.room_tool->links;
	tools.link_tool = room_to_add;
	while (room_to_add)
	{
		tools.path_tool = tools.paths_tool->path;
		if (!ft_check_back(tools.paths_tool->path, room_to_add->name))
		{
            tools.road_tool->next = (t_road*)malloc(sizeof(t_road));
            tools.road_tool->next->next = NULL;
            tools.road_tool->next->name = room_to_add->name;
			ft_create_new_paths(paths, tools.link_tool, tools.path_tool);
			break ;
		}
		room_to_add = room_to_add->next;
	}
	ft_close_paths(paths, start);
}