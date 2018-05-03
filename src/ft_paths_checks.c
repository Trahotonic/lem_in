#include "../inc/lem-inc.h"

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

int 	ft_dead_end(t_path *path, t_room *start)
{
    t_link *last_room_links;

    last_room_links = ft_find_last_room(path, start)->links;
    while (last_room_links)
    {
        if (!ft_check_back(path, last_room_links->name))
            return (0);
        last_room_links = last_room_links->next;
    }
    return (1);
}

char 	*ft_get_last_road_station(t_road *road)
{
    t_road	*ptr;

    ptr = road;
    while (ptr->next)
        ptr = ptr->next;
    return (ptr->name);
}

void	ft_close_paths(t_paths *paths, t_room *start)
{
    t_paths *ptr;

    ptr = paths;
    while (ptr)
    {
        if (!ft_strcmp(ft_get_last_road_station(ptr->path->road), "finish"))
            ptr->path->closed = 1;
        if (ft_dead_end(ptr->path, start) &&
            ft_strcmp(ft_get_last_road_station(ptr->path->road), "finish"))
        {
            ptr->path->closed = 1;
            ptr->path->dead_end = 1;
        }
        ptr = ptr->next;
    }
}

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