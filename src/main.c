#include "../inc/lem-inc.h"

int main(void)
{
	t_room	*start;
	t_paths	*paths;
	size_t 	ants_q;
    char	*transfer;
	t_path	*sortest_path;
	t_ants	*ants;

	if (!ft_get_maze_part_1(&start, &ants_q, &transfer))
		return (1);
    if (!ft_get_maze_part_2(&start, transfer))
        return (1);
//	ft_print_maze(start);
	paths = ft_init_path(start);
	while (ft_open_paths(paths))
		ft_get_paths(paths, start);
	ft_print_paths(paths);
//	if (ft_successful_roads(paths))
//		ft_print_path(ft_get_shortest_path(paths));
//	else
//		ft_printf("All paths lead to dead end\n");
	ft_get_ants(ants_q, &ants, paths);
	ft_print_ants(ants);
    ft_move_ants(ants, start);
//	system("leaks lem-in");
	return 0;
}
