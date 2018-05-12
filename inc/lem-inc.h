#ifndef LEM_IN_LEM_INC_H
#define LEM_IN_LEM_INC_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_room t_room;

typedef struct		s_link
{
	t_room          *station;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	char 			*room_name;
	long			x;
	long 			y;
	long 			depth;
    size_t          ant_nbr;
	int 			start;
	int 			end;
	t_link			*links;
	struct s_room	*next;
}					t_room;

typedef struct		s_paths
{
	t_link			*path;
	int 			closed;
	int 			dead_end;
	struct s_paths	*next;
}					t_paths;

typedef struct		s_ants
{
	size_t			ant_nbr;
    t_link			*road;
	struct s_ants	*next;
}					t_ants;

int 		ft_start_end_present(t_room *start);
t_room      *ft_start_location(t_room *start);
t_room      *ft_destination(t_room *start);
void		ft_print_ants(t_ants *ants);
void		ft_free_dump(char **dump);
int 		ft_invalid_coordinates(char *line);
int 		ft_room_exists(t_room *start, char *line);
int 		ft_coordinates_exist(t_room *start, char *line);
t_room		*ft_new_room(char *name, int n);
void		ft_add_room(t_room **rooms, char *name, int n);
void		ft_add_link(char *from, char *to, t_room **rooms);
int			ft_start_exists(t_room *start);
int 		ft_end_exists(t_room *start);
int 		ft_invalid_ants(char *line, size_t *ants_q);
int 		ft_is_all_digit(char *line);
int 		ft_is_comment(char *line);
int 		ft_is_room(char *line);
int 		ft_is_link(char *line);
int			ft_get_maze_part_1(t_room **start, size_t *ants_q, char **transfer);
int     	ft_get_maze_part_2(t_room **start, char *transfer);
void		ft_set_depth(t_room *start);
t_link		*ft_find_path(t_room *rooms);
void		ft_print_path(t_link *path);
//t_paths		*ft_init_path(t_room *start);
//int			ft_check_back(t_link *path, t_room *station);
//t_room      *ft_find_last_room(t_link *path);
//int			ft_dead_end(t_path *path, t_room *start);
//char 		*ft_get_last_road_station(t_road *road);
//void		ft_close_paths(t_paths *paths, t_room *start);
//int			ft_open_paths(t_paths *paths);
//void		ft_get_paths(t_paths *paths, t_room *start);
//int 		ft_successful_roads(t_paths *paths);
//t_path		*ft_get_shortest_path(t_paths *paths);
//t_paths		*ft_other_short_paths(t_paths *paths, t_path *shortest);
//void		ft_get_ants(size_t ants_q, t_ants **ants, t_link *path);
void		ft_print_maze(t_room *start);
//void		ft_print_paths(t_paths *paths);
void        ft_move_ants(size_t ants_q, t_link *path, t_room *rooms);

#endif
