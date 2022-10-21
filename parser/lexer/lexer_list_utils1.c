/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:04:27 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/21 20:32:55 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*allocate_token(int word_len)
{
	t_token	*result;

	result = ft_calloc(sizeof(t_token), 1);
	if (!result)
		exit(1);
	result->str = ft_calloc(sizeof(char), (word_len + 1));
	if (!result->str)
		exit(1);
	result->token_type = WORD;
	return (result);
}

t_expand_info	*allocate_expand_info(void)
{
	t_expand_info	*result;

	result = ft_calloc(sizeof(t_expand_info), 1);
	if (!result)
		exit(1);
	result->next = 0;
	result->split_arg = 0;
	return (result);
}
