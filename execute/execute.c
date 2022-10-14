/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:06:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/14 19:22:05 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	execute_and_or_handler(t_ast_node *head)
{
	execute_command(head->left);
	if (head->node_type == NODE_AND)
		// if exit status == 0 ->execute_command(head->right);
	else
}

void	execute_command(t_ast_node *head)
{
	if (!head)
		return ;
	if (head->node_type == NODE_AND || head->node_type == NODE_OR)
		execute_and_or_handler(head);
	else if (head->node_type == NODE_PIPE)
		execute_pipe_handler(head);
	else if (head->node_type == NODE_SUBSHELL)
		execute_subsehll_handler(head);
	else if (is_no_event(head))
		execute_command_handler(head);
	if (head->left != 0)
		execute_command(head->left);
}
