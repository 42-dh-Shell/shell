/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:25:43 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/11/08 14:12:56 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	execute_child(char **argv, t_ast_node *head)
{
	(g_shell->sh_lv)++;
	if (argv && ft_strcmp(argv[0], "") == 0)
		exit(0);
	if (is_builtin(argv))
	{
		execute_builtin(head, argv);
		exit(g_shell->exit_status);
	}
	else
	{
		execute(head, argv);
		exit(0);
	}
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
		ft_putstr_fd(COMM_ERROR, 2);
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd("\n", 2);
		exit(127);
	}
}

void	dup_child(t_ast_node *head)
{
	char	**argv;

	if (!is_valid_redir_filename(head->redir_token->expand_info))
		exit(1);
	argv = expand_str(head->redir_token->str, \
		head->redir_token->expand_info);
	if (!dup_builtin_fd(argv[0], head->node_type))
		exit(1);
	release_argv(argv);
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
	execve(argv[0], argv, get_envp());
	ft_exit("execve error\n", 1);
}
