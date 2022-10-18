/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 03:55:36 by daegulee          #+#    #+#             */
/*   Updated: 2022/10/18 13:59:29 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expand.h"
#include "../body/minishell.h"

extern	t_shell *g_shell;
//cat a$abc"b"

static char	**_result_general(char *str)
{
	char	**argv;

	argv = ft_malloc(sizeof(char *) * 2);
	argv[0] = ft_strdup(str);
	argv[1] = 0;
	return (argv);
}

char	**result_expand(char *str, t_expand_info *expand_info)
{
	t_expand_info	*cur;
	t_str_lst		*str_lst;
	t_string		*string;
	int				i;
	char			**split;

	cur = expand_info;
	str_lst = init_string_lst();
	while (cur)
	{
		i = 0;
		string = init_string(ft_substr(str, i, cur->start));
		if (cur->split_arg)
		{
			split = ft_split(++(cur->str), ' ');
			if (split != NULL)
				string->str = ft_strjoin(string->str, split[0]);
			push_strlst_string(str_lst, string);
			while (split[++i])
			{
				string = init_string(ft_strdup(split[i]));
				push_strlst_string(str_lst, string);
			}
		}
	}
	
}

char	**expand(char *str, t_expand_info *expand_info)
{
	t_str_lst		*str_lst;

	cur = expand_info;
	if (expand_info == NULL)
		return (_result_general(str));
}
