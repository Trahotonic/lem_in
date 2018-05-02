/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_uns_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:09:30 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/11 18:09:31 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static void	ft_do_magic(t_specs specs, int *ret, unsigned long long n)
{
	int		count;
	char	*str;

	str = NULL;
	count = 0;
	while (count < specs.accuracy)
	{
		write(1, "0", 1);
		count++;
		*ret += 1;
	}
	if (!(specs.acc_flag == 1 && specs.accuracy == 0 && n == 0))
	{
		str = ft_uitoa_base(n, 10);
		ft_putstr(str);
		*ret += ft_strlen(str);
		free(str);
	}
}

int			ft_place_uns_left(unsigned long long n, t_specs specs)
{
	int		count;
	int		ret;

	ret = 0;
	if (specs.hh == 1)
		n = (unsigned char)n;
	if (specs.h == 1)
		n = (unsigned short)n;
	ft_do_magic(specs, &ret, n);
	count = 0;
	while (count < specs.width)
	{
		write(1, " ", 1);
		count++;
		ret++;
	}
	return (ret);
}
