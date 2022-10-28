/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:44:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/24 21:20:22 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"

void	add_head_pipe(t_ast_node *new_node, t_ast_node *head, t_ast *ast)
{
	new_node->left = head;
	ast->head = new_node;
	head->parent = new_node;
	if (ast->subshell_flag == 1)
	{
		ast->subshell_flag = 0;
		reset_sub_idx(ast);
	}
}

void	add_right_pipe(t_ast_node *new_node, t_ast *ast)
{
	new_node->left = ast->head->right;
	ast->head->right = new_node;
	new_node->parent = ast->head;
	if (ast->subshell_flag == 1)
	{
		ast->subshell_flag = 0;
		reset_sub_idx(ast);
	}
}

void	add_pipe_node_in_subshell(t_ast *ast, t_ast_node *new_node)
{
	t_subshell_node	*subshell_head;
	int				i;
	t_ast_node		*head;

	i = -1;
	subshell_head = ast->subshell_head;
	while (++i < ast->subshell_idx)
		subshell_head = subshell_head->next;
	head = subshell_head->subshell_ast_node->left;
	if (head->node_type != NODE_AND && head->node_type != NODE_OR)
	{
		subshell_head->subshell_ast_node->left = new_node;
		head->parent = new_node;
		new_node->left = head;
		new_node->parent = subshell_head->subshell_ast_node;
	}
	else
	{
		head->right = new_node;
		new_node->parent = head;
	}
}

void	pipe_handler(t_token *token, t_ast *ast)
{
	t_ast_node	*new_node;
	t_ast_node	*head;

	new_node = get_pipe_or_and_ast_token(token);
	head = ast->head;
	if (ast->subshell_cnt == 0)
	{
		if (head->node_type != NODE_AND && head->node_type != NODE_OR)
			add_head_pipe(new_node, head, ast);
		else
			add_right_pipe(new_node, ast);
	}
	else
		add_pipe_node_in_subshell(ast, new_node);
	ast->last_added = new_node;
	ast->command_node = 0;
}
