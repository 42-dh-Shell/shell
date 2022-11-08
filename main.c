/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:46:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/11/08 17:16:03 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./signal/signal.h"
#include "./libft/libft.h"
#include "minishell.h"
#include "./parser/lexer/lexer.h"
#include "./hash/hash.h"

t_shell	*g_shell;

void	start_shell(void)
{
	char			*line;

	while (1)
	{
		set_signal_term();
		line = readline("minishell$ ");
		if (line)
		{
			if (ft_strcmp(line, "") != 0)
				lexer_parse(line);
			add_history(line);
			free(line);
		}
		else
			print_exit();
		system("leaks mini");
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
		while (str[++size])
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
		if (ft_strcmp(key, "TMPDIR") == 0)
			g_shell->tmp = ft_strdup(value);
		if (ft_strcmp(key, "OLDPWD") == 0)
			hash_add(g_shell->h_table, ft_strdup("OLDPWD"), ft_strdup(""));
	}
}

int	main(int argc, char **argv, char **envp)
{	
	if (argc != 1 && argv != NULL)
		ft_exit("minishell : not support non-interactive mode.\n", 1);
	init_shell(envp);
	g_shell->lr_table = make_table();
	start_shell();
}
