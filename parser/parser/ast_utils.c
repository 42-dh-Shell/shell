/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:16:30 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/19 16:33:23 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"

void	add_head_redir(t_token *token, t_ast *ast)
{
	t_ast_node	*new_node;

	new_node = ft_calloc(sizeof(t_ast_node), 1);
	if (!new_node)
		ft_exit("malloc error", 0);
	new_node->str = token->str;
	if (token->token_type == DLESS)
		new_node->node_type = NODE_DLESS;
	else if (token->token_type == LESS)
		new_node->node_type = NODE_LESS;
	else if (token->token_type == GREAT)
		new_node->node_type = NODE_GREAT;
	else
		new_node->node_type = NODE_DGREAT;
	ast->head = new_node;
	ast->last_added = new_node;
}

void	add_head_subshell(t_ast *ast)
{
	t_ast_node		*new_node;
	t_subshell_node	*subshell_node;

	new_node = ft_calloc(sizeof(t_ast_node), 1);
	if (!new_node)
		ft_exit("malloc error", 0);
	subshell_node = ft_calloc(sizeof(t_subshell_node), 1);
	if (!subshell_node)
		ft_exit("malloc error", 0);
	new_node->node_type = NODE_SUBSHELL;
	subshell_node->subshell_ast_node = new_node;
	ast->head = new_node;
	ast->subshell_idx = 0;
	ast->subshell_head = subshell_node;
	ast->last_added = new_node;
	ast->subshell_cnt += 1;
}

void	add_head_command(t_token *token, t_ast *ast)
{
	t_ast_node	*new_node;

	new_node = ft_calloc(sizeof(t_ast_node), 1);
	if (!new_node)
		ft_exit("malloc error", 0);
	new_node->str = token->str;
	new_node->wildcard_flag = token->wildcard_flag;
	new_node->node_type = NODE_COMMAND;
	new_node->expand_info = token->expand_info;
	ast->head = new_node;
	ast->last_added = new_node;
	ast->command_node = new_node;
}

void	add_redir_token(t_token *token, t_ast *ast)
{
	t_redir_token	*redir_token;

	redir_token = ft_calloc(sizeof(t_redir_token), 1);
	if (!redir_token)
		ft_exit("malloc error", 0);
	redir_token->str = token->str;
	redir_token->expand_info = token->expand_info;
	ast->last_added->redir_token = redir_token;
}

void	add_command_node_right(t_token *token, t_ast *ast)
{
	t_ast_node	*new_node;

	new_node = ft_calloc(sizeof(t_ast_node), 1);
	if (!new_node)
		ft_exit("malloc error", 0);
	new_node->str = token->str;
	new_node->expand_info = token->expand_info;
	new_node->node_type = NODE_COMMAND;
	new_node->wildcard_flag = token->wildcard_flag;
	ast->last_added->right = new_node;
	new_node->parent = ast->last_added;
	ast->last_added = new_node;
	ast->command_node = new_node;
}
