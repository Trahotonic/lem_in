/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:15:09 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/14 10:55:26 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n < ft_strlen(dest))
		return (ft_strlen(src) + n);
	else
	{
		while (dest[i] != '\0')
		{
			i++;
		}
		while (i < n - 1 && *src)
		{
			dest[i] = *src;
			src++;
			i++;
		}
		dest[i] = '\0';
		return (ft_strlen(dest) + ft_strlen(src));
	}
}
