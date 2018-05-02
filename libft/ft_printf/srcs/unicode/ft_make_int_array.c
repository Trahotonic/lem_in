/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_int_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:12:49 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/19 13:12:49 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

int		*ft_make_int_array(char **list, int size)
{
	int	*ret;
	int count;

	ret = (int*)malloc(sizeof(int) * size);
	count = 0;
	while (count < size)
	{
		ret[count] = ft_btoi(list[count]);
		count++;
	}
	return (ret);
}
