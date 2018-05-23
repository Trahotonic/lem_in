/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:26:17 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/14 10:22:26 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnew(size_t size)
{
	char		*ret;
	size_t		n;

	ret = (char*)malloc(sizeof(char) * (size + 1));
	if (ret)
	{
		n = 0;
		while (n <= size)
		{
			ret[n] = '\0';
			n++;
		}
		return (ret);
	}
	return (NULL);
}
