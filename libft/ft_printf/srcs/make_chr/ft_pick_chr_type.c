/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_chr_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:42:04 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/12 18:42:04 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

int		ft_pick_chr_type(t_specs specs, va_list ptr, char c)
{
	int	x;

	if (c == 'C' || (c == 'c' && specs.l == 1))
		x = specs.c;
	else
		x = va_arg(ptr, int);
	return (ft_print_chr(x, specs, c));
}
