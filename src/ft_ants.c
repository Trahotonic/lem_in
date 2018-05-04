#include "../inc/lem-inc.h"

static t_ants	*ft_new_ant(size_t nbr)
{
	t_ants *ant;

	ant = (t_ants*)malloc(sizeof(t_ants));
	ant->ant_nbr = nbr;
	ant->next = NULL;
	return (ant);
}

void				ft_get_ants(size_t ants_q, t_ants **ants)
{
	t_ants	*ant;

	ant = (t_ants*)malloc(sizeof(t_ants));
	ant->ant_nbr = ants_q;
	ant->next = NULL;
	*ants = ant;
	ants_q -= 1;
	while (ants_q)
	{
		ant = (t_ants*)malloc(sizeof(t_ants));
		ant->ant_nbr = ants_q;
		ant->next = *ants;
		*ants = ant;
		ants_q -= 1;
	}
}