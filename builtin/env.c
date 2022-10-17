/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:16:10 by idaegyu           #+#    #+#             */
/*   Updated: 2022/10/16 23:35:59 by idaegyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	mini_env(char **argv)
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