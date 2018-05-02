/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equal_dis_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:31:50 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/12 14:31:50 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

void	ft_equal_dis_str(t_specs *specs, char *str)
{
	if (specs->leftside == 1)
		specs->zero = 0;
	if (str != NULL)
	{
		if (specs->accuracy > (int)ft_strlen(str))
			specs->accuracy = ft_strlen(str);
		if (specs->acc_flag == 1)
			specs->width -= specs->accuracy;
		else
			specs->width -= ft_strlen(str);
	}
	else
	{
		if (specs->accuracy > 6)
			specs->accuracy = 6;
		if (specs->acc_flag == 1)
			specs->width -= specs->accuracy;
		else
			specs->width -= 6;
	}
}
