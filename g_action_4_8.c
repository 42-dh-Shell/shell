/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_action_4_8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:09:19 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/22 19:44:14 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	do_s4(t_auto_data *data)
{
	(data->str)++; // | 감기
	if (*(data->str) != '|')
		data->state = L_S5;
	else
		data->state = L_S6;
}

void	do_s5(t_auto_data *data)
{
	data->type = L_S5;
	data->state = L_S12;
}

void	do_s6(t_auto_data *data)
{
	(data->str)++; //| 감기
	data->type = L_S6;
	data->state = L_S12;
}

void	do_s7(t_auto_data *data)
{
	(data->str)++; // & 감기
	if (*(data->str) != '&')
		data->state = L_S9;
	else
		data->state = L_S8;
}

void	do_s8(t_auto_data *data)
{
	(data->str)++; // & 감기
	data->type = L_S8;
	data->state = L_S12;
}

// void	do_s9(t_auto_data *data)
// {
// 	if (data->buffer_idx == WORD_SIZE_MAX)
// 		printf("Line to long.\n");
// 	else
// 		printf("Tokenizing Error.\n");
// }
