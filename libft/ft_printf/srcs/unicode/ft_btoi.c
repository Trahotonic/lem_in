/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:14:00 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/19 13:14:00 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

int		ft_btoi(char *bin)
{
	size_t	n;
	int		ret;
	int		plus;

	ret = 0;
	plus = 1;
	n = ft_strlen(bin);
	while (n > 0)
	{
		if (bin[n - 1] == '1')
			ret += plus;
		plus *= 2;
		n--;
	}
	return (ret);
}
