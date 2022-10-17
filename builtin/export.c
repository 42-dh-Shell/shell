/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:36:51 by idaegyu           #+#    #+#             */
/*   Updated: 2022/10/18 00:31:44 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../body/minishell.h"

extern t_shell *g_shell;

void	sort_print(char **argv)
{
	int	i;

	i = -1;
	argv_sort(argv);
	while (argv[++i])
	{
		printf("declare -x %s", argv[i]);
		if (ft_strcmp(get_hash(g_shell->h_table, argv[i]), "") != 0)
			printf("=\"%s\"", get_hash(g_shell->h_table, argv[i]));
		printf("\n");
		free(argv[i]);
	}
	free(argv);
}

int	print_export(void)
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
			argv[++j] = cur->key;
			cur = cur->next;
		}
	}
	argv[++j] = 0;
	sort_print(argv);
	return (1);
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
	// else
	// {
	// 	while (argv[++i])
	// 	{
	// 		if (!is_id(argv[i]))
	// 		{
	// 			print_invaild(argv[i]);
	// 			continue ;
	// 		}
	// 		do_hash_in(argv[i]);
	// 	}
	// }
	return (0);
}
