/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:43:55 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/20 18:30:17 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	dup_pipe(t_command_io io, int fd_pipe[])
{
	if (io == C_RW)
	{
		if (dup2(fd_pipe[0], STDIN_FILENO) < 0)
			ft_exit("dup error\n", 1);
		if (dup2(fd_pipe[1], STDOUT_FILENO) < 0)
			ft_exit("dup error\n", 1);
		close(fd_pipe[0]);
		close(fd_pipe[1]);
	}
	else if (io == C_WRITE)
	{
		close(fd_pipe[0]);
		if (dup2(fd_pipe[1], STDOUT_FILENO) < 0)
			ft_exit("dup error\n", 1);
		close(fd_pipe[1]);
	}
	else if (io == C_READ)
	{
		close(fd_pipe[1]);
		if (dup2(fd_pipe[0], STDIN_FILENO) < 0)
			ft_exit("dup error\n", 1);
		close(fd_pipe[0]);
	}
}

void	execute_and_or_handler(t_ast_node *head, t_pid_list **pids)
{
	execute_command(head->left, NULL, C_NORMAL, pids);
	wait_all_pids(pids);
	if (head->node_type == NODE_AND && g_shell->exit_status == 0)
		execute_command(head->right, NULL, C_NORMAL, pids);
	else if (head->node_type == NODE_OR && g_shell->exit_status != 0)
		execute_command(head->right, NULL, C_NORMAL, pids);
}

void	execute_subsehll_handler(t_ast_node *head, int fd_pipe[], \
	t_command_io io, t_pid_list **pids)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		ft_exit("fork error\n", 1);
	if (pid == 0)
	{
		pids = NULL;
		head->left->right = head->right;
		execute_command(head->left, fd_pipe, io, pids);
		wait_all_pids(pids);
		exit(g_shell->exit_status);
	}
	else
	{
		waitpid(pid, &status, 0);
		g_shell->exit_status = WEXITSTATUS(status);
	}
}
