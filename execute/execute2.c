/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:43:55 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/28 13:37:13 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	expand_exit_status(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "$?") == 0)
		{
			free(argv[i]);
			argv[i] = ft_itoa(g_shell->exit_status);
		}
		i++;
	}
}

void	close_pipe(int fd_pipe[2], int idx)
{	
	if (fd_pipe[idx] != -1)
	{
		if (fd_pipe[idx] != 1 && fd_pipe[idx] != 0)
			close(fd_pipe[idx]);
		fd_pipe[idx] = -1;
	}
}

void	dup_pipe(t_command_io io, int fd_pipe[], int next_pipe[])
{
	if (io == C_RW)
	{
		close_pipe(fd_pipe, 1);
		close_pipe(next_pipe, 0);
		if (dup2(fd_pipe[0], STDIN_FILENO) < 0)
			ft_exit("dup error\n", 1);
		close_pipe(fd_pipe, 0);
		if (dup2(next_pipe[1], STDOUT_FILENO) < 0)
			ft_exit("dup error\n", 1);
		close_pipe(next_pipe, 1);
	}
	else if (io == C_WRITE)
	{
		close_pipe(fd_pipe, 0);
		if (dup2(fd_pipe[1], STDOUT_FILENO) < 0)
			ft_exit("dup error\n", 1);
		close_pipe(fd_pipe, 1);
	}
	else if (io == C_READ)
	{
		close_pipe(fd_pipe, 1);
		if (dup2(fd_pipe[0], STDIN_FILENO) < 0)
			ft_exit("dup error\n", 1);
		close_pipe(fd_pipe, 0);
	}
}

void	execute_and_or_handler(t_ast_node *head)
{
	execute_command(head->left, NULL, NULL, C_NORMAL);
	wait_all_pids();
	stdio_rollback();
	if (head->node_type == NODE_AND && g_shell->exit_status == 0)
		execute_command(head->right, NULL, NULL, C_NORMAL);
	else if (head->node_type == NODE_OR && g_shell->exit_status != 0)
		execute_command(head->right, NULL, NULL, C_NORMAL);
}

void	execute_subsehll_handler(t_ast_node *head, int fd_pipe[], \
	int next_pipe[], t_command_io io)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		ft_exit("fork error\n", 1);
	if (pid == 0)
	{
		g_shell->pids = NULL;
		if (head->right)
			g_shell->redir_list = head->right;
		execute_command(head->left, fd_pipe, next_pipe, io);
		wait_all_pids();
		exit(g_shell->exit_status);
	}
	else
	{
		waitpid(pid, &status, 0);
		g_shell->exit_status = WEXITSTATUS(status);
	}
}