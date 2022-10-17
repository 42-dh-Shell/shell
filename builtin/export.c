/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:36:51 by idaegyu           #+#    #+#             */
/*   Updated: 2022/10/18 01:17:36 by daegulee         ###   ########.fr       */
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
			argv[++j] = ft_strdup(cur->key);
			cur = cur->next;
		}
	}
	argv[++j] = NULL;
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
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	do_export(char *str, int *result)
{
	char	*key;
	char	*value;

	if (!is_id(str))
	{
		printf("minishell: export:  \'%s\': not a valid identifier\n", str);
		*result = 1;
		return ;
	}
	key = get_key(str);
	value = get_value(str);
	if (get_hash(g_shell->h_table, key) != NULL)
	{
		if (ft_strcmp(value, "") != 0)
			hash_add(g_shell->h_table, key, value);
		return ;
	}
	hash_add(g_shell->h_table, key, value);
}

int	mini_export(char **argv)
{
	int	argc;
	int	result;
	int	i;

	argc = argv_len(argv);
	result = 0;
	if (argc <= 1)
		return (print_export());
	else
	{
		i = 0;
		while (argv[++i])
			do_export(argv[i], &result);
	}
	system("leaks mini");
	return (result);
}
