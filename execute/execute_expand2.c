/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_expand2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:36:23 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/11/07 16:14:05 by daegulee         ###   ########.fr       */
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

char	*get_expand_value(t_expand_info *expand_info)
{
	char	*key;
	char	*value;

	key = ft_substr(expand_info->str, 1, expand_info->size - 1);
	if (ft_strcmp(key, "?") == 0)
		value = ft_itoa(g_shell->exit_status);
	else
		value = get_hash(g_shell->h_table, key);
	free(key);
	return (value);
}

void	release_value(t_expand_info *expand_info, int *size)
{
	char	*value;

	value = get_expand_value(expand_info);
	if (value)
		(*size) += ft_strlen(value);
	if (ft_strcmp(expand_info->str, "$?") == 0)
		free(value);
}

int	expand_str_size(char *node_str, t_expand_info *expand_info, int size)
{
	int			i;
	const int	len = ft_strlen(node_str);

	i = 0;
	while (i < len && node_str[i])
	{
		if (node_str[i] == '$' && expand_info && expand_info->size != -1)
		{
			release_value(expand_info, &size);
			i += expand_info->size;
			expand_info = expand_info->next;
		}
		else
		{
			if (node_str[i] == '$' && expand_info && expand_info->size == -1 \
				&& expand_info->next != 0)
				expand_info = expand_info->next;
			size++;
			i++;
		}
	}
	return (size);
}

char	**expand_str(char *node_str, t_expand_info *expand_info)
{
	char	*str;
	char	**argv;

	if (expand_info)
	{
		str = ft_calloc(sizeof(char), \
			expand_str_size(node_str, expand_info, 0) + 1);
	}
	else
		str = ft_calloc(sizeof(char), ft_strlen(node_str) + 1);
	if (!str)
		ft_exit("malloc error\n", 1);
	if (expand_info)
		get_expand_str(str, expand_info, node_str, 0);
	argv = get_argv(str, expand_info, node_str);
	free(str);
	return (argv);
}
