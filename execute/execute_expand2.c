/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_expand2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:36:23 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/18 14:56:09 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	get_argv_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

int	expand_str_size(char *node_str, t_expand_info *expand_info)
{
	int		size;
	char	*key;
	char	*value;

	size = 0;
	while (*node_str)
	{
		if (*node_str == '$')
		{
			key = ft_substr(node_str, 1, expand_info->size - 1);
			value = get_hash(g_shell->h_table, key);
			free(key);
			if (value)
				size += ft_strlen(value);
			node_str += expand_info->size;
			expand_info = expand_info->next;
		}
		else
		{
			size++;
			node_str++;
		}
	}
	return (size);
}

char	**expand_str(char *node_str, t_expand_info *expand_info)
{
	char			*str;

	if (expand_info)
		str = ft_calloc(sizeof(char), \
			expand_str_size(node_str, expand_info) + 1);
	else
		str = ft_calloc(sizeof(char), ft_strlen(node_str) + 1);
	if (!str)
		ft_exit("malloc error\n", 1);
	if (expand_info)
		get_expand_str(str, expand_info, node_str, 0);
	return (get_argv(str, expand_info, node_str));
}
