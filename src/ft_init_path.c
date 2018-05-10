#include "../inc/lem-inc.h"

t_room   *ft_start_location(t_room *start)
{
    t_room  *ptr;

    ptr = start;
    while (!ptr->start)
        ptr = ptr->next;
    return (ptr);
}

static void     ft_other_links(t_paths *paths, t_room *start)
{
    t_paths *ptr;
    t_link  *link;

    ptr = paths;
    link = start->links->next;
    while (link)
    {
        ptr->next = (t_paths*)malloc(sizeof(t_paths));
        ptr->next->next = NULL;
        ptr->next->path = (t_link*)malloc(sizeof(t_link));
        ptr->next->closed = 0;
        ptr->next->dead_end = 0;
        ptr->next->path->station = start;
        ptr->next->path->next = (t_link*)malloc(sizeof(t_link));
        ptr->next->path->next->station = link->station;
        ptr->next->path->next->next = NULL;
        ptr = ptr->next;
        link = link->next;
    }
}

t_paths         *ft_init_path(t_room *start)
{
    t_paths *paths;

    if (ft_start_location(start)->links == NULL)
        return (0);
	paths = (t_paths*)malloc(sizeof(t_paths));
	paths->closed = 0;
	paths->dead_end = 0;
	paths->next = NULL;
	paths->path = (t_link*)malloc(sizeof(t_link));
	paths->path->station = ft_start_location(start);
	paths->path->next = (t_link*)malloc(sizeof(t_link));
	paths->path->next->next = NULL;
	paths->path->next->station = ft_start_location(start)->links->station;
	ft_other_links(paths, ft_start_location(start));
    return (paths);
}