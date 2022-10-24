/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:43:37 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/24 18:53:35 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char	**add_back_argv(char **argv, char **new)
{
	int		i;
	int		new_size;
	int		argv_size;
	char	**new_argv;

	argv_size = 0;
	new_size = 0;
	while (argv[argv_size])
		argv_size++;
	while (new[new_size])
		new_size++;
	new_argv = ft_calloc(sizeof(char *), argv_size + new_size + 1);
	if (!new_argv)
		ft_exit("malloc error\n", 1);
	i = -1;
	while (++i < argv_size + new_size)
	{
		if (i < argv_size)
			new_argv[i] = argv[i];
		else
			new_argv[i] = new[i - argv_size];
	}
	free(argv);
	free(new);
	return (new_argv);
}

char	**get_wildcard_info(int wildcard_flag, char**argv)
{
	char	**result;
	int		i;

	if (!wildcard_flag)
		return (argv);
	result = NULL;
	if (wildcard_flag)
	{
		i = -1;
		while (argv[++i])
		{
			if (!result)
				result = wild_expand(argv[i]);
			else
				result = add_back_argv(result, wild_expand(argv[i]));
		}
	}
	return (result);
}

char	**get_command_info(t_ast_node *head)
{
	char		**argv;
	t_suffix	*suffix_list;
	char		**tmp;

	argv = NULL;
	argv = expand_str(head->str, head->expand_info);
	argv = get_wildcard_info(head->wildcard_flag, argv);
	suffix_list = head->suffix_list;
	while (suffix_list)
	{
		tmp = expand_str(suffix_list->str, suffix_list->expand_info);
		tmp = get_wildcard_info(suffix_list->wildcard_flag, tmp);
		argv = add_back_argv(argv, tmp);
		suffix_list = suffix_list->next;
	}
	return (argv);
}
