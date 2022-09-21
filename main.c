/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:46:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/09/21 20:04:03 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

void	singnal_handler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	print_exit(void)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
	exit(0);
}

void	start_read(void)
{
	int				ret;
	char			*line;

	signal(SIGINT, singnal_handler);
	while (true)
	{
		line = readline("$> ");
		if (line)
		{
			ret = strcmp(line, "exit");
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
