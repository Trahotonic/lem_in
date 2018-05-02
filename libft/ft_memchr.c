/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:47:44 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/13 17:00:10 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;
	size_t				count;

	str = (unsigned char*)s;
	count = 0;
	while (count < n)
	{
		if (*str == (unsigned char)c)
		{
			return (str);
		}
		str++;
		count++;
	}
	return (NULL);
}
