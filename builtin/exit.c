/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:58:58 by idaegyu           #+#    #+#             */
/*   Updated: 2022/10/28 10:56:50 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../minishell.h"

extern t_shell	*g_shell;

int	str_numeric(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	mini_exit(char **argv)
{
	int	argc;
	int	status;

	argc = argv_len(argv);
	if (g_shell->sh_lv == 0)
		error_printf("exit\n");
	if (argc <= 1)
		status = g_shell->exit_status;
	else if (argc == 2)
	{
		if (!str_numeric(argv[1]))
		{
			status = 255;
			error_printf("minishell : exit : %s : numeric argument required\n", \
			argv[1]);
		}
		else
			status = ft_atoi(argv[1], NULL);
	}
	else
	{
		error_printf("minishell : exit : too many argument\n");
		return (1);
	}
	exit(status & 0xFF);
}
