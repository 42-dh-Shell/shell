/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:36:59 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/11/08 17:20:27 by hyunkyle         ###   ########.fr       */
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

int	unexpected_token(t_token *head)
{
	fail_make_token_release(head);
	ft_color_printft2("(");
	return (0);
}

int	token_lst_add(t_token **head, t_token *target)
{
	t_token	*lst;
	t_token	*prev;
	int		flag;

	flag = 0;
	if (*head == 0)
	{
		*head = target;
		return (1);
	}
	lst = *head;
	prev = NULL;
	while (lst->next)
	{
		prev = lst;
		lst = lst->next;
		if (prev && prev->token_type == LBRAC && lst->token_type == LBRAC)
			flag = 1;
	}
	lst->next = target;
	if (flag)
		return (unexpected_token(*head));
	return (1);
}

void	release_ex_info(t_expand_info *head)
{
	t_expand_info	*target;

	while (head)
	{
		target = head;
		head = head->next;
		free(target->str);
		free(target);
	}
}

void	fail_make_token_release(t_token *head)
{
	t_token	*target;

	while (head)
	{
		target = head;
		head = head->next;
		if (target->token_type != LAST)
			free(target->str);
		release_ex_info(target->expand_info);
		free(target);
	}
}
