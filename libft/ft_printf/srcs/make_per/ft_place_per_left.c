/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_per_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 12:31:50 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/16 12:31:51 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

int		ft_place_per_left(t_specs specs)
{
	int	count;
	int	ret;

	count = 0;
	ret = 0;
	ft_putchar('%');
	ret++;
	while (count < specs.width)
	{
		ft_putchar(' ');
		count++;
		ret++;
	}
	return (ret);
}
