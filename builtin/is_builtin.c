/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:54:51 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/28 13:38:48 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../execute/execute.h"

static const t_built_f	g_built[9] = {
	NULL, mini_echo, mini_cd, mini_env, mini_exit, mini_export, mini_pwd, \
	mini_unset, mini_exit_status
};

t_ast_node	*get_command_node(t_ast_node *head)
{
	while (head && head->node_type != NODE_COMMAND)
		head = head->left;
	if (!head)
		return (NULL);
	return (head);
}

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
	if (ft_strcmp(argv[0], "$?") == 0)
		return (8);
	else
		return (0);
}

int	is_builtin(t_ast_node *head)
{
	char		**argv;
	int			result;
	t_ast_node	*command_node;

	command_node = get_command_node(head);
	if (!command_node)
		return (0);
	argv = get_command_info(command_node);
	result = get_builtin_idx(argv);
	release_argv(argv);
	return (result);
}

int	do_builtin(t_ast_node *head)
{
	int			result;
	char		**argv;

	argv = get_command_info(head);
	expand_exit_status(argv);
	result = g_built[is_builtin(head)](argv);
	release_argv(argv);
	return (result);
}
