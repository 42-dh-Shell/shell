/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exps_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:43:17 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/21 00:43:58 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_exps	*exps_dup(t_exps *origin)
{
	t_exps	*new;

	new = ft_malloc(sizeof(t_exps));
	new->end = origin->end;
	new->is_quote = origin->is_quote;
	new->str = ft_strdup(origin->str);
	return (new);
}

t_exps_list	*exps_list_dup(t_exps_list *exps_lst)
{
	t_exps		*cur;
	t_exps_list	*new_exps_lst;

	if (exps_lst == NULL)
		return (NULL);
	new_exps_lst = ft_malloc(sizeof(t_exps_list));
	cur = exps_lst->head;
	while (cur)
	{
		exps_lst_addback(&new_exps_lst, exps_dup(cur));
		cur = cur->next;
	}
	return (new_exps_lst);
}
