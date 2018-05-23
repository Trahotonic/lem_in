/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_hex_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:27:21 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/10 16:27:22 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static void	ft_do_magic(char x, int *ret, unsigned long long n)
{
	char	*str;

	str = ft_uitoa_base(n, 16);
	*ret += ft_strlen(str);
	if (x == 'x')
		ft_putstr(ft_allow(str));
	else
		ft_putstr(str);
	free(str);
}

static void	ft_place_ox(int *ret, char x)
{
	write(1, "0", 1);
	write(1, &x, 1);
	*ret += 2;
}

static void	ft_place_acc(t_specs specs, int *ret)
{
	int		count;

	count = 0;
	while (count < specs.accuracy)
	{
		ft_putchar('0');
		count++;
		*ret += 1;
	}
}

static void	ft_place_wid(t_specs specs, int *ret, char fill)
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

int			ft_place_hex_right(unsigned long long n, t_specs specs, char x)
{
	char	fill;
	int		ret;
	char	*str;

	ret = 0;
	str = NULL;
	if (specs.hh == 1)
		n = (unsigned char)n;
	if (specs.h == 1)
		n = (unsigned short)n;
	fill = ' ';
	if (specs.zero == 1)
		fill = '0';
	if (fill == '0' && specs.hash == 1)
		ft_place_ox(&ret, x);
	ft_place_wid(specs, &ret, fill);
	if (fill != '0' && specs.hash == 1)
		ft_place_ox(&ret, x);
	ft_place_acc(specs, &ret);
	if (!(specs.acc_flag == 1 && specs.accuracy == 0 && n == 0))
		ft_do_magic(x, &ret, n);
	return (ret);
}
