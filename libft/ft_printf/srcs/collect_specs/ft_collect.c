/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:25:45 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/10 16:25:47 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static void	ft_forstar(va_list ptr, t_specs *specs)
{
	long	forstar;

	forstar = va_arg(ptr, int);
	if (forstar < 0)
	{
		forstar = -forstar;
		specs->leftside = 1;
	}
	specs->width = forstar;
}

static char	*ft_for_l(char *format, t_specs *specs)
{
	specs->l = 1;
	format++;
	if (*format == 'l')
	{
		specs->ll = 1;
		specs->l = 0;
	}
	format--;
	return (format);
}

static char	*ft_for_h(char *format, t_specs *specs)
{
	specs->h = 1;
	specs->hh = 0;
	format++;
	if (*format == 'h')
	{
		specs->hh = 1;
		specs->h = 0;
		format++;
	}
	format--;
	return (format);
}

static void	ft_for_rest(char *format, t_specs *specs)
{
	if (*format == '+')
		specs->plus = 1;
	else if (*format == ' ')
		specs->space = 1;
	else if (*format == '#')
		specs->hash = 1;
	else if (*format == 'z')
		specs->z = 1;
	else if (*format == 'j')
		specs->j = 1;
}

char		*ft_collect(char *format, t_specs *specs, va_list ptr)
{
	while (*format != '\0' && *format != 'd' && *format != 'c'
		&& *format != 's' && *format != 'x' && *format != 'X'
		&& *format != 'o' && *format != 'i' && *format != '%'
		&& *format != 'u')
	{
		if (ft_check_invalid(format))
			return (format);
		if (*format == '-' && specs->leftside == 0)
			specs->leftside = 1;
		else if (ft_isdigit(*format))
			format = ft_get_width(format, specs);
		else if (*format == '.')
			format = ft_check_acc(format, specs, ptr);
		else if (*format == '*')
			ft_forstar(ptr, specs);
		else if (*format == 'l')
			format = ft_for_l(format, specs);
		else if (*format == 'h')
			format = ft_for_h(format, specs);
		ft_for_rest(format, specs);
		format++;
	}
	return (format);
}
