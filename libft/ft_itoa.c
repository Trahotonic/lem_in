/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:44:10 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/09 18:47:09 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(unsigned int n)
{
	int m;

	m = 1;
	while (n >= 10)
	{
		n /= 10;
		m++;
	}
	return (m);
}

static void	ft_filler(unsigned int work, int m, int minus, char *ret)
{
	while (work >= 10)
	{
		ret[m-- + minus] = work % 10 + '0';
		work /= 10;
	}
	ret[m-- + minus] = work % 10 + '0';
	if (minus == 1)
		ret[m + minus] = '-';
}

char		*ft_itoa(long long n)
{
	int				m;
	int				minus;
	unsigned int	work;
	char			*ret;

	minus = 0;
	if (n < 0)
	{
		work = -n;
		minus = 1;
	}
	else
		work = n;
	m = ft_size(work);
	if (!(ret = (char*)malloc(sizeof(char) * (m + 1 + minus))))
		return (NULL);
	ret[m-- + minus] = '\0';
	ft_filler(work, m, minus, ret);
	return (ret);
}
