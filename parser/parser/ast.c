/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:13:23 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/24 21:04:07 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"

void	head_node_handler(t_token *token, t_ast *ast)
{
	if (token->token_type == DLESS || token->token_type == LESS || \
		token->token_type == GREAT || token->token_type == DGREAT)
		add_head_redir(token, ast);
	else if (token->token_type == LBRAC)
		add_head_subshell(ast);
	else
		add_head_command(token, ast);
}

void	word_handler(t_token *token, t_ast *ast)
{
	if ((ast->last_added != 0 && ast->last_added->redir_token == 0) && \
		(ast->last_added->node_type == NODE_GREAT \
		|| ast->last_added->node_type == NODE_LESS \
		|| ast->last_added->node_type == NODE_DGREAT \
		|| ast->last_added->node_type == NODE_DLESS))
		add_redir_token(token, ast);
	else if (ast->last_added != 0 && \
		(ast->last_added->node_type == NODE_AND || \
		ast->last_added->node_type == NODE_PIPE || \
		ast->last_added->node_type == NODE_OR))
		add_command_node_right(token, ast);
	else if (ast->command_node == 0)
		add_command_node(token, ast);
	else if (ast->command_node != 0)
		add_suffix_node(token, ast);
}

void	make_ast(t_token *token, t_ast *ast)
{
	if (ast->head == 0)
		head_node_handler(token, ast);
	else if (token->token_type == WORD)
		word_handler(token, ast);
	else if (token->token_type == AND || token->token_type == OR)
		and_or_handler(token, ast);
	else if (token->token_type == PIPE)
		pipe_handler(token, ast);
	else if (token->token_type == DLESS || token->token_type == LESS || \
		token->token_type == GREAT || token->token_type == DGREAT)
		redir_handler(token, ast);
	else if (token->token_type == LBRAC || token->token_type == RBRAC)
		subshell_handler(token, ast);
}
