/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_expand1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:19:38 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/18 14:34:04 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	get_expand_str(char *str, t_expand_info *expand_info, \
	char *node_str, int i)
{
	char	*value;

	while (*node_str)
	{
		if (*node_str == '$')
		{
			value = get_hash(g_shell->h_table, \
			ft_substr(node_str, 1, expand_info->size - 1));
			node_str += expand_info->size;
			if (value)
			{
				expand_info->start = ft_strlen(str);
				expand_info->size = ft_strlen(value);
				ft_strlcat (str + ft_strlen(str), value, ft_strlen(str) + \
					ft_strlen(value) + 1);
				i += ft_strlen(value);
			}
			expand_info = expand_info->next;
		}
		else
		{
			str[i++] = *node_str;
			node_str++;
		}
	}
}

int	get_expand_argv_size(char *str, t_expand_info *expand_info)
{
	int	i;
	int	ex_end;
	int	ex_start;
	int	cnt;

	i = 0;
	cnt = 1;
	while (str[i])
	{
		ex_start = expand_info->start;
		ex_end = expand_info->start + expand_info->size;
		if (str[i] == ' ' && ex_start <= i && i <= ex_end && \
			expand_info->split_arg == 1)
		{
			cnt++;
			while (is_space(str[i]))
				i++;
		}
		else
			i++;
		if (i > ex_end && expand_info->next != NULL)
			expand_info = expand_info->next;
	}
	return (cnt);
}

void	argv_expand(char **result, t_expand_info *expand_info, char *str)
{
	int	i;
	int	start;
	int	r_idx;

	i = 0;
	start = 0;
	r_idx = 0;
	while (str[i])
	{
		if (str[i] == ' ' && expand_info->split_arg == 1 && expand_info->start \
			<= i && i <= expand_info->start + expand_info->size)
		{
			result[r_idx++] = ft_substr(str, start, i - start);
			while (is_space(str[i]))
				i++;
			start = i;
		}
		else
			i++;
		if (i > expand_info->start + expand_info->size \
			&& expand_info->next != NULL)
			expand_info = expand_info->next;
	}
	result[r_idx] = ft_substr(str, start, i - start);
}

char	**argv_no_expand(char *node_str)
{
	char	**result;

	result = ft_calloc(sizeof (char *), 2);
	if (!result)
		ft_exit("malloc error\n", 1);
	result[0] = node_str;
	return (result);
}

char	**get_argv(char *str, t_expand_info *expand_info, char *node_str)
{
	char	**result;

	if (!expand_info)
		return (argv_no_expand(node_str));
	result = ft_calloc(sizeof(char *), \
		get_expand_argv_size(str, expand_info) + 1);
	if (*str == '\0')
	{
		result[0] = str;
		return (result);
	}
	argv_expand(result, expand_info, str);
	free(str);
	return (result);
}
