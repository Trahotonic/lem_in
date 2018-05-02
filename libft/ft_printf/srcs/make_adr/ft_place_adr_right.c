/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_adr_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:53:29 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/12 13:53:30 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static void	ft_place_ox(int *ret)
{
	ft_putchar('0');
	ft_putchar('x');
	*ret += 2;
}

static void	ft_do_magic(int *ret, unsigned long long n)
{
	char	*s;

	s = ft_uitoa_base(n, 16);
	*ret += ft_strlen(s);
	ft_putstr(ft_allow(s));
	free(s);
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

int			ft_place_adr_right(unsigned long long n, t_specs specs)
{
	int		count;
	char	fill;
	int		ret;

	count = 0;
	ret = 0;
	fill = ' ';
	if (specs.zero == 1)
	{
		ft_place_ox(&ret);
		fill = '0';
	}
	while (count < specs.width)
	{
		ft_putchar(fill);
		count++;
		ret++;
	}
	if (fill == ' ')
		ft_place_ox(&ret);
	ft_place_acc(specs, &ret);
	if (!(specs.acc_flag == 1 && specs.accuracy == 0 && n == 0))
		ft_do_magic(&ret, n);
	return (ret);
}
