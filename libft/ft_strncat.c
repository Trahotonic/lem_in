/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:37:56 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/10/30 14:54:42 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	m;

	i = 0;
	m = 0;
	while (dest[m] != '\0')
		m++;
	while (i < n && src[i] != '\0')
	{
		dest[m] = src[i];
		m++;
		i++;
	}
	dest[m] = '\0';
	return (dest);
}
