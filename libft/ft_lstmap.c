/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:37:45 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/17 14:00:02 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *new;
	t_list *ptr;

	ret = NULL;
	while (lst && f)
	{
		if (!(new = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		new = f(lst);
		if (!ret)
			ret = new;
		else
		{
			ptr = ret;
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = new;
		}
		lst = lst->next;
	}
	return (ret);
}
