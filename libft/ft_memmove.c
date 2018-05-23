/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:12:44 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/03 14:04:09 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	if (d == s)
		return (dest);
	else if (d > s)
	{
		d = d + n - 1;
		s = s + n - 1;
		while (n > 0)
		{
			*d-- = *s--;
			n--;
		}
		return (dest);
	}
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}
