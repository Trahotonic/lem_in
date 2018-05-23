/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:42:22 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/17 14:23:35 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t lrunner;
	size_t brunner;

	brunner = 0;
	if (little[0] == '\0')
		return ((char*)&big[0]);
	while (big[brunner] != '\0')
	{
		if (big[brunner] == little[0])
		{
			lrunner = 0;
			while (little[lrunner] == big[brunner])
			{
				if (little[lrunner + 1] == '\0')
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
