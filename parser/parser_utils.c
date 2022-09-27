/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:09:02 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/09/27 20:18:28 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	closed_quote_dquote(int i, char **line, char quote_code)
{
	while ((*line)[i] != 0)
	{
		if ((*line)[i] == quote_code)
			return (1);
		i++;
	}
	return (0);
}

int	get_word_len(char **line)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while ((*line)[i] != 0 && !is_space((*line)[i]) && !is_meta((*line)[i]))
	{
		if ((*line)[i] != ASCII_DQUOTE && (*line)[i] != ASCII_QUOTE)
			cnt++;
		i++;
	}
	return (cnt);
}

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
