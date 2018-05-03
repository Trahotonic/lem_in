#include "../inc/lem-inc.h"

int main(void)
{
	t_room	*start;
//	t_paths	*paths;
	size_t 	ants_q;

	if (!ft_get_maze_part_1(&start, &ants_q))
		return (1);
	ft_print_maze(start);
//	paths = ft_init_path(start);
//	while (ft_open_paths(paths))
//		ft_get_paths(paths, start);
//	ft_print_paths(paths);
//	system("leaks lem-in");
	return 0;
}
