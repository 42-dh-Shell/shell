/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:54:51 by daegulee          #+#    #+#             */
/*   Updated: 2022/11/07 20:19:26 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../execute/execute.h"

static const t_built_f	g_built[9] = {
	NULL, mini_echo, mini_cd, mini_env, mini_exit, mini_export, mini_pwd, \
	mini_unset, mini_exit_status
};

int	mini_exit_status(char **argv)
{
	if (ft_strcmp(argv[0], "$?") == 0)
		printf("minishell: command not found: %d\n", g_shell->exit_status);
	return (127);
}

int	get_builtin_idx(char **argv)
{
	if (ft_strcmp(argv[0], "echo") == 0)
		return (1);
	if (ft_strcmp(argv[0], "cd") == 0)
		return (2);
	if (ft_strcmp(argv[0], "env") == 0)
		return (3);
	if (ft_strcmp(argv[0], "exit") == 0)
		return (4);
	if (ft_strcmp(argv[0], "export") == 0)
		return (5);
	if (ft_strcmp(argv[0], "pwd") == 0)
		return (6);
	if (ft_strcmp(argv[0], "unset") == 0)
		return (7);
	else
		return (0);
}

int	is_builtin(char	**argv)
{
	int			result;

	if (!argv)
		return (0);
	result = get_builtin_idx(argv);
	return (result);
}

int	do_builtin(char	**argv)
{
	int			result;

	if (!argv)
		return (0);
	result = g_built[is_builtin(argv)](argv);
	release_argv(argv);
	return (result);
}
