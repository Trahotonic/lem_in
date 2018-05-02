/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:59:52 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/06 18:00:54 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				ret[m] = f(m, s[m]);
				m++;
			}
			ret[m] = '\0';
			return (ret);
		}
	}
	return (NULL);
}
