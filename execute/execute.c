/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:06:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/19 19:15:27 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	execute_pipe_handler(t_ast_node *head, t_pid_list **pids)
{
	int		fd[2];

	if (pipe(fd) < 0)
		ft_exit("pipe_error\n", 1);
	execute_command(head->left, fd, C_WRITE, pids);
	execute_command(head->right, fd, C_READ, pids);
	close(fd[1]);
	close(fd[0]);
	if (is_last_pipe(head))
		wait_all_pids(pids);
}

void	close_pipe(int fd_pipe[], t_command_io io)
{
	if (io == C_WRITE)
		close(fd_pipe[0]);
	else if (io == C_READ)
		close(fd_pipe[1]);
}

void	execute(t_ast_node *head, int fd_pipe[], t_command_io io)
{
	char	**argv;
	char	*envp;
	char	*key;

	close_pipe(fd_pipe, io);
	if (head->node_type == NODE_DGREAT || head->node_type == NODE_LESS \
	|| head->node_type == NODE_DLESS || head->node_type == NODE_GREAT)
	{
		execute_redir(head);
		if (head->left != NULL)
			execute(head->left, fd_pipe, io);
	}
	else
	{
		key = ft_strdup("PATH");
		envp = get_hash(g_shell->h_table, key);
		free(key);
		argv = get_command_info(head);
		if (envp == NULL || ft_strchr(argv[0], '/'))
			execute_fullpath_handler(argv);
		else
			execute_make_fullpath(argv, envp);
	}
}

pid_t	execute_command_handler(t_ast_node *head, int fd_pipe[], \
	t_command_io io, t_pid_list **pids)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_exit("fork error\n", 1);
	if (pid == 0)
	{
		if (io == C_WRITE)
		{
			if (dup2(fd_pipe[1], STDOUT_FILENO) < 0)
				ft_exit("dup error\n", 1);
			close(fd_pipe[1]);
			close(fd_pipe[0]);
		}
		else if (io == C_READ)
		{
			if (dup2(fd_pipe[0], STDIN_FILENO) < 0)
				ft_exit("dup error\n", 1);
			close(fd_pipe[1]);
			close(fd_pipe[0]);
		}
		execute(head, fd_pipe, io);
	}
	add_last_pid(pid, pids);
	return (pid);
}

pid_t	execute_command(t_ast_node *head, int fd_pipe[], \
	t_command_io io, t_pid_list **pids)
{
	if (!head)
		return (-1);
	// if (head->node_type == NODE_AND || head->node_type == NODE_OR)
	// 	execute_and_or_handler(head);
	if (head->node_type == NODE_PIPE)
		execute_pipe_handler(head, pids);
	// else if (head->node_type == NODE_SUBSHELL)
	// 	execute_subsehll_handler(head);
	if (!has_event(head))
		return (execute_command_handler(head, fd_pipe, io, pids));
	return (-1);
}
