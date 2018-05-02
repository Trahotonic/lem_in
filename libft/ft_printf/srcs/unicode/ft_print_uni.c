/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uni.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:14:46 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/19 13:14:47 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

void		ft_print_uni(int n)
{
	int		*array;
	char	*bin;
	int		size;
	int		count;

	bin = ft_itoa_base(n, 2);
	if (ft_strlen(bin) >= 8 && ft_strlen(bin) <= 11)
	{
		array = ft_make_int_array(ft_make_do(bin, ft_create_mask(2), 1), 2);
		size = 2;
	}
	else if (ft_strlen(bin) >= 12 && ft_strlen(bin) <= 16)
	{
		array = ft_make_int_array(ft_make_do(bin, ft_create_mask(3), 2), 3);
		size = 3;
	}
	else
	{
		array = ft_make_int_array(ft_make_do(bin, ft_create_mask(4), 3), 4);
		size = 4;
	}
	count = 0;
	while (count < size)
		write(1, &array[count++], 1);
}
