/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:27:33 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/10 16:27:33 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

int	ft_print_hex(unsigned long long n, t_specs specs, char x)
{
	ft_equal_dis_hex(&specs, n);
	if (specs.leftside == 1)
		return (ft_place_hex_left(n, specs, x));
	else
		return (ft_place_hex_right(n, specs, x));
}
