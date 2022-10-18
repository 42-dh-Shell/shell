/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:51:53 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/18 16:40:17 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../parser/parser.h"

void	validation_ex_info(t_token	*token)
{
	t_expand_info	*expand_info;
	char			*str;

	expand_info = token->expand_info;
	while (expand_info)
	{
		if (expand_info->str[1] != '_' && !ft_isalpha(expand_info->str[1]))
		{
			str = ft_calloc(sizeof(char), 2);
			if (!str)
				ft_exit("malloc error\n", 1);
			str[0] = '$';
			str[1] = '\0';
			free(expand_info->str);
			expand_info->str = str;
			expand_info->size = -1;
		}
		expand_info = expand_info->next;
	}
}
