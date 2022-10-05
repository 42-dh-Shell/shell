/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:16:30 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/04 19:36:36 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"


void	add_redir_word(t_ast_node *last_added, t_token *token)
{	
	t_redir_token	*redir_token;

	redir_token = malloc(sizeof(t_redir_token));
	if (!redir_token)
		exit(0);
	redir_token->expand_info = token->expand_info;
	redir_token->str = token->str;
	last_added->redir_token = redir_token;
	free(token);
}

void	word_handler(t_ast *ast, t_token *token)
{
	t_ast_node	*last_added;

	last_added = ast->last_added;
	if (last_added->node_type == LESS || last_added->node_type == DLESS \
	|| last_added->node_type == DLESS || last_added->node_type == DGREAT)
		add_redir_word(last_added, token);
}
