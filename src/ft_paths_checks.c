#include "../inc/lem-inc.h"

int		ft_check_back(t_link *path, t_room *station)
{
    while (path)
    {
        if (path->station == station)
            return (1);
        path = path->next;
    }
    return (0);
}

t_link      *ft_get_last_road_station(t_link *path)
{
    while (path->next)
        path = path->next;
    return (path);
}

int 	ft_dead_end(t_link *path)
{
    t_link *last_room_links;

    last_room_links = ft_get_last_road_station(path)->station->links;
    while (last_room_links)
    {
        if (!ft_check_back(path, last_room_links->station))
            return (0);
        last_room_links = last_room_links->next;
    }
    return (1);
}

t_room    *ft_destination(t_room *start)
{
    t_room  *ptr;

    ptr = start;
    while (!ptr->end)
        ptr = ptr->next;
    return (ptr);
}
//
//void    ft_free_some_paths(t_paths *paths)
//{
//    t_paths *ptr;
//    t_paths *buff;
//
//    ptr = paths;
//    while (ptr && ptr->path->dead_end)
//        ptr = ptr->next;
//    if (ptr && ptr->next && ptr->path->dead_end)
//        ptr = ptr->next;
//    while (ptr)
//    {
//        if (ptr->next && ptr->next->next && ptr->next->path->dead_end)
//        {
//            buff = ptr->next;
//            ptr->next = ptr->next->next;
//            free(buff);
//        }
//        ptr = ptr->next;
//    }
//}
//
void	ft_close_paths(t_paths *paths, t_room *start)
{
//    t_paths *ptr;
//
//    ptr = paths;
//    while (ptr)
//    {
//        if (!ft_strcmp(ft_get_last_road_station(ptr->path->road), ft_destination(start)) &&
//				ptr->path->closed == 0)
//        {
//            ptr->path->closed = 1;
//            ft_print_path(ptr->path);
//        }
//        if (ft_dead_end(ptr->path, start) &&
//            ft_strcmp(ft_get_last_road_station(ptr->path->road), ft_destination(start)) &&
//				ptr->path->closed == 0)
//        {
//            ptr->path->closed = 1;
//            ptr->path->dead_end = 1;
//            ft_print_path(ptr->path);
//        }
//        ptr = ptr->next;
//    }
    t_room *destination;

    destination = ft_destination(start);
    while (paths)
    {
        if (ft_get_last_road_station(paths->path)->station == destination)
        {
            ft_printf("arrived\n");
            paths->closed = 1;
        }
        if (ft_dead_end(paths->path) && ft_get_last_road_station(paths->path)->station !=
                destination)
        {
//            ft_printf("%s dead end\n", ft_get_last_road_station(paths->path)->station->room_name);
            paths->closed = 1;
            paths->dead_end = 1;
        }
        paths = paths->next;
    }
}
