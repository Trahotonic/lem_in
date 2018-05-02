/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:45:52 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/10/27 12:01:04 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	n;
	size_t	m;
	char	*ret;

	n = 0;
	m = 0;
	while (s[n] != '\0')
		n++;
	if (!(ret = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	else
	{
		while (m < n)
		{
			ret[m] = s[m];
			m++;
		}
		ret[m] = '\0';
		return (ret);
	}
}
