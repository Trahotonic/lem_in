/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:14:34 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/19 13:14:35 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

static int	ft_check_x(char *str)
{
	size_t n;

	n = 0;
	while (str[n] != '\0')
		if (str[n++] == 'x')
			return (1);
	return (0);
}

static void	ft_place_right(char *bin, char x)
{
	size_t n;

	n = 7;
	while (n > 0)
	{
		if (bin[n] == 'x')
		{
			bin[n] = x;
			return ;
		}
		n--;
	}
}

static void	ft_x_to_zero(char *bin)
{
	size_t n;

	n = 0;
	while (bin[n] != '\0')
	{
		if (bin[n] == 'x')
			bin[n] = '0';
		n++;
	}
}

char		**ft_make_do(char *bin, char **arr, int pointer)
{
	size_t	n;
	int		ptr;

	ptr = pointer;
	n = ft_strlen(bin);
	while (n > 0)
	{
		if (!ft_check_x(arr[ptr]))
			ptr--;
		ft_place_right(arr[ptr], bin[n - 1]);
		n--;
	}
	ft_x_to_zero(arr[ptr]);
	return (arr);
}
