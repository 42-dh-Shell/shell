/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:23:12 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/06 20:27:39 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"

void	add_subshell_command(t_token *token, t_ast *ast)
{
	t_ast_node	*new_node;

	new_node = ft_calloc(sizeof(t_ast_node), 1);
	if (!new_node)
		ft_exit("malloc error", 0);
	if (ast->command_node != 0)
		add_suffix_node(token, ast);
	else
	{
		new_node->str = token->str;
		new_node->wildcard_flag = token->wildcard_flag;
		new_node->node_type = NODE_COMMAND;
		new_node->parent = ast->subshell_head;
		ast->subshell_head->left = new_node;
		ast->command_node = new_node;
	}
}

void	add_command_node(t_token *token, t_ast *ast)
{
	t_ast_node	*new_node;

	new_node = ft_calloc(sizeof(t_ast_node), 1);
	if (!new_node)
		ft_exit("malloc error", 0);
	new_node->str = token->str;
	new_node->wildcard_flag = token->wildcard_flag;
	new_node->node_type = NODE_COMMAND;
	new_node->expand_info = token->expand_info;
	ast->last_added->left = new_node;
	new_node->parent = ast->last_added;
}

void	add_suffix_node(t_token *token, t_ast *ast)
{
	t_suffix	*suffix;
	t_suffix	*suffix_list;

	suffix = ft_calloc(sizeof(t_suffix), 1);
	if (!suffix)
		ft_exit("malloc error", 0);
	suffix->str = token->str;
	suffix->expand_info = token->expand_info;
	suffix->wildcard_flag = token->wildcard_flag;
	if (ast->command_node->suffix_list == 0)
		ast->command_node->suffix_list = suffix;
	else
	{
		suffix_list = ast->command_node->suffix_list;
		while (suffix_list->next)
			suffix_list = suffix_list->next;
		suffix_list->next = suffix;
	}
}

void	pipe_and_or_handler(t_token *token, t_ast *ast)
{
	t_ast_node	*new_node;
	t_ast_node	*head;

	new_node = get_pipe_or_and_ast_token(token);
	if (ast->subshell_head == 0)
	{
		head = ast->head;
		ast->head = new_node;
		new_node->left = head;
		head->parent = new_node;
		ast->last_added = new_node;
	}
	else
	{
		head = ast->subshell_head->left;
		ast->subshell_head->left = new_node;
		head->parent = new_node;
		new_node->left = head;
		new_node->parent = ast->subshell_head;
	}
}

t_ast_node	*get_pipe_or_and_ast_token(t_token *token)
{
	t_ast_node	*new_node;

	new_node = ft_calloc(sizeof(t_ast_node), 1);
	if (!new_node)
		ft_exit("malloc error", 0);
	if (token->token_type == PIPE)
		new_node->node_type = NODE_PIPE;
	else if (token->token_type == AND)
		new_node->node_type = NODE_AND;
	else
		new_node->node_type = NODE_OR;
	new_node->str = token->str;
	return (new_node);
}
