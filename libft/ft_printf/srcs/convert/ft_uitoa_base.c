/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:53:28 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/11 17:53:28 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

char		*ft_uitoa_base(unsigned long long value, int base)
{
	char	*array;
	char	tmp[60];
	char	*ret;
	int		size;
	int		ptr;

	if (value == 0)
		return (ft_go_zero());
	array = "0123456789ABCDEF";
	size = 0;
	ptr = 59;
	while (value != 0)
	{
		tmp[ptr--] = array[value % base];
		value /= base;
		size++;
	}
	ptr++;
	ret = (char*)malloc(sizeof(char) * (size + 1));
	size = 0;
	while (ptr <= 59)
		ret[size++] = tmp[ptr++];
	ret[size] = '\0';
	return (ret);
}
