/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:46:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/11 19:55:55 by hyunkyle         ###   ########.fr       */
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
	start_shell();
}
