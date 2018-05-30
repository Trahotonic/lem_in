/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:25:31 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/05/22 15:25:32 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

static void	ft_check_debug(int argc, char **argv, t_room *start, t_link *path)
{
	int		n;
	int		m;
	int		p;

	n = 1;
	m = 0;
	p = 0;
	while (n < argc)
	{
		if (ft_strequ(argv[n], "-m"))
			m = 1;
		if (ft_strequ(argv[n], "-p"))
			p = 1;
		n += 1;
	}
	if (m)
	{
		ft_printf("\n");
		ft_print_maze(start);
	}
	if (p)
		ft_print_path(path);
}

int			main(int argc, char **argv)
{
	t_room	*start;
	size_t	ants_q;
	char	*transfer;
	t_link	*path;
	char	*line;

	line = NULL;
	if (!ft_get_maze_part_1(&start, &ants_q, &transfer, line))
		return (1);
	if (!ft_get_maze_part_2(&start, transfer))
	{
		ft_set_depth(start);
		path = ft_find_path(start);
		if (!path)
			return (ft_printf("\033[1;31mError\e[m\n"));
		ft_check_debug(argc, argv, start, path);
		return (ft_move_ants(ants_q, path, start));
	}
	ft_set_depth(start);
	path = ft_find_path(start);
	if (!path)
		return (ft_printf("\033[1;31mError\e[m\n"));
	ft_check_debug(argc, argv, start, path);
	return (ft_move_ants(ants_q, path, start));
}
