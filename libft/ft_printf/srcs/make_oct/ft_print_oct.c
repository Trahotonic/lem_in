/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:28:37 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/10 16:28:38 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

int	ft_print_oct(unsigned long long n, t_specs specs)
{
	ft_equal_dis_oct(&specs, n);
	if (specs.leftside == 1)
		return (ft_place_oct_left(n, specs));
	else
		return (ft_place_oct_right(n, specs));
}
