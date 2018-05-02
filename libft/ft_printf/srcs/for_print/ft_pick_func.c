/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:48:20 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/19 12:48:20 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

int	ft_pick_func(char c, t_specs specs, va_list ptr)
{
	if (c == '%')
		return (ft_print_per(specs));
	else if (c == 'd' || c == 'D' || c == 'i')
		return (ft_pick_int_type(specs, ptr, c));
	else if (c == 'x' || c == 'X')
		return (ft_pick_hex_type(specs, ptr, c));
	else if (c == 'o' || c == 'O')
		return (ft_pick_oct_type(specs, ptr, c));
	else if (c == 'u' || c == 'U')
		return (ft_pick_uns_type(specs, ptr, c));
	else if (c == 'p')
		return (ft_print_adr(va_arg(ptr, unsigned long long), specs));
	else if (c == 's' || c == 'S')
		return (ft_pick_str_type(specs, ptr, c));
	else if (c == 'c' || c == 'C')
		return (ft_pick_chr_type(specs, ptr, c));
	return (0);
}
