/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:16:10 by idaegyu           #+#    #+#             */
/*   Updated: 2022/10/18 00:16:04 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../body/minishell.h"

extern t_shell *g_shell;

int	mini_env(void)
{
	t_hash_list	*cur;
	int			i;

	i = -1;
	while (++i < g_shell->h_table->table_size)
	{
		cur = g_shell->h_table->hash_array[i];
		while (cur)
		{
			if (ft_strcmp(cur->value, "") == 0)
				continue ;
			printf("%s=%s\n", cur->key, cur->value);
			cur = cur->next;
		}
	}
	return (0);
}