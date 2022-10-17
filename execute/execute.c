/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:06:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/17 13:22:11 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	execute_and_or_handler(t_ast_node *head)
{
	execute_command(head->left, 0, C_NORMAL);
	//if (head->node_type == NODE_AND)
		// if exit_status == 0
			//execute_command(head->right);
	//else
		// if exit_status != 0
			//execute_command(head->right);
}

void	execute_pipe_handler(t_ast_node *head)
{
	int	fd[2];

	if (pipe(fd) < 0)
		ft_exit("pipe_error\n", 1);
	execute_command(head->left, fd, C_WRITE);
	execute_command(head->right, fd, C_READ);
}

void	execute_command_handler(t_ast_node *head, int fd_pipe[], \
	t_command_io io)
{
	if (id == )
}

void	execute_command(t_ast_node *head, int fd_pipe[], \
	t_command_io io)
{
	if (!head)
		return ;
	// if (head->node_type == NODE_AND || head->node_type == NODE_OR)
	// 	execute_and_or_handler(head);
	else if (head->node_type == NODE_PIPE)
		execute_pipe_handler(head);
	// else if (head->node_type == NODE_SUBSHELL)
	// 	execute_subsehll_handler(head);
	else if (!has_event(head))
		execute_command_handler(head, fd_pipe, io);
}
