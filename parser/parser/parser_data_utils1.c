/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:50:10 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/21 20:45:15 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"

void	release_all_subshell_node(t_subshell_node *sub_node)
{
	t_subshell_node	*target;

	while (sub_node)
	{
		target = sub_node;
		sub_node = sub_node->next;
		free(target);
	}
}

void	release_all_suffix_list(t_suffix *suffix_list)
{
	t_suffix	*target;

	while (suffix_list)
	{
		target = suffix_list;
		suffix_list = suffix_list->next;
		free(target->str);
		release_ex_info(target->expand_info);
		free(target);
	}
}

void	release_all_redir_token(t_redir_token *token)
{
	if (token == 0)
		return ;
	release_ex_info(token->expand_info);
	free(token->str);
	free(token);
}

void	release_all_ast_node(t_ast_node *head)
{
	t_ast_node	*target;

	if (head == 0)
		return ;
	target = head;
	if (head->left != 0)
		release_all_ast_node(head->left);
	if (head->right != 0)
		release_all_ast_node(head->right);
	if (target->node_type == NODE_SUBSHELL)
	{
		free(target);
		return ;
	}
	release_all_suffix_list(target->suffix_list);
	release_ex_info(target->expand_info);
	if (ft_strcmp(target->str, "<<") == 0)
		unlink(target->redir_token->str);
	release_all_redir_token(target->redir_token);
	free(target->str);
	free(target);
}

void	release_all_ast(t_ast *ast)
{
	release_all_subshell_node(ast->subshell_head);
	release_all_ast_node(ast->head);
	free(ast);
}
