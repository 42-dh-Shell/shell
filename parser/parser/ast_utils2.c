/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:23:39 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/06 20:47:22 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"

t_ast_node	*get_redir_ast_node(t_token *token)
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
	return (new_node);
}

void	redir_handler(t_token *token, t_ast *ast)
{
	t_ast_node	*new_node;
	t_ast_node	*comm_parent;

	new_node = get_redir_ast_node(token);
	if (ast->command_node == 0)
	{
		ast->last_added->left = new_node;
		new_node->parent = ast->last_added;
		ast->last_added = new_node;
	}
	else
	{
		comm_parent = ast->command_node->parent;
		ast->command_node->parent = new_node;
		new_node->parent = comm_parent;
	}
}

void	subshell_handler(t_token *token, t_ast *ast)
{
	t_ast_node	*new_node;

	if (token->token_type == LBRAC)
	{
		new_node = ft_calloc(sizeof(t_ast_node), 1);
		if (!new_node)
			ft_exit("malloc error", 0);
		ast->last_added->right = new_node;
		new_node->parent = ast->last_added;
		ast->subshell_head = new_node;
	}
	else
		ast->subshell_head = 0;
}
