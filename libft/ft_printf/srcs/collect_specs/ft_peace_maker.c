/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peace_maker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:24:54 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/10 16:24:54 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

t_specs	ft_peace_maker(void)
{
	t_specs specs;

	specs.plus = 0;
	specs.leftside = 0;
	specs.width = 0;
	specs.zero = 0;
	specs.count = 0;
	specs.accuracy = 0;
	specs.space = 0;
	specs.digit_flag = 0;
	specs.acc_flag = 0;
	specs.hash = 0;
	specs.l = 0;
	specs.ll = 0;
	specs.h = 0;
	specs.hh = 0;
	specs.z = 0;
	specs.j = 0;
	specs.c = 0;
	specs.str = NULL;
	specs.permis = 0;
	specs.flag = 0;
	return (specs);
}
