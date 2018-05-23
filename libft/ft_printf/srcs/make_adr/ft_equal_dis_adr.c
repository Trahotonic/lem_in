/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equal_dis_adr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:52:16 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/12 13:52:17 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

void	ft_equal_dis_adr(t_specs *specs, unsigned long long n)
{
	char	*num;

	if (specs->leftside == 1 || specs->acc_flag == 1)
		specs->zero = 0;
	num = ft_itoa_base(n, 16);
	if (specs->plus == 1)
		specs->plus = 0;
	specs->accuracy -= ft_strlen(num);
	if (specs->accuracy < 0)
		specs->accuracy = 0;
	specs->width -= (specs->accuracy + ft_strlen(num) + (2));
	if (specs->space == 1)
		specs->space = 0;
	free(num);
}
