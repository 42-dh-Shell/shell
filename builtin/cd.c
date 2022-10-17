/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:26:09 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/17 13:04:14 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"
#include <errno.h>
// pwd - oldpwd chdir
// . cur
// .. back 
// ... -> error bash: cd: ...: No such file or directory

// ~,no input home
int	argv_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

static char	*get_env_in_ht(char *key)
{
	char	*path;

	path = get_hash(g_shell->h_table, key);
	if (path == NULL)
		printf("cd: %s not set\n", key);
	return (path);
}

void	set_env_in_ht(int ch_dir)
{
	char	*cwd;
	char	*value;

	if (ch_dir < 0)
		return ;
	if (get_hash(g_shell->h_table, "PWD") != NULL)
	{
		if (get_hash(g_shell->h_table, "OLDPWD") != NULL)
		{
			value = ft_strdup(get_hash(g_shell->h_table, "PWD"));
			hash_remove(g_shell->h_table, "OLDPWD");
			hash_add(g_shell->h_table, "OLDPWD", value);
		}
		hash_remove(g_shell->h_table, "PWD");
		value = getcwd(NULL, 0);
		hash_add(g_shell->h_table, "PWD", value);
	}
}

static int	change_dir(char **argv, int *print_f)
{
	char	*path;
	int		ch_dir;

	path = NULL;
	ch_dir = 2;
	if (argv_len(argv) <= 1 || ft_strcmp(argv[1], "~") == 0)
		path = get_env_in_ht("HOME");
	else if (ft_strcmp(argv[1], "-") == 0)
	{
		*print_f = 1;
		path = get_env_in_ht("OLDPWD");
	}
	else
		ch_dir = chdir(argv[1]);
	if (ch_dir == 2 && path != NULL)
		ch_dir = chdir(path);
	set_env_in_ht(ch_dir);
	return (ch_dir);
}

int	mini_cd(char **argv)
{
	int			print_flag;
	int			ch_dir;

	print_flag = 0;
	ch_dir = change_dir(argv, &print_flag);
	if (ch_dir == 2)
		return (1);
	if (ch_dir < 0)
	{
		printf("cd : %s %s\n", argv[1], strerror(errno));
		return (1);
	}
	return (0);
}
