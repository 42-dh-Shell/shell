/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:51:53 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/11/07 11:42:45 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../parser/parser.h"

int	is_valid_expand_char(char ch, int i)
{
	return ((i == 1 && ch != '_' && !ft_isalpha(ch) && ch != '?') \
	|| (i != 1 && !ft_isalpha(ch) && !ft_isdigit(ch) && ch != '_'));
}

void	no_expand(t_expand_info	*expand_info)
{
	char	*str;

	str = ft_calloc(sizeof(char), 2);
	if (!str)
		ft_exit("malloc error\n", 1);
	str[0] = '$';
	str[1] = '\0';
	free(expand_info->str);
	expand_info->str = str;
	expand_info->size = -1;
}

void	status_expand_info(t_expand_info *expand_info)
{
	free(expand_info->str);
	expand_info->str = ft_strdup("$?");
	expand_info->size = 2;
	expand_info->start = 0;
}

void	validation_ex_info(t_token *token)
{
	t_expand_info	*expand_info;
	int				i;

	expand_info = token->expand_info;
	if (ft_strcmp(token->str, "$?") == 0)
	{
		status_expand_info(expand_info);
		return ;
	}
	while (expand_info)
	{
		i = 0;
		if (ft_strcmp(expand_info->str, "$") == 0)
			no_expand(expand_info);
		while (expand_info->str[++i])
		{
			if (is_valid_expand_char(expand_info->str[i], i))
			{
				no_expand(expand_info);
				break ;
			}
		}
		expand_info = expand_info->next;
	}
}
