/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:24:07 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/10 16:24:08 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static void	ft_add(t_pozor *vars, int base)
{
	while (vars->backup != 0)
	{
		vars->tmp[vars->ptr--] = vars->array[vars->backup % base];
		vars->backup /= base;
		vars->size++;
	}
}

char		*ft_itoa_base(long long value, int base)
{
	t_pozor vars;

	vars.minus = 0;
	if (value == 0)
		return (ft_go_zero());
	if (value < 0 && base == 10)
	{
		vars.minus = 1;
		vars.backup = -value;
	}
	else
		vars.backup = value;
	vars.array = "0123456789ABCDEF";
	vars.size = 0;
	vars.ptr = 59;
	ft_add(&vars, base);
	vars.ptr++;
	vars.ret = (char*)malloc(sizeof(char) * (vars.size + 1 + vars.minus));
	vars.size = 0;
	while (vars.ptr <= 59)
		vars.ret[vars.size++] = vars.tmp[vars.ptr++];
	vars.ret[vars.size] = '\0';
	return (vars.ret);
}
