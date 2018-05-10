#include "../inc/lem-inc.h"

t_room	*ft_find_last_room(t_link *path)
{
	t_link	*ptr;

	ptr = path;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr->station);
}
//
t_link		*ft_duplicate_path(t_link *path, t_room *new_station)
{
//	t_road	*ret;
//	t_road	*ptr;
//	t_road	*ptr2;
//
//	ret = (t_road*)malloc(sizeof(t_road));
//	ret->name = ft_strdup(road->name);
//	ret->next = NULL;
//	ptr = road;
//	ptr2 = ret;
//	while (ptr->next->next)
//	{
//		ptr2->next = (t_road*)malloc(sizeof(t_road));
//		ptr2->next->name = ft_strdup(ptr->next->name);
//		ptr2->next->next = NULL;
//		ptr = ptr->next;
//		ptr2 = ptr2->next;
//	}
//	ptr2->next = (t_road*)malloc(sizeof(t_road));
//	ptr2->next->name = ft_strdup(link->name);
//	ptr2->next->next = NULL;
//	return (ret);
    t_link  *ret;
    t_link  *ptr;

    ret = (t_link*)malloc(sizeof(t_link));
    ret->station = path->station;
    ret->next = NULL;
    ptr = ret;
    while (path->next->next)
    {
        ptr->next = (t_link*)malloc(sizeof(t_link));
        ptr->next->station = path->next->station;
        ptr->next->next = NULL;
        ptr = ptr->next;
        path = path->next;
    }
    ptr->next = (t_link*)malloc(sizeof(t_link));
    ptr->next->station = new_station;
    ptr->next->next = NULL;
    return (ret);
}

void		ft_create_new_paths(t_paths *paths, t_link *links, t_link *p)
{
//	t_paths	*paths_ptr;
//	t_link	*link_ptr;
//	t_path	*path;
//
//	paths_ptr = paths;
//	link_ptr = links;
//	while (paths_ptr->next)
//		paths_ptr = paths_ptr->next;
//	while (link_ptr)
//	{
//		if (!ft_check_back(p, link_ptr->name))
//		{
//			path = (t_path*)malloc(sizeof(t_path));
//			path->closed = 0;
//			path->dead_end = 0;
//			path->road = ft_duplicate_road(p->road, link_ptr);
//			paths_ptr->next = (t_paths*)malloc(sizeof(t_paths));
//			paths_ptr->next->next = NULL;
//			paths_ptr->next->path = path;
//			paths_ptr = paths_ptr->next;
//		}
//		link_ptr = link_ptr->next;
//	}
    t_paths *paths_ptr;

    paths_ptr = paths;
    while (paths_ptr->next)
        paths_ptr = paths_ptr->next;
    while (links)
    {
        if (!ft_check_back(p, links->station))
        {
            paths_ptr->next = (t_paths*)malloc(sizeof(t_paths));
            paths_ptr->next->path = ft_duplicate_path(p, links->station);
            paths_ptr->next->closed = 0;
            paths_ptr->next->dead_end = 0;
            paths_ptr->next->next = NULL;
            paths_ptr = paths_ptr->next;
        }
        links = links->next;
    }
}

void		ft_get_paths(t_paths *paths, t_room *start)
{
	t_paths	*paths_ptr;
    t_link	*link_ptr;
    t_link	*path;
    t_link	*path_end;
    t_link  *link_anchor;

    paths_ptr = paths;
    while (paths_ptr->closed)
        paths_ptr = paths_ptr->next;
    link_ptr = ft_find_last_room(paths_ptr->path)->links;
    link_anchor = link_ptr;
    path = paths_ptr->path;
    path_end = path;
    while (path_end->next)
        path_end = path_end->next;
    while (link_ptr)
    {
        if (!ft_check_back(path, link_ptr->station))
        {
            path_end->next = (t_link*)malloc(sizeof(t_link));
            path_end->next->next = NULL;
            path_end->next->station = link_ptr->station;
            ft_create_new_paths(paths, link_anchor, path);
            break ;
        }
        link_ptr = link_ptr->next;
    }
    ft_close_paths(paths, start);
    //	t_link	*room_to_add;
//    t_tools tools;
//
//	tools.paths_tool = paths;
//	while (tools.paths_tool->path->closed)
//        tools.paths_tool = tools.paths_tool->next;
//	tools.room_tool = ft_find_last_room(tools.paths_tool->path, start);
//	tools.road_tool = tools.paths_tool->path->road;
//	while (tools.road_tool->next)
//		tools.road_tool = tools.road_tool->next;
//	room_to_add = tools.room_tool->links;
//	tools.link_tool = room_to_add;
//	while (room_to_add)
//	{
//		tools.path_tool = tools.paths_tool->path;
//		if (!ft_check_back(tools.paths_tool->path, room_to_add->name))
//		{
//            tools.road_tool->next = (t_road*)malloc(sizeof(t_road));
//            tools.road_tool->next->next = NULL;
//            tools.road_tool->next->name = room_to_add->name;
//			ft_create_new_paths(paths, tools.link_tool, tools.path_tool);
//			break ;
//		}
//		room_to_add = room_to_add->next;
//	}
//	ft_close_paths(paths, start);
}