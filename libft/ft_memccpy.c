/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:49:32 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/03 12:42:37 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	while (n > 0)
	{
		if (*s == (unsigned char)c)
		{
			*d = *s;
			return (++d);
		}
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (NULL);
}
