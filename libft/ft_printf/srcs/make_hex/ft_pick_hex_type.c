/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_hex_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:02:08 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/11 15:02:09 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static void	ft_silence(t_specs *specs)
{
	specs->hh = 0;
	specs->h = 0;
	specs->l = 0;
	specs->ll = 0;
	specs->j = 0;
}

static void	ft_king_of_the_hill(t_specs *specs)
{
	if (specs->hh == 1)
		specs->h = 0;
	if (specs->l == 1)
	{
		specs->h = 0;
		specs->hh = 0;
	}
	if (specs->ll == 1)
	{
		specs->h = 0;
		specs->hh = 0;
	}
	if (specs->j == 1)
	{
		specs->h = 0;
		specs->hh = 0;
		specs->l = 0;
		specs->ll = 0;
	}
	if (specs->z == 1)
	{
		ft_silence(specs);
		specs->z = 1;
	}
}

int			ft_pick_hex_type(t_specs specs, va_list ptr, char x)
{
	ft_king_of_the_hill(&specs);
	if (specs.l == 1)
		return (ft_print_hex(va_arg(ptr, unsigned long), specs, x));
	else if (specs.ll == 1)
		return (ft_print_hex(va_arg(ptr, unsigned long long), specs, x));
	else if (specs.h == 1)
		return (ft_print_hex(va_arg(ptr, unsigned int), specs, x));
	else if (specs.hh == 1)
		return (ft_print_hex(va_arg(ptr, unsigned int), specs, x));
	else if (specs.j == 1)
		return (ft_print_hex(va_arg(ptr, uintmax_t), specs, x));
	else if (specs.z == 1)
		return (ft_print_hex(va_arg(ptr, size_t), specs, x));
	else
		return (ft_print_hex(va_arg(ptr, unsigned int), specs, x));
}
