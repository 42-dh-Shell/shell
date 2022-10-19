/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:54:01 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/19 16:05:14 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

extern t_shell *g_shell;

void	envp_join(char **argv, int j, char *key, char *value)
{
	char	*tmp;

	tmp = ft_strjoin(key, "=");
	argv[j] = ft_strjoin(tmp, key);
	free(tmp);
}

char	**get_envp(void)
{
	t_hash_list	*cur;
	int			i;
	char		**argv;
	int			j;

	j = -1;
	argv = ft_malloc(sizeof(char *) * (g_shell->h_table->size_elem + 1));
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
			envp_join(argv, ++j, cur->key, cur->value);
			cur = cur->next;
		}
	}
	argv[++j] = NULL;
	return (argv);
}

