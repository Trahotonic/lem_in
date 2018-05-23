/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_oct_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:28:15 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/10 16:28:15 by rkyslyy          ###   ########.fr       */
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

static void	ft_shmatok(t_specs specs, unsigned long long n, int *ret)
{
	int		count;

	count = 0;
	if (specs.hash == 1 && n != 0)
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

int			ft_place_oct_left(unsigned long long n, t_specs specs)
{
	int		count;
	int		ret;

	ret = 0;
	if (specs.hh == 1)
		n = (unsigned char)n;
	if (specs.h == 1)
		n = (unsigned short)n;
	ft_shmatok(specs, n, &ret);
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
