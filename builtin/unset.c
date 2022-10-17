/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:29:59 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/18 01:38:49 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"
#include "../body/minishell.h"

extern t_shell *g_shell;

int	mini_unset(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (get_hash(g_shell->h_table, argv[i]) != NULL)
			hash_remove(g_shell->h_table, argv[i]);
	}
	return (1);
}
