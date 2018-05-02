/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unistr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:38:52 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/16 18:38:52 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

int	ft_print_unistr(wchar_t *str, t_specs specs)
{
	ft_equal_unistr(&specs, str);
	if (specs.leftside == 1)
		return (ft_place_ust_left(str, specs));
	else
		return (ft_place_ust_right(str, specs));
}
