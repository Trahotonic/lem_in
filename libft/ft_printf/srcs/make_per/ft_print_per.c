/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 12:32:08 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/16 12:32:13 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

int	ft_print_per(t_specs specs)
{
	ft_equal_dis_per(&specs);
	if (specs.leftside == 1)
		return (ft_place_per_left(specs));
	else
		return (ft_place_per_right(specs));
}
