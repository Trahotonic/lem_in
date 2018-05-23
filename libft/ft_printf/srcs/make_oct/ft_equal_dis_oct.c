/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equal_dis_oct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:27:50 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/10 16:27:50 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

void		ft_equal_dis_oct(t_specs *specs, unsigned long long n)
{
	char	*num;

	if (specs->hh == 1)
		n = (unsigned char)n;
	if (specs->h == 1)
		n = (unsigned short)n;
	if (specs->leftside == 1 || specs->acc_flag == 1)
		specs->zero = 0;
	num = ft_itoa_base(n, 8);
	if (specs->plus == 1)
		specs->plus = 0;
	if (n == 0 && specs->acc_flag == 0)
		specs->hash = 0;
	specs->accuracy -= ft_strlen(num) + specs->hash;
	if (specs->accuracy < 0)
		specs->accuracy = 0;
	if (!(specs->acc_flag == 1 && specs->accuracy == 0 && n == 0))
		specs->width -= (specs->accuracy + ft_strlen(num) + specs->hash);
	if (specs->space == 1)
		specs->space = 0;
	free(num);
}
