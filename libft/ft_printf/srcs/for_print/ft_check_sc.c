/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:47:31 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/19 12:47:31 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static int	ft_shmatok(va_list ptr, char *format, int l, t_specs *specs)
{
	size_t	n;

	n = 0;
	if (*format == 'C' || (*format == 'c' && l % 2 != 0))
	{
		specs->c = va_arg(ptr, wchar_t);
		if (specs->c > 255 && MB_CUR_MAX == 1)
			return (1);
		return (0);
	}
	else if (*format == 'S' || (*format == 's' && l % 2 != 0))
	{
		specs->str = va_arg(ptr, wchar_t*);
		while (specs->str != NULL && specs->str[n] != '\0')
		{
			if (specs->str[n] > 256 && MB_CUR_MAX == 1)
				return (1);
			n++;
		}
		specs->permis = 1;
		return (0);
	}
	else
		return (0);
}

int			ft_check_sc(char *format, t_specs *specs, va_list ptr)
{
	int		l;

	l = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			while (!ft_check_invalid(format) &&
				*format != 's' && *format != 'c')
			{
				if (*format == 'l')
					l += 1;
				format++;
			}
			return (ft_shmatok(ptr, format, l, specs));
		}
		format++;
	}
	return (0);
}
