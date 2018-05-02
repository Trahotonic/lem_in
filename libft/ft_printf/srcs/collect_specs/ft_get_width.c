/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:25:11 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/10 16:25:11 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

char	*ft_get_width(char *format, t_specs *specs)
{
	int	get;

	if (*format == '0' && specs->zero == 0 && specs->digit_flag == 0)
		specs->zero = 1;
	if (specs->digit_flag == 0)
		specs->digit_flag = 1;
	get = ft_smoker_atoi(format);
	if (get != 0)
		specs->width = get;
	while (ft_isdigit(*format))
		format++;
	format -= 1;
	return (format);
}
