/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:46:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/07 19:00:59 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./signal/signal.h"
#include "./parser/parser/parser.h"

void	start_read(void)
{
	int				ret;
	char			*line;

	set_signal_term();
	while (1)
	{
		line = readline("$> ");
		if (line)
		{
			ret = str_equal(line, "exit");
			if (!ret && !str_equal(line, ""))
				parser(line);
			add_history(line);
			free(line);
			if (ret)
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
