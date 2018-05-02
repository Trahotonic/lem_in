/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_oct_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:28:27 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/10 16:28:28 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static void	ft_do_magic(int *ret, unsigned long long n)
{
	char	*str;

	str = ft_itoa_base(n, 8);
	ft_putstr(str);
	*ret += ft_strlen(str);
	free(str);
}

static void	ft_shmatok(t_specs specs, char fill, int *ret)
{
	int		count;

	count = 0;
	while (count < specs.width)
	{
		write(1, &fill, 1);
		count++;
		*ret += 1;
	}
	count = 0;
	if (fill != '0' && specs.hash == 1)
	{
		write(1, "0", 1);
		*ret += 1;
	}
	while (count < specs.accuracy)
	{
		write(1, "0", 1);
		count++;
		*ret += 1;
	}
}

int			ft_place_oct_right(unsigned long long n, t_specs specs)
{
	int		count;
	int		ret;
	char	fill;
	char	*str;

	str = NULL;
	ret = 0;
	if (specs.hh == 1)
		n = (unsigned char)n;
	if (specs.h == 1)
		n = (unsigned short)n;
	count = 0;
	fill = ' ';
	if (specs.zero == 1)
		fill = '0';
	if (fill == '0' && specs.hash == 1)
	{
		ft_putchar('0');
		ret++;
	}
	ft_shmatok(specs, fill, &ret);
	if (!(specs.acc_flag == 1 && specs.accuracy == 0 && n == 0))
		ft_do_magic(&ret, n);
	return (ret);
}
