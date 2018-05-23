/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:02:12 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/14 17:02:50 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_filler(unsigned int work, int m, int minus, char *ret)
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
