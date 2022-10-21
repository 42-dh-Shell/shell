/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:20:05 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/10/21 19:01:29 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*get_bracket_toekn(char **line)
{
	t_token	*result;

	result = ft_calloc(sizeof(t_token), 1);
	if (!result)
		ft_exit("malloc error\n", 1);
	if (**line == ASCII_LBRAK)
	{
		(*line)++;
		result->token_type = LBRAC;
	}
	else
	{
		(*line)++;
		result->token_type = RBRAC;
	}
	return (result);
}

t_token	*get_pipe_or_token(char **line)
{
	t_token	*result;

	if (**line == ASCII_PIPE)
	{
		(*line)++;
		result = allocate_token(2);
		result->token_type = OR;
		result->str[0] = '|';
		result->str[1] = '|';
		result->str[2] = 0;
	}
	else
	{
		result = allocate_token(1);
		result->token_type = PIPE;
		result->str[0] = '|';
		result->str[1] = 0;
	}
	return (result);
}

t_token	*get_great_dgreat_token(char **line)
{
	t_token	*result;

	if (**line == ASCII_GREAT)
	{
		(*line)++;
		result = allocate_token(2);
		result->token_type = DGREAT;
		result->str[0] = '>';
		result->str[1] = '>';
		result->str[2] = 0;
	}
	else
	{
		result = allocate_token(1);
		result->token_type = GREAT;
		result->str[0] = '>';
		result->str[1] = 0;
	}
	return (result);
}

t_token	*get_less_dless_token(char **line)
{
	t_token	*result;

	if (**line == ASCII_LESS)
	{
		(*line)++;
		result = allocate_token(2);
		result->token_type = DLESS;
		result->str[0] = '<';
		result->str[1] = '<';
		result->str[2] = 0;
	}
	else
	{
		result = allocate_token(1);
		result->token_type = LESS;
		result->str[0] = '<';
		result->str[1] = 0;
	}
	return (result);
}

t_token	*get_and_token(char **line)
{
	t_token	*result;

	if (**line == ASCII_AND)
	{
		(*line)++;
		result = allocate_token(2);
		result->token_type = AND;
		result->str[0] = '&';
		result->str[1] = '&';
		result->str[2] = 0;
	}
	else
	{
		ft_color_printf("minishell : unsupported token '&'\n");
		return (0);
	}
	return (result);
}
