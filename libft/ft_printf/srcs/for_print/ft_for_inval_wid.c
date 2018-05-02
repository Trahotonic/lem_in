/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_inval_wid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:49:24 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/19 12:49:25 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

int	ft_for_inval_wid(char *format, t_specs specs, int ret)
{
	if (specs.width > 1 && specs.leftside == 0)
		ft_put_inval_width(specs.width, specs.zero);
	write(1, &*format, 1);
	if (specs.width > 1 && specs.leftside == 1)
		ft_put_inval_width(specs.width, specs.zero);
	ret += 1;
	if (specs.width > 0)
		ret += specs.width - 1;
	return (ret);
}
