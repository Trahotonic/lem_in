/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:42:48 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/12 18:42:49 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

int	ft_print_chr(unsigned int c, t_specs specs, char uni)
{
	ft_equal_dis_chr(&specs, c);
	if (specs.leftside == 1)
		return (ft_place_chr_left(c, specs, uni));
	else
		return (ft_place_chr_right(c, specs, uni));
}
