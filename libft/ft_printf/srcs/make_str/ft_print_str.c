/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:33:32 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/12 14:33:32 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

int	ft_print_str(char *str, t_specs specs)
{
	ft_equal_dis_str(&specs, str);
	if (specs.leftside == 1)
		return (ft_place_str_left(str, specs));
	else
		return (ft_place_str_right(str, specs));
}
