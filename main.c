/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:46:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/11 10:27:07 by hyunkyle         ###   ########.fr       */
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
		line = readline("$> ");
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

int	main(void)
{
	t_hash	*hash_table;

	hash_table = get_hash(1, 0.75);
	hash_add(hash_table, "1", "hyunkyu1");
	hash_add(hash_table, "2", "hyunkyu2");
	hash_add(hash_table, "3", "hyunkyu3");
	hash_add(hash_table, "4", "hyunkyu4");
	hash_add(hash_table, "5", "hyunkyu5");
	hash_add(hash_table, "6", "hyunkyu6");
	hash_add(hash_table, "7", "hyunkyu7");
	hash_add(hash_table, "8", "hyunkyu8");
	hash_add(hash_table, "9", "hyunkyu9");
	hash_add(hash_table, "10", "hyunkyu10");
	
	printf("value = %s\n", hash_get(hash_table, "1")->value);
	printf("value = %s\n", hash_get(hash_table, "2")->value);
	printf("value = %s\n", hash_get(hash_table, "3")->value);
	printf("value = %s\n", hash_get(hash_table, "4")->value);
	printf("value = %s\n", hash_get(hash_table, "5")->value);
	printf("value = %s\n", hash_get(hash_table, "6")->value);
	printf("value = %s\n", hash_get(hash_table, "7")->value);
	printf("value = %s\n", hash_get(hash_table, "8")->value);
	printf("value = %s\n", hash_get(hash_table, "9")->value);
	printf("value = %s\n", hash_get(hash_table, "10")->value);

	//start_shell();
}
