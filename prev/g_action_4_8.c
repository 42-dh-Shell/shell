/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_action_4_8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:09:19 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/26 20:02:18 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	do_s4(t_auto_data *data)
{
	t_exps_info	*list;

	(data->str)++; // $ go
	//cur .
	init_exps_list(data, list);
	while (*(data->str) && get_char_status(*(data->str)) == WORD)
	{
		if (data->buffer_idx == WORD_SIZE_MAX)
		{
			data->next_state = L_S13;
			return ;
		}
		(data->buffer)[data->buffer_idx] = *(data->str);
		// cur로 관리해야됨 
		fill_exps_list(data, list);
		(data->buffer_idx)++;
		(data->str)++;
	}
	if (!(*(data->str)))
	{
		data->next_state = L_S13;
		return ;
	}
	data->next_state = data->prev_state;
}

void	do_s5(t_auto_data *data)
{
	(data->str)++; // > 감기
	data->prev_state = data->next_state;
	if (get_char_status(*(data->str)) == RIGHT_ARROW)
		data->next_state = L_S6;
	else
		data->next_state = L_S17;
}

void	do_s6(t_auto_data *data)
{
	(data->str)++; //> 감기
	data->prev_state = data->next_state;
	data->next_state = L_S17;
}

void	do_s7(t_auto_data *data)
{
	(data->str)++; // < 감기
	data->prev_state = data->next_state;
	if (get_char_status(*(data->str)) == LEFT_ARROW)
		data->next_state = L_S8;
	else
		data->next_state = L_S17;
}

void	do_s8(t_auto_data *data)
{
	(data->str)++; // > 감기
	data->prev_state = data->next_state;
	data->next_state = L_S17;
}

// void	do_s9(t_auto_data *data)
// {
// 	if (data->buffer_idx == WORD_SIZE_MAX)
// 		printf("Line to long.\n");
// 	else
// 		printf("Tokenizing Error.\n");
// }
