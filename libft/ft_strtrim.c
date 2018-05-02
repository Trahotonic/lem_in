/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:13:03 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/07 16:35:25 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strtrim(char const *s)
{
	char				*ret;
	int					n;
	unsigned int		c;
	int					k;

	if (s)
	{
		n = 0;
		k = 0;
		while (s[n] == ' ' || s[n] == '\t' || s[n] == '\n')
			n++;
		c = ft_strlen(s);
		while ((s[c] == ' ' || s[c] == '\t' || s[c] == '\n' || s[c] == '\0')
				&& c != 0)
			c--;
		c -= (unsigned int)n;
		if (!(ret = (char*)malloc(sizeof(char) * (c + 2))))
			return (NULL);
		while (k <= (int)c && (int)c != 0)
			ret[k++] = s[n++];
		ret[k] = '\0';
		return (ret);
	}
	return (NULL);
}
