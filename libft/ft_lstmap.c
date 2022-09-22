/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:19:47 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/01 17:25:57 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l_map;
	t_list	*elem;

	if (lst == NULL || f == NULL )
		return (NULL);
	l_map = ft_lstnew(f(lst -> content));
	if (l_map == NULL)
		return (NULL);
	lst = lst -> next;
	while (lst != NULL)
	{
		elem = ft_lstnew(f(lst -> content));
		if (elem == NULL)
		{
			if (del != NULL)
				ft_lstclear(&l_map, del);
			return (NULL);
		}
		ft_lstadd_back(&l_map, elem);
		lst = lst -> next;
	}
	return (l_map);
}
