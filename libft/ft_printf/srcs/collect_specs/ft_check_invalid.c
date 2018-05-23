/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_invalid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:25:30 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/10 16:25:32 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

int		ft_check_invalid(char *format)
{
	if (*format != '+' && *format != '-' && *format != '_' &&
		*format != '#' && *format != ' ' && *format != '.' &&
		!ft_isdigit(*format) && *format != '*' && *format != 'l'
		&& *format != 'h' && *format != 'z' && *format != 'j')
		return (1);
	return (0);
}
