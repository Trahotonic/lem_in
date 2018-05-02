#include "../inc/lem-inc.h"

static void ft_other_links(t_paths *paths, t_room *start)
{
    t_paths *ptr;
    t_link  *link;

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
}

t_paths	    *ft_init_path(t_room *start)
{
    t_paths *paths;

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
    ft_other_links(paths, start);
    return (paths);
}