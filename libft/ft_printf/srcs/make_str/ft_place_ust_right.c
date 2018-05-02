/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_ust_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:43:43 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/16 18:43:43 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static int	ft_get_wchr_bytes(wchar_t *str)
{
	size_t	n;
	int		len;

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

static void	ft_permis(wchar_t c, int *ret, int tmp)
{
	if (c > 256)
		ft_print_uni(c);
	else
		write(1, &c, 1);
	*ret += tmp;
}

static void	ft_for_acc(int *count, t_specs specs, wchar_t *str, int *ret)
{
	size_t	n;
	int		tmp;

	n = 0;
	*count = 0;
	while (*count < specs.accuracy)
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
		*count += tmp;
		if (*count <= specs.accuracy)
			ft_permis(str[n], ret, tmp);
		n++;
	}
}

static void	ft_do_magic(int *ret, wchar_t *str)
{
	size_t	count;

	count = 0;
	*ret += ft_get_wchr_bytes(str);
	if (MB_CUR_MAX != 1)
		ft_place_uni(str);
	else
	{
		while (str[count] != '\0')
			write(1, &str[count++], 1);
	}
}

int			ft_place_ust_right(wchar_t *str, t_specs specs)
{
	int		count;
	int		ret;
	char	fill;

	if (str == NULL)
		str = L"(null)";
	count = 0;
	ret = 0;
	fill = ' ';
	if (specs.zero == 1)
		fill = '0';
	while (count < specs.width)
	{
		write(1, &fill, 1);
		count++;
		ret++;
	}
	if (specs.acc_flag == 1)
		ft_for_acc(&count, specs, str, &ret);
	else
		ft_do_magic(&ret, str);
	return (ret);
}
