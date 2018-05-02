/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:53:39 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/12 13:53:40 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

int	ft_print_adr(unsigned long long n, t_specs specs)
{
	ft_equal_dis_adr(&specs, n);
	if (specs.leftside == 1)
		return (ft_place_adr_left(n, specs));
	else
		return (ft_place_adr_right(n, specs));
}
