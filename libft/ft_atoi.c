/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:06:19 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/06 14:56:12 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoi(const char *nptr)
{
	long long n;
	long long m;
	long long minus;

	n = 0;
	m = 0;
	minus = 0;
	while (nptr[n] == ' ' || nptr[n] == '\t' || nptr[n] == '\n' ||
			nptr[n] == '\f' || nptr[n] == '\v' || nptr[n] == '\r')
		n++;
	if (nptr[n] == '-')
		minus = 1;
	if (nptr[n] == '-' || nptr[n] == '+')
		n++;
	while (nptr[n] >= '0' && nptr[n] <= '9')
	{
		m = m * 10 + (nptr[n] - '0');
		n++;
	}
	if (minus == 1)
		return (-m);
	else
		return (m);
}
