/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:46:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/18 01:47:48 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

t_shell	*g_shell;

void	start_shell(void)
{
	int				ret;
	char			*line;

	set_signal_term();
	while (1)
	{
		line = readline("minishell$ ");
		if (line)
		{
			ret = ft_strcmp(line, "exit");
			if (ret && ft_strcmp(line, "") != 0)
				lexer_parse(line);
			add_history(line);
			free(line);
			if (!ret)
			{
				printf("exit\n");
				break ;
			}
		}
		else
			print_exit();
	}
}

char	*get_key(char *str)
{
	int		size;
	char	*key;

	size = 0;
	if (ft_strnstr(str, "=", ft_strlen(str)) != NULL)
	{
		while (str[size] != '=')
			size++;
		key = ft_malloc(sizeof(char) * (size + 1));
		size = -1;
		while (str[++size] != '=')
			key[size] = str[size];
		key[size] = 0;
	}
	else
	{
		while (str[size])
			size++;
		key = ft_malloc(sizeof(char) * (size + 1));
		size = -1;
		while (str[++size] != '=')
			key[size] = str[size];
		key[size] = 0;
	}
	return (key);
}

char	*get_value(char *str)
{
	int		size;
	char	*val;
	int		i;

	size = 0;
	i = 0;
	if (ft_strnstr(str, "=", ft_strlen(str)) != NULL)
	{
		while (str[size] != '=')
			size++;
		val = ft_malloc(sizeof(char) * (ft_strlen(str) - size));
		size++;
		while (str[size])
		{
			val[i] = str[size];
			i++;
			size++;
		}
		val[i] = 0;
	}
	else
		val = ft_strdup("");
	return (val);
}

void	init_shell(char **envp)
{
	int		size;
	int		i;
	char	*key;
	char	*value;

	g_shell = ft_malloc(sizeof(t_shell));
	size = 0;
	i = -1;
	while (envp[size])
		size++;
	g_shell->h_table = make_hash_table(size, 0.75);
	while (++i < size)
	{
		key = get_key(envp[i]);
		value = get_value(envp[i]);
		hash_add(g_shell->h_table, key, value);
		if (ft_strcmp(key, "OLDPWD") == 0)
			hash_add(g_shell->h_table, ft_strdup("OLDPWD"), ft_strdup(""));
	}
}

int	main(int argc, char **argv, char **envp)
{	
	init_shell(envp);
	char	*export[] = {
		"unset", "PWD", "USER", "c", 0
	};
	char	*cd[] = {
		"cd", ".."
	};
	argc = 0;
	mini_unset(export);
	mini_export(NULL);
	mini_cd(cd);
	mini_pwd(argv);
	system("leaks mini");
	// start_shell();
}



	// char	*export[] = {
	// 	"export", "132=123", "_1234=123", "a1234", "a12345=123", 0
	// };
	// argc = 0;
	// // if (argc != 1 && argv != NULL)
	// // 	ft_exit("minishell : not support non-interactive mode.\n", 1);
	// init_shell(envp);
	// // argv = NULL;
	// // mini_cd(argv);
	// argv = NULL;
	// mini_export(NULL);
	// 	printf("-------------------------------\n");

	// mini_export(export);
	// 	printf("--------123-----------------------\n");

	// mini_export(NULL);
	// printf("-------------------------------\n");
	// // start_shell();