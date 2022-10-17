/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_r21,20,19,18,17.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:12:57 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/11 19:29:24 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"

void	act_r21(t_support *sup)
{
	t_token	*cur;

	if (sup->wait->cmd_suf->para_lst == NULL)
		sup->wait->cmd_suf->para_lst = ft_malloc(sizeof(t_token_list));
	cur = sup->wait->cmd_suf->para_lst->head;
	if (cur == NULL)
	{
		sup->wait->cmd_suf->para_lst->head = \
		token_dup(sup->stack->top->bottom->token);
		return ;
	}
	while (cur->next)
		cur = cur->next;
	cur->next = token_dup(sup->stack->top->bottom->token);
}

void	act_r20(t_support *sup)
{
	sup->wait->cmd_suf = ft_malloc(sizeof(t_cmd_suf));
	sup->wait->cmd_suf->para_lst = ft_malloc(sizeof(t_token_list));
	sup->wait->cmd_suf->para_lst->head \
	= token_dup(sup->stack->top->bottom->token);
}

void	act_r19(t_support *sup)
{
	t_redir	*cur;

	if (sup->wait->cmd_suf->pre_rd_lst == NULL)
		sup->wait->cmd_suf->pre_rd_lst = ft_malloc(sizeof(t_redir_lst));
	cur = sup->wait->cmd_suf->pre_rd_lst->head;
	if (cur == NULL)
	{
		sup->wait->cmd_suf->pre_rd_lst->head = sup->wait->io_redir;
		sup->wait->io_redir = NULL;
		return ;
	}
	while (cur->next)
		cur = cur->next;
	cur->next = sup->wait->io_redir;
	sup->wait->io_redir = NULL;
}

void	act_r18(t_support *sup)
{
	sup->wait->cmd_suf = ft_malloc(sizeof(t_cmd_suf));
	sup->wait->cmd_suf->pre_rd_lst = ft_malloc(sizeof(t_redir_lst));
	sup->wait->cmd_suf->pre_rd_lst->head = sup->wait->io_redir;
	sup->wait->io_redir = NULL;
}

void	act_r17(t_support *sup)
{
	sup->wait->cmd_name = ft_malloc(sizeof(t_cmd_name));
	sup->wait->cmd_name->c_name = token_dup(sup->stack->top->bottom->token);
}

// <a cat && <b <d <a cat >d >>a | <a <d cat >d >>a && ( cat && ls )