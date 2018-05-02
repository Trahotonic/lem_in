/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_int_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:26:22 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/10 16:26:23 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static void	ft_plusominus1(long long n, t_specs specs, int *ret, char fill)
{
	int		count;

	count = 0;
	if (n < 0 && fill == '0')
	{
		write(1, "-", 1);
		*ret += 1;
	}
	if (n >= 0 && specs.plus == 1 && fill == '0')
	{
		write(1, "+", 1);
		*ret += 1;
	}
}

static void	ft_plusominus2(long long n, t_specs specs, int *ret, char fill)
{
	int		count;

	count = 0;
	if (n < 0 && fill != '0')
	{
		write(1, "-", 1);
		*ret += 1;
	}
	if (n >= 0 && specs.plus == 1 && fill != '0')
	{
		write(1, "+", 1);
		*ret += 1;
	}
}

static void	ft_shmatok(t_specs specs, int *ret, char fill, long long n)
{
	int		count;

	count = 0;
	ft_plusominus1(n, specs, ret, fill);
	while (count < specs.width - specs.space)
	{
		write(1, &fill, 1);
		count++;
		*ret += 1;
	}
	ft_plusominus2(n, specs, ret, fill);
	count = 0;
	while (count < specs.accuracy)
	{
		write(1, "0", 1);
		count++;
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

int			ft_place_int_right(long long n, t_specs specs)
{
	char	fill;
	int		ret;

	ret = 0;
	if (specs.hh == 1)
		n = (signed char)n;
	if (specs.h == 1)
		n = (short)n;
	fill = ' ';
	if (specs.zero == 1)
		fill = '0';
	if (specs.space == 1)
	{
		write(1, " ", 1);
		ret++;
	}
	ft_shmatok(specs, &ret, fill, n);
	if (n < 0)
		n = -n;
	if (!(specs.acc_flag == 1 && specs.accuracy == 0 && n == 0))
		ft_do_magic(n, &ret);
	return (ret);
}
