/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_str_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:33:20 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/12 14:33:21 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static void	ft_for_acc(t_specs specs, char *str, int *ret, int count)
{
	if (specs.acc_flag == 1)
		while (count < specs.accuracy && str[count] != '\0')
		{
			write(1, &str[count++], 1);
			*ret += 1;
		}
	else
	{
		ft_putstr(str);
		*ret += ft_strlen(str);
	}
}

int			ft_place_str_right(char *str, t_specs specs)
{
	int		count;
	char	fill;
	int		ret;

	ret = 0;
	if (str == NULL)
		str = "(null)";
	count = 0;
	fill = ' ';
	if (specs.zero == 1)
		fill = '0';
	while (count < specs.width)
	{
		write(1, &fill, 1);
		count++;
		ret++;
	}
	count = 0;
	ft_for_acc(specs, str, &ret, count);
	return (ret);
}
