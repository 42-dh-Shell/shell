/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:39:28 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/20 14:32:13 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../body/minishell.h"

extern t_shell *g_shell;

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
