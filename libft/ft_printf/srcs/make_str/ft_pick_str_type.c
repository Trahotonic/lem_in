/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_str_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:32:48 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/12 14:32:49 by rkyslyy          ###   ########.fr       */
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
		specs->l = 0;
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

int			ft_pick_str_type(t_specs specs, va_list ptr, char s)
{
	ft_king_of_the_hill(&specs);
	if ((s == 'S' || specs.l == 1) && (MB_CUR_MAX != 1 || specs.permis == 1))
		return (ft_print_unistr(specs.str, specs));
	else
		return (ft_print_str(va_arg(ptr, char*), specs));
}
