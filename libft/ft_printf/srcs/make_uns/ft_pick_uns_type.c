/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_uns_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:08:50 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/11 18:08:51 by rkyslyy          ###   ########.fr       */
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

int			ft_pick_uns_type(t_specs specs, va_list ptr, char u)
{
	if (u == 'U')
	{
		ft_silence(&specs);
		return (ft_print_uns(va_arg(ptr, unsigned long long), specs));
	}
	ft_king_of_the_hill(&specs);
	if (specs.l == 1)
		return (ft_print_uns(va_arg(ptr, unsigned long), specs));
	else if (specs.ll == 1)
		return (ft_print_uns(va_arg(ptr, unsigned long long), specs));
	else if (specs.h == 1)
		return (ft_print_uns(va_arg(ptr, unsigned int), specs));
	else if (specs.hh == 1)
		return (ft_print_uns(va_arg(ptr, unsigned int), specs));
	else if (specs.j == 1)
		return (ft_print_uns(va_arg(ptr, uintmax_t), specs));
	else if (specs.z == 1)
		return (ft_print_uns(va_arg(ptr, size_t), specs));
	else
		return (ft_print_uns(va_arg(ptr, unsigned int), specs));
}
