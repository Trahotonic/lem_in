/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paths_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:21:19 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/05/22 15:21:20 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem-inc.h"

t_room	*ft_destination(t_room *start)
{
	t_room	*ptr;

	ptr = start;
	while (!ptr->end)
		ptr = ptr->next;
	return (ptr);
}
