#include "../inc/lem-inc.h"

t_paths	*ft_init_path(t_room *start)
{
	t_paths *paths;
	t_paths *ptr;
	t_link	*link;

	paths = (t_paths*)malloc(sizeof(t_paths));
	paths->next = NULL;
	paths->path = (t_path*)malloc(sizeof(t_path));
	paths->path->closed = 0;
	paths->path->dead_end = 0;
	paths->path->road = (t_road*)malloc(sizeof(t_road));
	paths->path->road->name = ft_strdup("start");
	paths->path->road->next = (t_road*)malloc(sizeof(t_road));
	paths->path->road->next->next = NULL;
	paths->path->road->next->name = start->links->name;
	ptr = paths;
	link = start->links->next;
	while (link)
	{
		ptr->next = (t_paths*)malloc(sizeof(t_paths));
		ptr->next->next = NULL;
		ptr->next->path = (t_path*)malloc(sizeof(t_path));
		ptr->next->path->closed = 0;
		ptr->next->path->dead_end = 0;
		ptr->next->path->road = (t_road*)malloc(sizeof(t_road));
		ptr->next->path->road->name = ft_strdup("start");
		ptr->next->path->road->next = (t_road*)malloc(sizeof(t_road));
		ptr->next->path->road->next->next = NULL;
		ptr->next->path->road->next->name = link->name;
		ptr = ptr->next;
		link = link->next;
	}
	return (paths);
}

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

//int		ft_check_back(t_path *path, char const *room_name)
//{
//	t_road	*ptr;
//
//	ptr = path->road;
//	while (ptr)
//	{
//		if (!ft_strcmp(ptr->name, room_name))
//			return (1);
//		ptr = ptr->next;
//	}
//	return (0);
//}

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

//char 		*ft_get_last_road_station(t_road *road)
//{
//	t_road	*ptr;
//
//	ptr = road;
//	while (ptr->next)
//		ptr = ptr->next;
//	return (ptr->name);
//}
//
//int 		ft_dead_end(t_path *path, t_room *start)
//{
//	t_link *last_room_links;
//
//	last_room_links = ft_find_last_room(path, start)->links;
//	while (last_room_links)
//	{
//		if (!ft_check_back(path, last_room_links->name))
//			return (0);
//		last_room_links = last_room_links->next;
//	}
//	return (1);
//}
//
//void		ft_close_paths(t_paths *paths, t_room *start)
//{
//	t_paths *ptr;
//
//	ptr = paths;
//	while (ptr)
//	{
//		if (!ft_strcmp(ft_get_last_road_station(ptr->path->road), "finish"))
//			ptr->path->closed = 1;
//		if (ft_dead_end(ptr->path, start) &&
//				ft_strcmp(ft_get_last_road_station(ptr->path->road), "finish"))
//		{
//			ptr->path->closed = 1;
//			ptr->path->dead_end = 1;
//		}
//		ptr = ptr->next;
//	}
//}

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

//int 		ft_open_paths(t_paths *paths)
//{
//	t_paths *ptr;
//
//	ptr = paths;
//	while (ptr)
//	{
//		if (ptr->path->closed == 0)
//			return (1);
//		ptr = ptr->next;
//	}
//	return (0);
//}

void		ft_get_paths(t_paths *paths, t_room *start)
{
	t_paths	*ptr;
	t_room	*last_room_in_path;
	t_road	*road_end;
	t_link	*room_to_add;
	t_link	*anchor;
	t_path	*backup;

	ptr = paths;
	while (ptr->path->closed)
		ptr = ptr->next;
	last_room_in_path = ft_find_last_room(ptr->path, start);
	road_end = ptr->path->road;
	while (road_end->next)
		road_end = road_end->next;
	room_to_add = last_room_in_path->links;
	anchor = room_to_add;
	while (room_to_add)
	{
		backup = ptr->path;
		if (!ft_check_back(ptr->path, room_to_add->name))
		{
			road_end->next = (t_road*)malloc(sizeof(t_road));
			road_end->next->next = NULL;
			road_end->next->name = room_to_add->name;
			ft_create_new_paths(paths, anchor, backup);
			break ;
		}
		room_to_add = room_to_add->next;
	}
	ft_close_paths(paths, start);
}