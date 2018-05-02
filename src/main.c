#include "../inc/lem-inc.h"

int main(void)
{
	t_room	*start;
	t_paths	*paths;

	start = ft_new_room("start");
	ft_add_room(&start, "1");
	ft_add_room(&start, "2");
	ft_add_room(&start, "3");
	ft_add_room(&start, "4");
	ft_add_room(&start, "finish");
    ft_add_link("start", "finish", &start);
    ft_add_link("start", "1", &start);
    ft_add_link("start", "2", &start);
    ft_add_link("start", "3", &start);
    ft_add_link("start", "4", &start);
    ft_add_link("1", "start", &start);
    ft_add_link("1", "3", &start);
    ft_add_link("2", "start", &start);
    ft_add_link("2", "4", &start);
    ft_add_link("3", "1", &start);
    ft_add_link("3", "start", &start);
    ft_add_link("3", "finish", &start);
    ft_add_link("4", "finish", &start);
    ft_add_link("4", "start", &start);
    ft_add_link("4", "2", &start);
    ft_add_link("finish", "3", &start);
    ft_add_link("finish", "4", &start);
    ft_add_link("finish", "start", &start);
	ft_print_maze(start);
	paths = ft_init_path(start);
	while (ft_open_paths(paths))
		ft_get_paths(paths, start);
	ft_print_paths(paths);
	return 0;
}
