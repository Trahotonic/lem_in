/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:25:38 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/20 12:44:25 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		count;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (char*)dest;
	s = (const char*)src;
	count = 0;
	while (count < n)
	{
		d[count] = s[count];
		count++;
	}
	return (d);
}
