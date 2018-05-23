/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_uns_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:09:40 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/11 18:09:41 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static void	ft_place_acc_wid(t_specs specs, char fill, int *ret)
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
	while (count < specs.accuracy)
	{
		write(1, "0", 1);
		count++;
		*ret += 1;
	}
}

int			ft_place_uns_right(unsigned long long n, t_specs specs)
{
	int		count;
	char	fill;
	char	*str;
	int		ret;

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
	ft_place_acc_wid(specs, fill, &ret);
	if (!(specs.acc_flag == 1 && specs.accuracy == 0 && n == 0))
	{
		str = ft_uitoa_base(n, 10);
		ft_putstr(str);
		ret += ft_strlen(str);
		free(str);
	}
	return (ret);
}
