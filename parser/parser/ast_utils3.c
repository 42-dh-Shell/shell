/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:25:13 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/11 19:27:29 by hyunkyle         ###   ########.fr       */
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

void	add_last_subshell_node(t_ast *ast, t_ast_node *new_node)
{
	t_subshell_node	*subshell_node;
	t_subshell_node	*sub_head;

	subshell_node = ft_calloc(sizeof(t_subshell_node), 1);
	if (!subshell_node)
		ft_exit("malloc error", 0);
	subshell_node->subshell_ast_node = new_node;
	if (ast->subshell_head == 0)
		ast->subshell_head = subshell_node;
	else
	{
		sub_head = ast->subshell_head;
		while (sub_head->next)
			sub_head = sub_head->next;
		sub_head->next = subshell_node;
	}
	ast->subshell_idx += 1;
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
	subshell_head->subshell_ast_node->left = new_node;
	head->parent = new_node;
	new_node->left = head;
	new_node->parent = subshell_head->subshell_ast_node;
}

void	reset_sub_idx(t_ast *ast)
{
	t_subshell_node	*subshell_head;
	int				idx;

	idx = -1;
	subshell_head = ast->subshell_head;
	while (subshell_head)
	{
		idx++;
		subshell_head = subshell_head->next;
	}
	ast->subshell_idx = idx;
}
