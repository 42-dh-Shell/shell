/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:06:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/21 20:20:09 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
//        ls           |      hello        | 	 hello	  |    hello
//			
//

void	execute_middle_pipe(int read, int write, t_ast_node *head, \
		t_pid_list **pids)
{
	int	fd[2];

	fd[0] = read;
	fd[1] = write;
	execute_command(head->right, fd, C_RW, pids);
	close(fd[0]);
	close(fd[1]);
}

void	execute_pipe_handler(t_ast_node *head, t_pid_list **pids, \
			int fd_pipe[], t_command_io io)
{
	int		fd[2];

	if (pipe(fd) < 0)
		ft_exit("pipe_error\n", 1);
	if (head->left->node_type == NODE_PIPE)
		execute_pipe_handler(head->left, pids, fd, io);
	if (head->left->node_type != NODE_PIPE)
	{
		execute_command(head->left, fd, C_WRITE, pids);
		close(fd[1]);
	}
	if (fd_pipe)
		execute_middle_pipe(fd[0], fd_pipe[1], head, pids);
	else
	{
		execute_command(head->right, fd, C_READ, pids);
		close(fd[0]);
		close(fd[1]);
	}
	if (is_last_pipe(head))
		wait_all_pids(pids);
}

void	execute(t_ast_node *head, char **argv)
{
	char	*envp_path;

	if (head->node_type == NODE_DGREAT || head->node_type == NODE_LESS \
	|| head->node_type == NODE_DLESS || head->node_type == NODE_GREAT)
	{
		execute_redir(head);
		if (head->left != NULL)
			execute(head->left, argv);
	}
	else
	{
		envp_path = get_envp_path();
		if (envp_path == NULL || ft_strchr(argv[0], '/'))
			execute_fullpath_handler(argv);
		else
			execute_make_fullpath(argv, envp_path);
	}
}

void	execute_command_handler(t_ast_node *head, int fd_pipe[], \
	t_command_io io, t_pid_list **pids)
{
	pid_t	pid;
	char	**argv;

	argv = get_command_info(head);
	if (is_builtin(argv[0]))
	{
		execute_builtin(head, argv, io);
		return ;
	}
	pid = fork();
	if (pid < 0)
		ft_exit("fork error\n", 1);
	if (pid == 0)
	{
		dup_pipe(io, fd_pipe);
		execute(head, argv);
	}
	else
	{
		add_last_pid(pid, pids);
		free(argv);
	}
}

void	execute_command(t_ast_node *head, int fd_pipe[], \
	t_command_io io, t_pid_list **pids)
{	
	if (!head)
		return ;
	if (head->node_type == NODE_AND || head->node_type == NODE_OR)
		execute_and_or_handler(head, pids);
	if (head->node_type == NODE_PIPE)
		execute_pipe_handler(head, pids, fd_pipe, io);
	else if (head->node_type == NODE_SUBSHELL)
		execute_subsehll_handler(head, fd_pipe, io, pids);
	if (!has_event(head))
		execute_command_handler(head, fd_pipe, io, pids);
}
