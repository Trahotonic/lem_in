/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:38:57 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/05/29 14:38:57 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKUP_H
# define BACKUP_H

typedef struct s_link	t_link;

typedef struct		s_room
{
	char			*room_name;
	long			x;
	long			y;
	long			depth;
	size_t			ant_nbr;
	int				start;
	int				end;
	t_link			*links;
	struct s_room	*next;
}					t_room;

#endif
