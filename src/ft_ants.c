#include "../inc/lem-inc.h"

static char	*ft_aggr_join(char *s1, char *s2)
{
    char	*ret;
    char    *anchor;
    int		n;

    if (s1 && s2)
    {
        anchor = s2;
        if (!(ret = (char*)malloc(sizeof(char) * ((ft_strlen(s1) +
                ft_strlen(s2)) + 1))))
            return (NULL);
        n = 0;
        while (s1[n] != '\0')
        {
            ret[n] = s1[n];
            n++;
        }
        while (*s2)
            ret[n++] = *s2++;
        ret[n] = '\0';
        free(s1);
        free(anchor);
        return (ret);
    }
    return (NULL);
}


void				ft_get_ants(size_t ants_q, t_ants **ants, t_link *path)
{
	t_ants  *ant;
    size_t  n;

	ant = (t_ants*)malloc(sizeof(t_ants) * ants_q + 1);
//	ant->ant_nbr = ants_q;
//	ant->road = path;
//	ant->next = NULL;
//	*ants = ant;
//	ants_q -= 1;
//	while (ants_q)
//	{
//        printf("%zu\n", ants_q);
//		ant = (t_ants*)malloc(sizeof(t_ants));
//		ant->ant_nbr = ants_q;
//        ant->road = path;
//		ant->next = *ants;
//		*ants = ant;
//		ants_q -= 1;
//	}
    n = 0;
    while (n < ants_q)
    {
        ant[n].ant_nbr = n + 1;
        ant[n].road = path;
        ant[n].next = NULL;
        n += 1;
    }
}

//void            ft_move_one_step(t_ants *ants, t_room *start, size_t newbie)
//{
//    t_ants *ptr;
//
//    ptr = ants;
//    while (ptr)
//    {
//        if (ptr->road->station != ft_start_location(start) &&
//                ft_destination(start) != ptr->road->station &&
//             ptr->ant_nbr != newbie)
//        {
//            ft_printf("L%zu-%s ", ptr->ant_nbr, ptr->road->next->station->room_name);
//            ptr->road = ptr->road->next;
//        }
//        ptr = ptr->next;
//    }
//}
//
//int             ft_some_ants_still_moving(t_ants *ants, t_room *start)
//{
//    t_ants *ptr;
//
//    ptr = ants;
//    while (ptr)
//    {
//        if (ptr->road->station != ft_destination(start))
//            return (1);
//        ptr = ptr->next;
//    }
//    return (0);
//}
//

void            ft_print_dis(t_link *path)
{
    while (path)
    {
        ft_printf("%d", path->station->ant_nbr);
        if (path->next)
            ft_printf("-");
        else
            ft_printf("\n");
        path = path->next;
    }
}


size_t          ft_get_min(t_link *path)
{
    size_t ret;

//    ft_print_dis(path);
    while (path->station->ant_nbr == 0)
        path = path->next;
    ret = path->station->ant_nbr;
    while (path)
    {
//        printf("*\n");
        if (path->station->ant_nbr < ret && path->station->ant_nbr != 0) {
//            printf("was %zu\n", ret);
            ret = path->station->ant_nbr;
//            printf("became %zu\n", ret);
        }
        path = path->next;
    }
//    printf("%zu\n", ret);
    return (ret);
}

size_t          ft_get_max(t_link *path)
{
    size_t ret;

    ret = path->station->ant_nbr;
    while (path)
    {
        if (path->station->ant_nbr > ret)
            ret = path->station->ant_nbr;
        path = path->next;
    }
    return (ret);
}

void            ft_increase(t_link *path, size_t ants_q)
{
    t_link  *ptr;
    t_link  *anchor;
    size_t  checker;
    size_t min;
    size_t max;

    ptr = path;
    anchor = path;
    min = ft_get_min(anchor);
    while (path)
    {
        if (path->station->ant_nbr != 0)
            path->station->ant_nbr += 1;
        if (path->station->ant_nbr > ants_q)
            path->station->ant_nbr = 0;
        path = path->next;
    }
    while (ptr->station->ant_nbr != min + 1)
        ptr = ptr->next;
    if (ptr->next && ptr->next->station->ant_nbr == 0)
        ptr->next->station->ant_nbr = 1;
    min = ft_get_min(anchor);
    max = ft_get_max(anchor);
    checker = min;
    while (checker <= max)
    {
        ptr = anchor;
        while (ptr->station->ant_nbr != checker)
            ptr = ptr->next;
        ft_printf("L%zu-%s ", ptr->station->ant_nbr, ptr->station->room_name);
        checker += 1;
    }
    ft_printf("\n");
}

void            ft_move_ants(size_t ants_q, t_link *path, t_room *rooms)
{
    t_link  *ptr;

    ptr = path->next;
    free(path);
    path = ptr;
    path->station->ant_nbr = 1;
    if (ants_q > 1)
    {
        ft_printf("L1-%s\n", path->station->room_name);
        while (ft_destination(rooms)->ant_nbr != ants_q)
            ft_increase(path, ants_q);
    }
    else
        while (path)
        {
            ft_printf("L1-%s\n", path->station->room_name);
            path = path->next;
        }
}