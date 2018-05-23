/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_inval_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:47:46 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/19 12:47:46 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

void	ft_put_inval_width(int width, int zero)
{
	int		n;
	char	fill;

	n = 0;
	fill = ' ';
	if (zero == 1)
		fill = '0';
	while (n < width - 1)
	{
		write(1, &fill, 1);
		n++;
	}
}
