/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:22:17 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/05/22 15:22:18 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int	ft_invalid_coordinates(char *line)
{
	char	**dump;
	size_t	n;
	int		sign;

	n = 0;
	sign = 0;
	while (line[n] != '\0')
	{
		if (line[n] == '-' || line[n] == '+')
			sign += 1;
		n += 1;
	}
	dump = ft_strsplit(line, ' ');
	if (dump[0][0] == 'L' || sign > 1 || !ft_is_all_digit(dump[1]) ||
		!ft_is_all_digit(dump[2]) || ft_atoi(dump[1]) > 2147483647 ||
		ft_atoi(dump[1]) < -2147483648 || ft_atoi(dump[2]) > 2147483647 ||
		ft_atoi(dump[2]) < -2147483648)
	{
		ft_free_dump(dump);
		return (1);
	}
	ft_free_dump(dump);
	return (0);
}

int	ft_room_exists(t_room *start, char *line)
{
	t_room	*ptr;
	char	**dump;

	ptr = start;
	dump = ft_strsplit(line, ' ');
	while (ptr)
	{
		if (ft_strequ(ptr->room_name, dump[0]))
		{
			ft_free_dump(dump);
			return (1);
		}
		ptr = ptr->next;
	}
	ft_free_dump(dump);
	return (0);
}

int	ft_coordinates_exist(t_room *start, char *line)
{
	t_room	*ptr;
	char	**dump;

	ptr = start;
	dump = ft_strsplit(line, ' ');
	while (ptr)
	{
		if (ptr->x == ft_atoi(dump[1]) && ptr->y == ft_atoi(dump[2]))
		{
			ft_free_dump(dump);
			return (1);
		}
		ptr = ptr->next;
	}
	ft_free_dump(dump);
	return (0);
}
