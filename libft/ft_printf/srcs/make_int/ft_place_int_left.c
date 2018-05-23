/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_int_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:26:14 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/10 16:26:14 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static void	ft_plusominus(long long n, int *ret, t_specs specs)
{
	if (n < 0)
	{
		write(1, "-", 1);
		*ret += 1;
	}
	if (n >= 0 && specs.plus == 1)
	{
		write(1, "+", 1);
		*ret += 1;
	}
}

static void	ft_do_magic(long long n, int *ret)
{
	char	*str;

	str = ft_itoa_base(n, 10);
	ft_putstr(str);
	*ret += ft_strlen(str);
	free(str);
}

static void	ft_shmatok(t_specs specs, int *ret, long long n)
{
	int		count;

	count = 0;
	if (specs.space == 1)
	{
		write(1, " ", 1);
		*ret += 1;
	}
	ft_plusominus(n, ret, specs);
	while (count < specs.accuracy)
	{
		write(1, "0", 1);
		count++;
		*ret += 1;
	}
}

int			ft_place_int_left(long long n, t_specs specs)
{
	int		count;
	int		ret;

	ret = 0;
	if (specs.h == 1)
		n = (short)n;
	if (specs.hh == 1)
		n = (signed char)n;
	count = 0;
	ft_shmatok(specs, &ret, n);
	if (n < 0)
		n = -n;
	if (!(specs.acc_flag == 1 && specs.accuracy == 0 && n == 0))
		ft_do_magic(n, &ret);
	count = 0;
	while (count < specs.width - specs.space)
	{
		write(1, " ", 1);
		count++;
		ret++;
	}
	return (ret);
}
