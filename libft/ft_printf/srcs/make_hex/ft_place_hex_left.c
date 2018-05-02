/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_hex_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:27:11 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/10 16:27:12 by rkyslyy          ###   ########.fr       */
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

static void	ft_place_acc(int accuracy, int *ret)
{
	int		count;

	count = 0;
	while (count < accuracy)
	{
		write(1, "0", 1);
		count++;
		*ret += 1;
	}
}

int			ft_place_hex_left(unsigned long long n, t_specs specs, char x)
{
	int		count;
	int		ret;

	ret = 0;
	if (specs.hh == 1)
		n = (unsigned char)n;
	if (specs.h == 1)
		n = (unsigned short)n;
	if (specs.hash == 1)
	{
		ft_putchar('0');
		ft_putchar(x);
		ret += 2;
	}
	ft_place_acc(specs.accuracy, &ret);
	if (!(specs.acc_flag == 1 && specs.accuracy == 0 && n == 0))
		ft_do_magic(x, &ret, n);
	count = 0;
	while (count < specs.width)
	{
		ft_putchar(' ');
		count++;
		ret++;
	}
	return (ret);
}
