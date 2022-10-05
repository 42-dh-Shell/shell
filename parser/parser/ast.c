/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:13:23 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/04 19:36:14 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"

void	ast_handler(t_ast *ast, t_token *token)
{
	if (ast->head == 0)
		head_node_handler(ast, token);
	else if (token->token_type == WORD)
		word_handler(ast, token);
	else if (token->token_type == PIPE || token->token_type == AND || \
		token->token_type == OR)
		pipe_and_or_handler(ast, token);
	else if (token->token_type == DLESS || token->token_type == LESS || \
		token->token_type == GREAT || token->token_type == DGREAT)
		redir_handler(ast, token);
	else
		subshell_handler(ast, token);
}

t_ast	*make_ast(t_token *token)
{
	t_ast		*ast;
	t_token		*tmp;

	ast = allocate_ast();
	while (token->token_type != LAST)
	{
		tmp = token;
		token = token->next;
		ast_handler(ast, tmp);
	}
}
