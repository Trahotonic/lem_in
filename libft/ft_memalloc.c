/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:13:50 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/06 16:24:58 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ret;
	size_t	n;

	if (size > 0)
	{
		n = 0;
		ret = (char*)malloc(sizeof(char) * size);
		if (ret != NULL)
		{
			while (n < size)
			{
				ret[n] = 0;
				n++;
			}
			return (ret);
		}
	}
	return (0);
}
