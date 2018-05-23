/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:50:40 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/03 18:00:18 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	n;

	n = 0;
	while (s1[n] == s2[n])
	{
		if (s1[n] == '\0' && s2[n] == '\0')
			return (0);
		n++;
	}
	return ((unsigned char)s1[n] - (unsigned char)s2[n]);
}
