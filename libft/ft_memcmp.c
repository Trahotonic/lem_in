/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 21:05:47 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/13 16:59:00 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				count;
	unsigned char		*s;
	unsigned char		*d;

	count = 0;
	s = (unsigned char*)s1;
	d = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (s[count] == d[count])
	{
		if (count == n - 1 || n == 0)
			return (0);
		count++;
	}
	return (s[count] - d[count]);
}
