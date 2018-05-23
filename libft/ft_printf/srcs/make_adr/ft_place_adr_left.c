/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_adr_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:53:15 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/12 13:53:15 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static void	ft_do_magic(int *ret, unsigned long long n)
{
	char	*s;

	s = ft_uitoa_base(n, 16);
	*ret += ft_strlen(s);
	ft_putstr(ft_allow(s));
	free(s);
}

int			ft_place_adr_left(unsigned long long n, t_specs specs)
{
	int		count;
	int		ret;

	count = 0;
	ret = 0;
	ft_putchar('0');
	ft_putchar('x');
	ret += 2;
	while (count < specs.accuracy)
	{
		ft_putchar('0');
		count++;
		ret++;
	}
	if (!(specs.acc_flag == 1 && specs.accuracy == 0 && n == 0))
		ft_do_magic(&ret, n);
	count = 0;
	while (count < specs.width)
	{
		ft_putchar(' ');
		count++;
		ret++;
	}
	return (ret);
}
