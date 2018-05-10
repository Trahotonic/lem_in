#include "../inc/lem-inc.h"

int main(void)
{
	t_room	*start;
	t_paths	*paths;
	size_t 	ants_q;
    char		*transfer;
	t_ants	*ants;

	if (!ft_get_maze_part_1(&start, &ants_q, &transfer))
		return (1);
    if (!ft_get_maze_part_2(&start, transfer))
	{
		paths = ft_init_path(start);
		while (ft_open_paths(paths))
			ft_get_paths(paths, start);
		if (!ft_successful_roads(paths))
			return (ft_printf("Error\n"));
	}
//	ft_print_maze(start);
	paths = ft_init_path(start);
	if (!paths)
		return (ft_printf("Error\n"));
	while (ft_open_paths(paths)) {
        ft_get_paths(paths, start);
    }
	if (!ft_successful_roads(paths))
		return (ft_printf("Error\n"));
//	paths = ft_other_short_paths(paths, ft_get_shortest_path(paths));
//	ft_print_paths(paths);
//	ft_print_path(ft_get_shortest_path(paths));
	ft_get_ants(ants_q, &ants, paths);
//	ft_print_ants(ants);
    ft_move_ants(ants, start);
//	return 0;
}
