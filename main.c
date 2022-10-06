/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:46:51 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/03 15:07:38 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./signal/signal.h"
#include "./parser/lexer/lexer.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

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
			ret = ft_strcmp(line, "exit");
			if (ret)
				lexer(line);
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
