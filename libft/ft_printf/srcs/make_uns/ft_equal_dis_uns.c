/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equal_dis_uns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:08:15 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/11 18:08:17 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static int	ft_siz(unsigned long long n)
{
	int		m;

	m = 1;
	while (n >= 10)
	{
		n /= 10;
		m++;
	}
	return (m);
}

void		ft_equal_dis_uns(t_specs *specs, unsigned long long n)
{
	if (specs->hh == 1)
		n = (unsigned char)n;
	if (specs->h == 1)
		n = (unsigned short)n;
	if (specs->leftside == 1 || specs->acc_flag == 1)
		specs->zero = 0;
	specs->accuracy -= ft_siz(n);
	if (specs->accuracy < 0)
		specs->accuracy = 0;
	specs->width -= (specs->accuracy + ft_siz(n));
	if (specs->plus == 1 && specs->space == 1)
		specs->space = 0;
}
