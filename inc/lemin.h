/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:49:02 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/05/29 12:49:05 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"
# include "backup.h"

typedef struct		s_link
{
	t_room			*station;
	struct s_link	*next;
}					t_link;

typedef struct		s_paths
{
	t_link			*path;
	int				closed;
	int				dead_end;
	struct s_paths	*next;
}					t_paths;

typedef struct		s_ants
{
	size_t			ant_nbr;
	t_link			*road;
	struct s_ants	*next;
}					t_ants;

int					ft_return_error(char **line);
int					ft_start_end_present(t_room *start);
t_room				*ft_start_location(t_room *start);
t_room				*ft_destination(t_room *start);
void				ft_print_ants(t_ants *ants);
void				ft_free_dump(char **dump);
int					ft_invalid_coordinates(char *line);
int					ft_room_exists(t_room *start, char *line);
int					ft_coordinates_exist(t_room *start, char *line);
t_room				*ft_new_room(char *name, int n);
void				ft_add_room(t_room **rooms, char *name, int n);
void				ft_add_link(char *from, char *to, t_room **rooms);
int					ft_start_exists(t_room *start);
int					ft_end_exists(t_room *start);
int					ft_invalid_ants(char *line, size_t *ants_q);
int					ft_is_all_digit(char *line);
int					ft_is_comment(char *line);
int					ft_is_room(char *line);
int					ft_is_link(char *line);
void				ft_skip_comments(char **work);
void				ft_start_or_end(char *line, char *work, t_room **start);
int					ft_case_start(t_room **start, char **line);
int					ft_case_end(t_room **start, char **line);
void				ft_shmatochok(char **line);
int					ft_invalid_command(char *line);
int					ft_get_maze_part_1(t_room **start, size_t *ants_q,
										char **transfer, char *line);
int					ft_get_maze_part_2(t_room **start, char *transfer);
void				ft_set_depth(t_room *start);
t_link				*ft_find_path(t_room *rooms);
void				ft_print_path(t_link *path);
void				ft_print_maze(t_room *start);
int					ft_is_one_station(t_link *path);
int					ft_move_ants(size_t ants_q, t_link *path, t_room *rooms);

#endif
