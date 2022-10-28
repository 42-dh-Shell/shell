/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:25:43 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/28 15:00:06 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

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
		ft_putstr_fd(COMM_ERROR, 2);
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd("\n", 2);
		exit(127);
	}
}

void	dup_child(t_ast_node *head)
{
	if (!dup_builtin_fd(head->redir_token->str, head->node_type))
		exit(1);
}

void	execute_fullpath_handler(char **argv)
{
	if (!is_valid_command(argv[0]))
	{
		ft_putstr_fd(COMM_ERROR, 2);
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd("\n", 2);
		exit(127);
	}
	execute_fullpath(argv);
}

void	execute_fullpath(char **argv)
{
	expand_exit_status(argv);
	execve(argv[0], argv, get_envp());
	ft_exit("execve error\n", 1);
}
