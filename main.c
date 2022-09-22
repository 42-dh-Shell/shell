/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:46:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/09/22 19:32:51 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./signal/signal.h"
#include "./libft/libft.h"
#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void	start_read(void)
{
	int				ret;
	char			*line;

	set_signal_term();
	while (true)
	{
		line = readline("$> ");
		if (line)
		{
			ret = ft_strcmp(line, "exit");
			if (ret)
				//tokenizing_line
			add_history(line);
			free(line);
			if (!ret)
			{
				printf("exit\n");
				exit(0);
			}
		}
		else
			print_exit();
	}
}

int	main(void)
{
	start_read();
}
