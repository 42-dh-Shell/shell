/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:58:58 by idaegyu           #+#    #+#             */
/*   Updated: 2022/10/17 13:08:41 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

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

void	mini_exit(char **argv)
{
	int	argc;
	int	status;

	argc = argv_len(argv);
	if (g_shell->sh_lv == 0)
		printf("exit\n");
	if (argc <= 1)
		status = g_shell->exit_status;
	else if (argc == 2)
	{
		if (!str_numeric(argv[0]))
		{
			status = 255;
			printf("exit : %s : numeric argument required\n", argv[0]);
		}
		else
			status = ft_atoi(argv[0], NULL);
	}
	else
	{
		printf("exit : too many argument\n");
		return (1);
	}
	exit(status & 0xFF);
}