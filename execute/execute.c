/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:06:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/19 17:17:49 by hyunkyle         ###   ########.fr       */
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
	int		fd[2];
	pid_t	pid[2];
	//int		status[2];

	if (pipe(fd) < 0)
		ft_exit("pipe_error\n", 1);
	pid[0] = execute_command(head->left, fd, C_WRITE);
	pid[1] = execute_command(head->right, fd, C_READ);
	close(fd[1]);
	close(fd[0]);
}

void	execute(t_ast_node *head, int fd_pipe[], t_command_io io)
{
	char	**argv;
	char	*envp;
	char	*key;

	if (io == C_WRITE)
		close(fd_pipe[0]);
	else if (io == C_READ)
		close(fd_pipe[1]);
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
	t_command_io io)
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
	return (pid);
}

pid_t	execute_command(t_ast_node *head, int fd_pipe[], \
	t_command_io io)
{
	if (!head)
		return (-1);
	// if (head->node_type == NODE_AND || head->node_type == NODE_OR)
	// 	execute_and_or_handler(head);
	if (head->node_type == NODE_PIPE)
		execute_pipe_handler(head);
	// else if (head->node_type == NODE_SUBSHELL)
	// 	execute_subsehll_handler(head);
	if (!has_event(head))
		return (execute_command_handler(head, fd_pipe, io));
	return (-1);
}
