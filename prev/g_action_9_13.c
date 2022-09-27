/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_action_9_13.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:23:13 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/26 18:56:51 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// void	do_s9(t_auto_data *data)
// {
// 	if (!(*(data->str)))
// 		printf("Syntax Error.\n");
// 	else if (data->buffer_idx == WORD_SIZE_MAX)
// 		printf("File Name Too long.\n");
// 	else
// 		printf("Tokenizing Error.\n");
// }
void	do_s9(t_auto_data *data)
{
	(data->str)++; // ) 감기
	data->prev_state = data->next_state;
	data->next_state = L_S17;
}

void	do_s10(t_auto_data *data)
{
	(data->str)++; // ( 감기
	data->prev_state = data->next_state;
	data->next_state = L_S17;
}

void	do_s11(t_auto_data *data)
{
	(data->str)++; // & 감기
	data->prev_state = data->next_state;
	if (get_char_status(*(data->str)) == BIT_AND)
		data->next_state = L_S12;
	else
		data->next_state = L_S13;
}

void	do_s12(t_auto_data *data)
{
	(data->str)++; // & 감기
	data->prev_state = data->next_state;
	data->next_state = L_S17;
}

void	do_s13(t_auto_data *data)
{
	if (data->prev_state == L_S1)
		ft_exit("syntax error.\n",1);
	else if (data->buffer_idx == WORD_SIZE_MAX)
		ft_exit("Too Long.\n", 2);
	else if (data->prev_state == L_S2 || \
	data->prev_state == L_S3)
	{
		ft_exit("Unclosed Quote!.\n", 2);
	}
}
