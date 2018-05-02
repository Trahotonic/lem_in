/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:52:05 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/06 17:58:37 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	n;
	size_t	m;
	char	*ret;

	if (s && f)
	{
		n = 0;
		m = 0;
		while (s[n] != '\0')
			n++;
		ret = (char*)malloc(sizeof(char) * (n + 1));
		if (ret)
		{
			while (m < n)
			{
				ret[m] = f(s[m]);
				m++;
			}
			ret[m] = '\0';
			return (ret);
		}
	}
	return (NULL);
}
