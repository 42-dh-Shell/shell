/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:46:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/14 14:50:11 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./signal/signal.h"
#include "./libft/libft.h"
#include "minishell.h"
#include "./parser/lexer/lexer.h"
#include "./hash/hash.h"

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

int	main(int argc, char **argv, char **envp)
{	
	t_hash	*hash_table;

	hash_table = get_hash_table(20, 0.75);
	int i = 0;
	argc = 0;
	argv = 0;
	while (envp[i])
	{
		char **str = ft_split(envp[i], '=');
		if (str[1] == 0)
			str[1] = ft_strdup("");
		printf("key = %s\n", str[0]);
		printf("value = %s\n", str[1]);
		hash_add(hash_table, str[0], str[1]);
		i++;
	}
	//start_shell();
}
