/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:09:46 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/11 18:09:47 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

int		ft_print_uns(unsigned long long n, t_specs specs)
{
	ft_equal_dis_uns(&specs, n);
	if (specs.leftside == 1)
		return (ft_place_uns_left(n, specs));
	else
		return (ft_place_uns_right(n, specs));
}
