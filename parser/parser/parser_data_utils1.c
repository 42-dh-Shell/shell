/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:50:10 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/14 13:01:50 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"

void	release_subshell_node(t_subshell_node *sub_node)
{
	t_subshell_node	*target;

	while (sub_node)
	{
		target = sub_node;
		sub_node = sub_node->next;
		free(target);
	}
}

void	release_suffix_list(t_suffix *suffix_list)
{
	t_suffix	*target;

	while (suffix_list)
	{
		target = suffix_list;
		suffix_list = suffix_list->next;
		free(target);
	}
}

void	release_redir_token(t_redir_token *token)
{
	if (token == 0)
		return ;
	free(token);
}

void	release_ast_node(t_ast_node *head)
{
	t_ast_node	*target;

	if (head == 0)
		return ;
	target = head;
	if (head->left != 0)
		release_ast_node(head->left);
	if (head->right != 0)
		release_ast_node(head->right);
	release_suffix_list(target->suffix_list);
	release_redir_token(target->redir_token);
	free(target);
}

void	release_ast(t_ast *ast)
{
	release_subshell_node(ast->subshell_head);
	release_ast_node(ast->head);
	free(ast);
}
