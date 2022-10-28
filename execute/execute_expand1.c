/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_expand1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:19:38 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/28 17:31:32 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	get_expand_str(char *str, t_expand_info *expand_info, \
	char *node_str, int i)
{
	char		*value;
	const int	len = ft_strlen(node_str);
	int			j;

	j = 0;
	while (j < len && node_str[j])
	{
		if (node_str[j] == '$' && expand_info && expand_info->size != -1)
		{
			value = get_expand_value(expand_info);
			j += expand_info->size;
			if (value)
				get_expd_str_help(str, expand_info, value, i);
			expand_info = expand_info->next;
			continue ;
		}
		if (node_str[j] == '$' && expand_info \
				&& expand_info->size == -1 && expand_info->next != 0)
			expand_info = expand_info->next;
		str[i++] = node_str[j];
		j++;
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
		if (expand_info->size != -1 && str[i] == ' ' && ex_start <= i \
			&& i < ex_end && expand_info->split_arg == 1)
		{
			cnt++;
			while (is_space(str[i]))
				i++;
		}
		else
			i++;
		if ((expand_info->size == -1 || i > ex_end) && \
			expand_info->next != NULL)
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
	result[0] = ft_strdup(node_str);
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
		result[0] = ft_strdup(str);
		return (result);
	}
	argv_expand(result, expand_info, str);
	return (result);
}
