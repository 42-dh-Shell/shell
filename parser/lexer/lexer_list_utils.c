/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:36:59 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/07 10:09:01 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	expand_lst_add(t_token *head, t_expand_info *target)
{
	t_expand_info	*lst;

	if (head->expand_info == 0)
	{
		head->expand_info = target;
		return ;
	}
	lst = head->expand_info;
	while (lst->next)
		lst = lst->next;
	lst->next = target;
}

void	token_lst_add(t_token **head, t_token *target)
{
	t_token	*lst;

	if (*head == 0)
	{
		*head = target;
		return ;
	}
	lst = *head;
	while (lst->next)
		lst = lst->next;
	lst->next = target;
}

void	release_ex_info(t_expand_info *head)
{
	t_expand_info	*target;

	while (head)
	{
		free(head->str);
		target = head;
		head = head->next;
		free(target);
	}
}

void	release_token_lst(t_token *head)
{
	t_token	*target;

	while (head)
	{
		target = head;
		head = head->next;
		free(target);
	}
}
