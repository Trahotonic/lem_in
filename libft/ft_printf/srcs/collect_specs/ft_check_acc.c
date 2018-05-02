/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_acc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:25:19 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/10 16:25:19 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static char	*ft_forstar(char *format, t_specs *specs, int forstar, va_list ptr)
{
	forstar = va_arg(ptr, int);
	if (forstar < 0)
	{
		specs->acc_flag = 0;
		return (format);
	}
	specs->accuracy = forstar;
	return (format);
}

char		*ft_check_acc(char *format, t_specs *specs, va_list ptr)
{
	int		acc;
	long	forstar;

	forstar = 0;
	specs->acc_flag = 1;
	format += 1;
	acc = 0;
	if (*format == '*')
		return (ft_forstar(format, specs, forstar, ptr));
	if (ft_isdigit(*format))
	{
		acc = ft_smoker_atoi(format);
		specs->accuracy = acc;
		while (ft_isdigit(*format))
			format++;
		format -= 1;
		return (format);
	}
	specs->accuracy = acc;
	format -= 1;
	return (format);
}
