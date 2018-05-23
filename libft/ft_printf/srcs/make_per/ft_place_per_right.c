/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_per_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 12:31:59 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/16 12:32:00 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

int			ft_place_per_right(t_specs specs)
{
	int		count;
	int		ret;
	char	fill;

	count = 0;
	ret = 0;
	fill = ' ';
	if (specs.zero == 1)
		fill = '0';
	while (count < specs.width)
	{
		ft_putchar(fill);
		count++;
		ret++;
	}
	ft_putchar('%');
	ret++;
	return (ret);
}
