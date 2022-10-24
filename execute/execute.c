/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:06:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/24 17:46:39 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
//        ls           |      hello        | 	 hello	  |    hello
//			
//

void	execute_middle_pipe(int fd_pipe[], int next_pipe[], t_ast_node *head)
{
	close_pipe(fd_pipe, 1);
	execute_command(head->right, fd_pipe, next_pipe, C_RW);
	close_pipe(fd_pipe, 0);
	close_pipe(next_pipe, 1);
}

void	execute_pipe_handler(t_ast_node *head, int next_pipe[], t_command_io io)
{
	int	fd[2];

	if (pipe(fd) < 0)
		ft_exit("pipe_error\n", 1);
	if (head->left->node_type == NODE_PIPE)
		execute_pipe_handler(head->left, fd, io);
	if (head->left->node_type != NODE_PIPE)
	{
		execute_command(head->left, fd, NULL, C_WRITE);
		close_pipe(fd, 1);
	}
	if (next_pipe)
		execute_middle_pipe(fd, next_pipe, head);
	else if (is_last_pipe(head))
	{
		close_pipe(fd, 1);
		execute_command(head->right, fd, NULL, C_READ);
		close_pipe(fd, 0);
		wait_all_pids();
	}
}

void	execute(t_ast_node *head)
{
	char	*envp_path;
	char	**argv;

	while (g_shell->redir_list)
	{
		execute_redir(g_shell->redir_list);
		g_shell->redir_list = g_shell->redir_list->left;
	}
	if (head->node_type == NODE_DGREAT || head->node_type == NODE_LESS \
	|| head->node_type == NODE_DLESS || head->node_type == NODE_GREAT)
	{
		execute_redir(head);
		if (head->left != NULL)
			execute(head->left);
	}
	else
	{
		envp_path = get_envp_path();
		argv = get_command_info(head);
		if (envp_path == NULL || ft_strchr(argv[0], '/'))
			execute_fullpath_handler(argv);
		else
			execute_make_fullpath(argv, envp_path);
	}
}

void	execute_command_handler(t_ast_node *head, int fd_pipe[], \
	int next_pipe[], t_command_io io)
{
	pid_t	pid;

	if (is_builtin(head))
	{
		execute_builtin(head, io);
		return ;
	}
	pid = fork();
	if (pid < 0)
		ft_exit("fork error\n", 1);
	if (pid == 0)
	{
		dup_pipe(io, fd_pipe, next_pipe);
		execute(head);
	}
	else
		add_last_pid(pid);
}

void	execute_command(t_ast_node *head, int fd_pipe[], \
	int next_pipe[], t_command_io io)
{	
	if (!head)
		return ;
	if (head->node_type == NODE_AND || head->node_type == NODE_OR)
		execute_and_or_handler(head);
	if (head->node_type == NODE_PIPE)
		execute_pipe_handler(head, next_pipe, io);
	else if (head->node_type == NODE_SUBSHELL)
		execute_subsehll_handler(head, fd_pipe, next_pipe, io);
	if (!has_event(head))
		execute_command_handler(head, fd_pipe, next_pipe, io);
}
