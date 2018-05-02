/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_chr_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:42:32 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/12 18:42:32 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static int	ft_check_size(unsigned int c)
{
	if (c <= 127)
		return (1);
	else if (c > 127 && c <= 2047)
		return (2);
	else if (c > 2047 && c <= 65535)
		return (3);
	else
		return (4);
}

static void	ft_place_wid(t_specs specs, char fill, int *ret)
{
	int		count;

	count = 0;
	while (count < specs.width)
	{
		write(1, &fill, 1);
		count++;
		*ret += 1;
	}
}

int			ft_place_chr_right(unsigned int c, t_specs specs, char uni)
{
	int		count;
	int		ret;
	char	fill;

	count = 0;
	ret = 0;
	fill = ' ';
	if (specs.zero == 1)
		fill = '0';
	ft_place_wid(specs, fill, &ret);
	if ((uni == 'C' || specs.l == 1) && MB_CUR_MAX != 1 && c > 255)
	{
		ft_print_uni(c);
		ret += ft_check_size(c);
	}
	else
	{
		write(1, &c, 1);
		ret++;
	}
	return (ret);
}
