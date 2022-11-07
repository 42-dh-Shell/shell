/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:16:10 by idaegyu           #+#    #+#             */
/*   Updated: 2022/10/28 10:56:45 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../minishell.h"

extern t_shell	*g_shell;

int	mini_env(char **argv)
{
	t_hash_list	*cur;
	int			i;

	argv = NULL;
	i = -1;
	while (++i < g_shell->h_table->table_size)
	{
		cur = g_shell->h_table->hash_array[i];
		while (cur)
		{
			if (ft_strcmp(cur->value, "") == 0)
			{
				cur = cur->next;
				continue ;
			}
			printf("%s=%s\n", cur->key, cur->value);
			cur = cur->next;
		}
	}
	return (0);
}
