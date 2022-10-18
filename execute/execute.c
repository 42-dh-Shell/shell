/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:06:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/18 11:37:23 by hyunkyle         ###   ########.fr       */
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


void	execute(t_ast_node *head)
{
	char	**argv;

	if (head->node_type == NODE_DGREAT || head->node_type == NODE_LESS \
	|| head->node_type == NODE_DLESS || head->node_type == NODE_GREAT)
	{
		if (!is_valid_redir_filename(head->redir_token->expand_info), argv)
			return ;
		argv = expand_str(head);
		dup_fd(head->redir_token->str, head->node_type);
		execute(head->left);
	}
}

pid_t	execute_command_handler(t_ast_node *head, int fd_pipe[], \
	t_command_io io)
{
	pid_t	pid;

	if (io == C_WRITE)
	{
		if (dup2(fd_pipe[1], STDOUT_FILENO) < 0)
			ft_exit("dup error\n", 1);
	}
	else if (io == C_READ)
	{
		if (dup2(fd_pipe[0], STDIN_FILENO) < 0)
			ft_exit("dup error\n", 1);
	}
	pid = fork();
	if (pid < 0)
		ft_exit("fork error\n", 1);
	if (pid == 0)
		execute(head);
	return (pid);
}

void	execute_command(t_ast_node *head, int fd_pipe[], \
	t_command_io io)
{
	pid_t	pid;

	pid = -1;
	if (!head)
		return ;
	// if (head->node_type == NODE_AND || head->node_type == NODE_OR)
	// 	execute_and_or_handler(head);
	else if (head->node_type == NODE_PIPE)
		execute_pipe_handler(head);
	// else if (head->node_type == NODE_SUBSHELL)
	// 	execute_subsehll_handler(head);
	if (!has_event(head))
		pid = execute_command_handler(head, fd_pipe, io);
	if (pid != -1)
		waitpid(pid, NULL);
}
