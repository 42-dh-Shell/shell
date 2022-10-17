/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:54:51 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/18 02:14:23 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static const t_built_f	g_built[8] = {
	NULL, mini_echo, mini_cd, mini_env, mini_exit, mini_export, mini_pwd, \
	mini_unset
};

int	is_builtin(char *argv_0)
{
	if (ft_strcmp(argv_0, "echo") == 0)
		return (1);
	if (ft_strcmp(argv_0, "cd") == 0)
		return (2);
	if (ft_strcmp(argv_0, "env") == 0)
		return (3);
	if (ft_strcmp(argv_0, "exit") == 0)
		return (4);
	if (ft_strcmp(argv_0, "export") == 0)
		return (5);
	if (ft_strcmp(argv_0, "pwd") == 0)
		return (6);
	if (ft_strcmp(argv_0, "unset") == 0)
		return (7);
	return (0);
}

int	do_builtin(char **argv)
{
	int	result;

	result = g_built[is_builtin(argv[0])](argv);
	return (result);
}
