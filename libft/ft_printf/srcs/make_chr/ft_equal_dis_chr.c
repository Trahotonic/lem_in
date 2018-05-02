/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equal_dis_chr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:41:50 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/12 18:41:51 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

void	ft_equal_dis_chr(t_specs *specs, unsigned int c)
{
	if (specs->leftside == 1)
		specs->zero = 0;
	if (MB_CUR_MAX != 1)
	{
		if (c <= 127)
			specs->width -= 1;
		else if (c > 127 && c <= 2047)
			specs->width -= 2;
		else if (c > 2047 && c <= 65535)
			specs->width -= 3;
		else
			specs->width -= 4;
	}
	else
		specs->width -= 1;
}
