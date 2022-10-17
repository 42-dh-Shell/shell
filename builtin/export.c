/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:36:51 by idaegyu           #+#    #+#             */
/*   Updated: 2022/10/17 13:23:45 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	print_export(void)
{
	t_hash_list	*cur;
	int			i;

	i = -1;
	while (++i < g_shell->h_table->table_size)
	{
		cur = g_shell->h_table->hash_array[i];
		while (cur)
		{
			printf("%s %s", "declare -x", cur->key);
			if (ft_strcmp(cur->value, "") != 0)
				printf("= %s", cur->value);
			printf("\n");
			cur = cur->next;
		}
	}
}

int	is_id(char *str)
{
	int	i;

	i = 0;
	if (!(ft_isalpha(str[i]) || str[i] == '_'))
		return (0);
	i++;
	while (str[i])
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

int	mini_export(char **argv)
{
	int	argc;
	int	i;

	argc = argv_len(argv);
	i = 0;
	if (argc <= 1)
		return (print_export());
	else
	{
		while (argv[++i])
		{
			if (!is_id(argv[i]))
			{
				print_invaild(argv[i]);
				continue ;
			}
			do_hash_in(argv[i]);
		}
	}
}
