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

int		ft_check_back(t_path *path, char const *room_name)
{
	t_road	*ptr;

	ptr = path->road;
	while (ptr)
	{
		if (!ft_strcmp(ptr->name, room_name))
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
//
//void		ft_add_room_to_path(t_path *path, t_room *room)
//{
//	t_road	*road_ptr;
//	t_link	*link_ptr;
//
//	road_ptr = path->road;
//	link_ptr = room->links;
//	while (road_ptr)
//		road_ptr = road_ptr->next;
//
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

char 		*ft_get_last_road_station(t_road *road)
{
	t_road	*ptr;

	ptr = road;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr->name);
}

void		ft_create_new_paths(t_paths *paths, t_link *links, t_road *road, t_path *p)
{
	t_road	*road_ptr;
	t_paths	*paths_ptr;
	t_link	*link_ptr;
	t_path	*path;

	road_ptr = road;
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
			path->road = ft_duplicate_road(road, link_ptr);
			if (!ft_strcmp(ft_get_last_road_station(path->road), "finish"))
				path->closed = 1;
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
	t_paths	*ptr;
	t_room	*last_room_in_path;
	t_road	*road_end;
	t_link	*room_to_add;
	t_link	*anchor;

	ptr = paths;
	while (ptr->path->closed)
		ptr = ptr->next;
//	ft_printf("here\n");
//	ft_print_path(ptr->path);
	last_room_in_path = ft_find_last_room(ptr->path, start);
	road_end = ptr->path->road;
	while (road_end->next)
		road_end = road_end->next;
	room_to_add = last_room_in_path->links;
	anchor = room_to_add;
//	ft_printf("here %s\n", anchor->name);
	while (room_to_add)
	{
		if (!ft_check_back(ptr->path, room_to_add->name))
		{
			road_end->next = (t_road*)malloc(sizeof(t_road));
			road_end->next->next = NULL;
			road_end->next->name = room_to_add->name;
			if (!ft_strcmp(road_end->next->name, "finish"))
				ptr->path->closed = 1;
			ft_create_new_paths(paths, anchor, ptr->path->road, ptr->path);
			return ;
		}
		room_to_add = room_to_add->next;
	}
}