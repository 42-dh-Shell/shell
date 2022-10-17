/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:26:09 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/18 00:14:48 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"
#include <errno.h>
#include "../body/minishell.h"

extern t_shell *g_shell;
// pwd - oldpwd chdir
// . cur
// .. back 
// ... -> error bash: cd: ...: No such file or directory

// ~,no input home

static char	*get_env_in_ht(char *key)
{
	char	*path;

	path = get_hash(g_shell->h_table, key);
	if (path != NULL && ft_strcmp(path, "") == 0)
		path = NULL;
	if (path == NULL)
		printf("mishell : cd: %s not set\n", key);
	return (path);
}

void	set_env_in_ht(int ch_dir)
{
	char	*value;

	if (ch_dir < 0 || ch_dir == NO_EXEC_CHDIR)
		return ;
	if (get_hash(g_shell->h_table, "PWD") != NULL)
	{
		if (get_hash(g_shell->h_table, "OLDPWD") != NULL)
		{
			value = ft_strdup(get_hash(g_shell->h_table, "PWD"));
			hash_add(g_shell->h_table, ft_strdup("OLDPWD"), value);
		}
		value = getcwd(NULL, 0);
		hash_add(g_shell->h_table, ft_strdup("PWD"), value);
	}
}

static int	change_dir(char **argv)
{
	char	*path;
	int		ch_dir;

	path = NULL;
	ch_dir = NO_EXEC_CHDIR;
	if (argv_len(argv) <= 1 || ft_strcmp(argv[1], "~") == 0)
		path = get_env_in_ht("HOME");
	else if (ft_strcmp(argv[1], "-") == 0)
	{
		path = get_env_in_ht("OLDPWD");
		if (path)
			printf("%s\n", path);
	}
	else
		ch_dir = chdir(argv[1]);
	if (ch_dir == NO_EXEC_CHDIR && path != NULL)
		ch_dir = chdir(path);
	set_env_in_ht(ch_dir);
	return (ch_dir);
}

int	mini_cd(char **argv)
{
	int			ch_dir;

	ch_dir = change_dir(argv);
	if (ch_dir == 2)
		return (1);
	if (ch_dir < 0)
	{
		printf("minishell : cd : %s %s\n", argv[1], strerror(errno));
		return (1);
	}
	return (0);
}
