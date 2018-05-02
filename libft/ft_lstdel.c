/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:19:05 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/17 13:57:22 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;
	t_list *nptr;

	if (del && alst)
	{
		ptr = *alst;
		while (ptr != NULL)
		{
			nptr = ptr->next;
			del(ptr->content, ptr->content_size);
			free(ptr);
			ptr = nptr;
		}
		*alst = NULL;
	}
}
