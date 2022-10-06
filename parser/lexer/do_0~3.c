/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_0~3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:32:34 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/28 22:30:37 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	do_s0(t_auto_data *data)
{
	data->prev_state = data->next_state;
	if (get_char_status(*(data->str)) == WORD)
		change_next_state(data, L_S1);
	else if (get_char_status(*(data->str)) == DOUBLE_QUOTE)
		change_next_state(data, L_S2);
	else if (get_char_status(*(data->str)) == SINGLE_QUOTE)
		change_next_state(data, L_S3);
	else if (get_char_status(*(data->str)) == EXPANSION)
		change_next_state(data, L_S1);
	else if (get_char_status(*(data->str)) == RIGHT_ARROW)
		change_next_state(data, L_S5);
	else if (get_char_status(*(data->str)) == LEFT_ARROW)
		change_next_state(data, L_S7);
	else
		do_s0_v2(data);
}

void	do_s0_v2(t_auto_data *data)
{
	if (get_char_status(*(data->str)) == RIGHT_BRAKIT)
		change_next_state(data, L_S9);
	else if (get_char_status(*(data->str)) == LEFT_BRAKIT)
		change_next_state(data, L_S10);
	else if (get_char_status(*(data->str)) == BIT_AND)
		change_next_state(data, L_S11);
	else if (get_char_status(*(data->str)) == BIT_OR)
		change_next_state(data, L_S14);
	else if (get_char_status(*(data->str)) == IS_SPACE)
		change_next_state(data, L_S16);
	else
		change_next_state(data, L_S13);
}

void	do_s1(t_auto_data *data)
{	
	data->prev_state = L_S1;
	if (get_char_status(*(data->str)) == WORD)
	{
		if (*(data->str) == '*')
			data->flag_wild = 1;
		fill_buffer(data);
	}
	if (get_char_status(*(data->str)) == WORD)
		change_next_state(data, L_S1);
	else if (get_char_status(*(data->str)) == DOUBLE_QUOTE)
		change_next_state(data, L_S2);
	else if (get_char_status(*(data->str)) == SINGLE_QUOTE)
		change_next_state(data, L_S3);
	else if (get_char_status(*(data->str)) == EXPANSION)
		change_next_state(data, L_S4);
	else
		change_next_state(data, L_S17);
}

void	do_s2(t_auto_data *data)
{
	if (get_char_status(*(data->str)) == DOUBLE_QUOTE \
	&& data->prev_state != L_S4)
		(data->str)++;
	data->prev_state = data->next_state;
	if (ft_strnstr(data->str, "\"", ft_strlen(data->str)) == NULL \
	&& change_next_state(data, L_S13))
		return ;
	while (get_char_status(*(data->str)) != DOUBLE_QUOTE)
	{
		if (get_char_status(*(data->str)) == EXPANSION && \
		change_next_state(data, L_S4))
			return ;
		fill_buffer(data);
	}
	(data->str)++;
	data->next_state = L_S1;
}

void	do_s3(t_auto_data *data)
{
	data->prev_state = data->next_state;
	(data->str)++;
	if (ft_strnstr(data->str, "\'", ft_strlen(data->str)) == NULL && \
	change_next_state(data, L_S13))
		return ;
	while (get_char_status(*(data->str)) != SINGLE_QUOTE)
		fill_buffer(data);
	(data->str)++;
	change_next_state(data, L_S1);
}
