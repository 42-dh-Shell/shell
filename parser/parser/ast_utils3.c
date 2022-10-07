/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:25:13 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/07 20:40:26 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../lexer/lexer.h"

int	is_node_pipe_and_or(t_ast_node	*node)
{
	return (node->node_type == NODE_PIPE || \
		node->node_type == NODE_OR || \
		node->node_type == NODE_AND);
}
