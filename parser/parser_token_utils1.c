/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_token_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:20:05 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/09/27 15:12:17 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
		exit(1);
	return (result);
}

t_token	*meta_token_control(char **line)
{
	if (**line == ASCII_PIPE)
	{
		(*line)++;
		return (get_pipe_or_token(line));
	}
	else if (**line == ASCII_GREAT)
	{
		(*line)++;
		return (get_great_dgreat_token(line));
	}
	else if (**line == ASCII_LESS)
	{
		(*line)++;
		return (get_less_dless_token(line));
	}
	else
	{
		(*line)++;
		return (get_and_token(line));
	}
}
