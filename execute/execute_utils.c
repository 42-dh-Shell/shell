/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:12:35 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/19 13:53:35 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	has_event(t_ast_node *head)
{
	while (head)
	{
		if (head->node_type == NODE_SUBSHELL || head->node_type == NODE_AND \
			|| head->node_type == NODE_OR || head->node_type == NODE_PIPE)
			return (1);
		head = head->left;
	}
	return (0);
}

int	is_valid_redir_filename(t_expand_info *expand_info)
{
	char	*key;
	char	*value;

	if (expand_info == 0)
		return (1);
	while (expand_info)
	{
		if (expand_info->split_arg == 1)
		{
			key = ft_substr(expand_info->str, expand_info->start + 1, \
				expand_info->size);
			value = get_hash(g_shell->h_table, key);
			if (value != NULL && get_argv_size(ft_split(value, ' ')) > 1)
			{
				printf("minishell: %s: ambiguous redirect\n", key);
				free(key);
				return (0);
			}
			free(key);
		}
		expand_info = expand_info->next;
	}
	return (1);
}

void	release_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
}

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

char	**get_command_info(t_ast_node *head)
{
	char		**argv;
	t_suffix	*suffix_list;

	argv = expand_str(head->str, head->expand_info);
	suffix_list = head->suffix_list;
	while (suffix_list)
	{
		argv = add_back_argv(argv, \
			expand_str(suffix_list->str, suffix_list->expand_info));
		suffix_list = suffix_list->next;
	}
	return (argv);
}
