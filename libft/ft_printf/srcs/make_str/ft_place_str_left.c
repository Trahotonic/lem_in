/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_str_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:33:06 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/12 14:33:07 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static void	ft_place_wid(t_specs specs, int count, int *ret)
{
	while (count < specs.width)
	{
		write(1, " ", 1);
		count++;
		*ret += 1;
	}
}

int			ft_place_str_left(char *str, t_specs specs)
{
	int		count;
	int		ret;

	ret = 0;
	if (str == NULL)
		str = "(null)";
	count = 0;
	if (specs.acc_flag == 1)
	{
		while (count < specs.accuracy && str[count] != '\0')
		{
			write(1, &str[count++], 1);
			ret++;
		}
		count = 0;
	}
	else
	{
		ft_putstr(str);
		ret += ft_strlen(str);
	}
	ft_place_wid(specs, count, &ret);
	return (ret);
}
