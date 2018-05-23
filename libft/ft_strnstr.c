/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:44:11 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/17 14:16:17 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lrunner;
	size_t	brunner;

	if (little[0] == '\0')
		return ((char*)big);
	brunner = 0;
	while (big[brunner] != '\0' && brunner <= len)
	{
		if (big[brunner] == little[0])
		{
			lrunner = 0;
			while (little[lrunner] == big[brunner] && brunner <= len)
			{
				if (little[lrunner + 1] == '\0' && brunner < len)
					return ((char*)&big[brunner - lrunner]);
				lrunner++;
				brunner++;
			}
			brunner -= lrunner;
		}
		brunner++;
	}
	return (NULL);
}
