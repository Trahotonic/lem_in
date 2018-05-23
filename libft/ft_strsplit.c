/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:49:27 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/14 12:59:38 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wl(char const *s, int start, char c)
{
	int		n;

	n = 0;
	while (s[start] != '\0' && s[start] != c)
	{
		start++;
		n++;
	}
	return (n);
}

static size_t	ft_wc(char const *s, char c)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (s[n] != '\0')
	{
		if (n == 0 && s[n] != c)
			i++;
		if (s[n] == c && s[n + 1] != c && s[n + 1] != '\0')
			i++;
		n++;
	}
	return (i);
}

static size_t	ft_ch(char const *s, int start, char c)
{
	int		n;

	n = 0;
	while (s[start] != '\0' && s[start] == c)
	{
		start++;
		n++;
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	n;
	size_t	m;
	size_t	l;
	char	**ret;

	if (s)
	{
		n = 0;
		m = 0;
		if (!(ret = (char**)malloc(sizeof(char*) * (ft_wc(s, c) + 1))))
			return (NULL);
		while (s[n] != '\0' && n + ft_ch(s, n, c) < ft_strlen(s))
		{
			l = 0;
			while (s[n] == c)
				n++;
			ret[m] = (char*)malloc(sizeof(char) * (ft_wl((char*)s, n, c) + 1));
			while (s[n] != c && s[n] != '\0')
				ret[m][l++] = s[n++];
			ret[m++][l] = '\0';
		}
		ret[m] = 0;
		return (ret);
	}
	return (NULL);
}
