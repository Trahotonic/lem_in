#include "../inc/lem-inc.h"

//void				ft_get_ants(size_t ants_q, t_ants **ants, t_paths *paths)
//{
//	t_ants	*ant;
//
//	ant = (t_ants*)malloc(sizeof(t_ants));
//	ant->ant_nbr = ants_q;
//	ant->road = ft_get_shortest_path(paths)->road;
//	ant->next = NULL;
//	*ants = ant;
//	ants_q -= 1;
//	while (ants_q)
//	{
//		ant = (t_ants*)malloc(sizeof(t_ants));
//		ant->ant_nbr = ants_q;
//        ant->road = ft_get_shortest_path(paths)->road;
//		ant->next = *ants;
//		*ants = ant;
//		ants_q -= 1;
//	}
//}
//
//void            ft_move_one_step(t_ants *ants, t_room *start, size_t newbie)
//{
//    t_ants *ptr;
//
//    ptr = ants;
//    while (ptr)
//    {
//        if (!ft_strequ(ptr->road->name,
//                       ft_start_location(start)->room_name) &&
//                !ft_strequ(ft_destination(start), ptr->road->name) &&
//             ptr->ant_nbr != newbie)
//        {
//            ft_printf("L%zu-%s ", ptr->ant_nbr, ptr->road->next->name);
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
//        if (!ft_strequ(ptr->road->name, ft_destination(start)))
//            return (1);
//        ptr = ptr->next;
//    }
//    return (0);
//}
//
//void            ft_move_ants(t_ants *ants, t_room *start)
//{
//    t_ants  *changer;
//
//    changer = ants;
//    while (ft_some_ants_still_moving(ants, start))
//    {
//        if (changer)
//            ft_move_one_step(ants, start, changer->ant_nbr);
//        else
//            ft_move_one_step(ants, start, 0);
//        if (changer)
//        {
//            ft_printf("L%zu-%s ", changer->ant_nbr, changer->road->next->name);
//            changer->road = changer->road->next;
//            changer = changer->next;
//        }
//        ft_printf("\n");
//    }
//}