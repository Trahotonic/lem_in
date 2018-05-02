#include "../inc/lem-inc.h"

t_room	*ft_new_room(char *name)
{
	t_room *ret;

	ret = (t_room*)malloc(sizeof(t_room));
	ret->room_name = ft_strdup(name);
	ret->room_id = 0;
	ret->links = NULL;
	ret->next = NULL;
	return (ret);
}

void		ft_add_room(t_room **rooms, char *name)
{
	t_room	*add;
	t_room	*ptr;

	add = ft_new_room(name);
	ptr = *rooms;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = add;
	add->room_id = ptr->room_id + 1;
}

void		ft_add_link(char *from, char *to, t_room **rooms)
{
	t_room	*ptr;
	t_link	*lnew;

	lnew = (t_link*)malloc(sizeof(t_link));
	lnew->name = ft_strdup(to);
	ptr = *rooms;
	while (ft_strcmp(from, ptr->room_name) && ptr != NULL)
		ptr = ptr->next;
	if (!ptr)
		return (ft_putendl_fd("No such room found", 2));
	lnew->next = ptr->links;
	ptr->links = lnew;
}
