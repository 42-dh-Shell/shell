/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:04:27 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/09/28 19:03:22 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*allocate_token(int word_len)
{
	t_token	*result;

	result = malloc(sizeof(t_token));
	if (!result)
		exit(1);
	result->str = malloc(sizeof(char) * (word_len + 1));
	if (!result->str)
		exit(1);
	result->expand_info = 0;
	result->next = 0;
	result->wildcard_flag = 0;
	return (result);
}

t_expand_info	*allocate_expand_info(void)
{
	t_expand_info	*result;

	result = malloc(sizeof(t_expand_info));
	if (!result)
		exit(1);
	result->next = 0;
	result->split_arg = 0;
	return (result);
}
