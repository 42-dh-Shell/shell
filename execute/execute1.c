/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:25:43 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/19 19:50:55 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	dup_fd(char *filename, enum	e_ast_types type)
{
	int	fd;
	int	status;

	if (type == NODE_DGREAT)
		fd = open (filename, O_CREAT | O_APPEND | O_WRONLY, 0644);
	else if (type == NODE_GREAT)
		fd = open (filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else
		fd = open (filename, O_RDONLY);
	if (fd < 0)
	{
		if (errno == 2)
			printf ("minishell: no such file or directory: %s\n", filename);
		exit (1);
	}
	if (type == NODE_DGREAT || type == NODE_GREAT)
		status = dup2(fd, STDOUT_FILENO);
	else
		status = dup2(fd, STDIN_FILENO);
	if (status < 0)
		ft_exit ("dup2 error\n", 1);
}

void	execute_redir(t_ast_node *head)
{
	char	**argv;

	if ((head->node_type == NODE_GREAT || head->node_type == NODE_DGREAT) \
		&& next_redir_exist(head))
		return ;
	if (!is_valid_redir_filename(head->redir_token->expand_info))
		return ;
	argv = expand_str(head->redir_token->str, \
		head->redir_token->expand_info);
	dup_fd(argv[0], head->node_type);
}

void	execute_make_fullpath(char **argv, char *envp)
{
	char	**paths;
	char	*full_path;

	paths = ft_split(envp, ':');
	if (!paths)
		ft_exit("malloc error\n", 1);
	full_path = get_valid_fullpath(paths, argv);
	if (full_path)
	{
		argv[0] = full_path;
		execute_fullpath(argv);
	}
	else
	{
		printf (COMM_ERROR);
		printf ("%s\n", argv[0]);
		exit(127);
	}
}

void	execute_fullpath_handler(char **argv)
{
	if (!is_valid_command(argv[0]))
	{
		printf (COMM_ERROR);
		printf ("%s\n", argv[0]);
		exit(127);
	}
	execute_fullpath(argv);
}

void	execute_fullpath(char **argv)
{
	execve(argv[0], argv, get_envp());
	ft_exit("execve error\n", 1);
}
