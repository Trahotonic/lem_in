/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:29:01 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/10 16:29:02 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prlib.h"

static int			ft_check_valid_sp(char c)
{
	if (c == '%' || c == 'd' || c == 'D' || c == 'i' || c == 'x' || c == 'X' ||
		c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'p' || c == 's' ||
		c == 'S' || c == 'c' || c == 'C')
		return (1);
	return (0);
}

static char			*ft_do_inval(char *f, int *ret, int *fl, t_specs sp)
{
	*fl = 1;
	if (*f != '\0')
	{
		*ret = ft_for_inval_wid(f, sp, *ret);
		f++;
	}
	sp = ft_peace_maker();
	return (f);
}

static char			*ft_lil_shit(char *format, int *ret, int flag)
{
	if (*format != '%' && *format != '\0' && flag == 0)
	{
		write(1, &*format, 1);
		*ret += 1;
		format++;
	}
	return (format);
}

static void			*ft_for_valid(char *f, int *ret, t_specs sp, va_list ptr)
{
	*ret += ft_pick_func(*f, sp, ptr);
	f++;
	sp = ft_peace_maker();
	return (f);
}

int					ft_printf(char *format, ...)
{
	int		ret;
	t_specs	specs;
	va_list	(ptr);

	ret = 0;
	specs = ft_peace_maker();
	va_start(ptr, format);
	if (ft_check_sc(format, &specs, ptr))
		return (ft_break(ptr, ret));
	while (*format != '\0')
	{
		specs.flag = 0;
		if (*format == '%')
		{
			format = ft_collect(format + 1, &specs, ptr);
			if (ft_check_valid_sp(*format))
				format = ft_for_valid(format, &ret, specs, ptr);
			else
				format = ft_do_inval(format, &ret, &specs.flag, specs);
			if (ft_check_sc(format, &specs, ptr))
				break ;
		}
		format = ft_lil_shit(format, &ret, specs.flag);
	}
	return (ft_break(ptr, ret));
}
