/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:35:24 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/21 19:42:32 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"

void	expand_lst_add_back(t_expand_info **head, t_expand_info *new)
{
	t_expand_info	*lst;

	if (!*head)
	{
		*head = new;
		return ;
	}
	lst = *head;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}

t_expand_info	*dup_expand_info(t_expand_info *old)
{
	t_expand_info	*new;
	t_expand_info	*head;

	head = NULL;
	while (old)
	{
		new = ft_calloc(sizeof(t_expand_info), 1);
		if (!new)
			ft_exit("malloc error", 1);
		new->str = ft_strdup(old->str);
		new->size = old->size;
		new->start = old->start;
		new->split_arg = old->split_arg;
		expand_lst_add_back(&head, new);
		old = old->next;
	}
	return (head);
}
