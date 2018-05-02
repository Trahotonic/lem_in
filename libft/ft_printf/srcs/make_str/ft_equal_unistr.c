/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equal_unistr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:06:31 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/19 13:06:31 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static int		ft_get_wchr_bytes(wchar_t *str)
{
	size_t		n;
	int			len;

	n = 0;
	len = 0;
	while (str[n] != '\0')
	{
		if (str[n] <= 127)
			len += 1;
		else if (str[n] > 127 && str[n] <= 2047)
			len += 2;
		else if (str[n] > 2047 && str[n] <= 65535)
			len += 3;
		else
			len += 4;
		n++;
	}
	return (len);
}

static int		ft_get_acc_size(wchar_t *str, int accuracy)
{
	size_t		n;
	int			ret;
	int			tmp;

	n = 0;
	ret = 0;
	while (ret <= accuracy)
	{
		tmp = 0;
		if (str[n] <= 127)
			tmp += 1;
		else if (str[n] > 127 && str[n] <= 2047)
			tmp += 2;
		else if (str[n] > 2047 && str[n] <= 65535)
			tmp += 3;
		else
			tmp += 4;
		if (ret + tmp <= accuracy)
			ret += tmp;
		else
			break ;
	}
	return (ret);
}

static wchar_t	*ft_check(wchar_t *str, t_specs *specs)
{
	if (str == NULL)
		str = L"(null)";
	if (specs->leftside == 1)
		specs->zero = 0;
	return (str);
}

void			ft_equal_unistr(t_specs *specs, wchar_t *str)
{
	int			len;

	str = ft_check(str, specs);
	len = ft_get_wchr_bytes(str);
	if (str != NULL)
	{
		if (specs->acc_flag == 1)
		{
			if (specs->accuracy > len)
				specs->accuracy = len;
			specs->width -= ft_get_acc_size(str, specs->accuracy);
		}
		else
			specs->width -= len;
	}
	else
	{
		if (specs->accuracy > 6)
			specs->accuracy = 6;
		if (specs->acc_flag == 1)
			specs->width -= specs->accuracy;
		else
			specs->width -= 6;
	}
}
