/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:39:28 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/28 10:57:07 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../minishell.h"

extern t_shell	*g_shell;

int	mini_pwd(char **argv)
{
	const int	argc = argv_len(argv);
	char		*str;

	if (argc == 0)
		return (1);
	str = getcwd(NULL, 0);
	printf("%s\n", str);
	if (str == NULL)
		return (1);
	free(str);
	return (0);
}
