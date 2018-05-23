/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:08:36 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/12/13 13:08:37 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int					ft_check_nl(char *line)
{
	size_t	n;

	n = 0;
	while (line[n] != '\0')
		if (line[n++] == '\n')
			return (1);
	return (0);
}

int					ft_get_line(t_stream *ptr)
{
	char	*tmp;
	char	*buf;
	int		end;

	if (ptr->sline == NULL)
		ptr->sline = ft_strnew(0);
	end = 1;
	while (end != 0 && !ft_check_nl(ptr->sline))
	{
		tmp = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
		end = read(ptr->fd, tmp, BUFF_SIZE);
		if ((end == 0 && ft_strlen(ptr->sline) == 0) || end == -1)
			free(tmp);
		if (end == 0 && ft_strlen(ptr->sline) == 0)
			return (0);
		if (end == -1)
			return (-1);
		tmp[end] = '\0';
		buf = ft_strdup(ptr->sline);
		free(ptr->sline);
		ptr->sline = ft_strjoin(buf, tmp);
		free(tmp);
		free(buf);
	}
	return (1);
}

t_stream			**ft_make_list(void)
{
	t_stream		**ret;

	ret = (t_stream**)malloc(sizeof(t_stream*));
	*ret = NULL;
	return (ret);
}

char				*ft_add_line(t_stream *ptr)
{
	char			*ret;
	char			*new;
	size_t			n;

	n = 0;
	while (ptr->sline[n] != '\n' && ptr->sline[n] != '\0')
		n++;
	ret = (char*)malloc(sizeof(char) * (n + 1));
	n = 0;
	while (ptr->sline[n] != '\n' && ptr->sline[n] != '\0')
	{
		ret[n] = ptr->sline[n];
		n++;
	}
	ret[n] = '\0';
	if (ptr->sline[n] == '\n')
		n++;
	new = ft_strsub(ptr->sline, n, ft_strlen(ptr->sline));
	ft_strdel(&ptr->sline);
	ptr->sline = new;
	if (ft_strlen(ptr->sline) == 0)
		ft_strdel(&ptr->sline);
	return (ret);
}

int					get_next_line(const int fd, char **line)
{
	static t_stream	**fds;
	t_stream		*ptr;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	if (!fds)
		fds = ft_make_list();
	ptr = *fds;
	if (ptr != NULL)
		while (ptr != NULL && ptr->fd != fd)
			ptr = ptr->next;
	if (ptr == NULL)
	{
		ptr = (t_stream*)malloc(sizeof(t_stream));
		ptr->fd = fd;
		if (!(ptr->sline = ft_strnew(0)))
			return (-1);
		ptr->next = *fds;
		*fds = ptr;
	}
	ret = ft_get_line(ptr);
	*line = ft_add_line(ptr);
	return (ret);
}
