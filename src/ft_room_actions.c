#include "../inc/lem-inc.h"

t_room	*ft_new_room(char *name, int n)
{
	t_room	*ret;
	char 	**dump;

	dump = ft_strsplit(name, ' ');
	ret = (t_room*)malloc(sizeof(t_room));
	ret->room_name = ft_strdup(dump[0]);
	ret->room_id = 0;
	ret->links = NULL;
	ret->next = NULL;
	ret->start = 0;
	if (n == 1)
		ret->start = 1;
	ret->end = 0;
	if (n == 2)
		ret->end = 1;
	ft_free_dump(dump);
	return (ret);
}

void	ft_add_room(t_room **rooms, char *name, int n)
{
	t_room	*add;
	t_room	*ptr;

	add = ft_new_room(name, n);
	ptr = *rooms;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = add;
	add->room_id = ptr->room_id + 1;
}

int 	ft_duplicate_exists(t_link *links, char *to)
{
	t_link	*ptr;

	ptr = links;
	while (ptr)
	{
		if (ft_strequ(to, ptr->name))
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void	ft_add_link(char *from, char *to, t_room **rooms)
{
	t_room	*ptr;
	t_link	*l_new;

	l_new = (t_link*)malloc(sizeof(t_link));
	l_new->name = ft_strdup(to);
	ptr = *rooms;
	while (ft_strcmp(from, ptr->room_name) && ptr != NULL)
		ptr = ptr->next;
	if (!ptr)
		return (ft_putendl_fd("No such room found", 2));
	if (!ft_duplicate_exists(ptr->links, to))
	{
		l_new->next = ptr->links;
		ptr->links = l_new;
	}
}
