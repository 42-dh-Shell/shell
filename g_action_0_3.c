/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_action_0_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:04:10 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/22 20:09:00 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

//white space -> s13
//alpha_digit -> s1
//" -> S2
//' ->S3
// | -> s4
// & -> s7
// ( -> S10
// ) -> s11 

void	do_s0(t_auto_data *data)
{
	if (is_alpha_digit(*(data->str)))
		data->state = L_S1;
	else if (*(data->str) == '\"')
		data->state = L_S2;
	else if (*(data->str) == '\'')
		data->state = L_S3;
	else if (*(data->str) == '|')
		data->state = L_S4;
	else if (*(data->str) == '&')
		data->state = L_S7;
	else if (*(data->str) == '(')
		data->state = L_S10;
	else
		do_s0_v2(data);
	// else if (*(data->str) == ')')
	// 	data->state = L_S11;
	// else if (is_space(*(data->str)))
	// 	data->state = L_S13;
	// else if (*(data->str) == '<')
	// 	data->state = L_S14;
	// else if (*(data->str) == '>')
	// 	data->state = L_S15;
	// else if (*(data->str) == '<<')
	// 	data->state = L_S16;
	// else if (*(data->str) == '>>')
	// 	data->state = L_S17;
	// else
	// 	data->state = L_S9;
}

void	do_s0_v2(t_auto_data *data)
{
	if (*(data->str) == ')')
		data->state = L_S11;
	else if (is_space(*(data->str)))
		data->state = L_S13;
	else if (*(data->str) == '<')
		data->state = L_S14;
	else if (*(data->str) == '>')
		data->state = L_S15;
	else if (*(data->str) == '<<')
		data->state = L_S16;
	else if (*(data->str) == '>>')
		data->state = L_S17;
	else
		data->state = L_S9;
}
void	do_s1(t_auto_data *data)
{
	if (is_alpha_digit(*data->str))
	{
		if (data->buffer_idx == WORD_SIZE_MAX)
		{
			data->state = L_S9;
			return ;
		}
		(data->buffer)[data->buffer_idx] = *(data->str);
		(data->buffer_idx)++;
		(data->str)++;
	}
	//똑같은거 들어오면 같같은  상태인거 스킵.
	if (*(data->str) == '\"')
		data->state = L_S2;
	else if (*(data->str) == '\'')
		data->state = L_S3;
	if (!(is_alpha_digit(*(data->str))) && *(data->str) != '\"' && \
	*(data->str) != '\'')
	{
		data->type = L_S1;
		data->state = L_S12;
	}
}

void	do_s2(t_auto_data *data)
{
	(data->str)++; // open "감기
	while (*(data->str) && *(data->str) != '\"')
	{
		if (data->buffer_idx == WORD_SIZE_MAX)
		{
			data->state = L_S9;
			return ;
		}
		(data->buffer)[data->buffer_idx] = *(data->str);
		(data->buffer_idx)++;
		(data->str)++;
	}
	if (!(*(data->str)))
	{
		data->state = L_S9;
		return ;
	}
	(data->str)++; //close "감기
	(data->state) = L_S1;
}

void	do_s3(t_auto_data *data)
{
	(data->str)++; // open '감기
	while (*(data->str) && *(data->str) != '\'')
	{
		if (data->buffer_idx == WORD_SIZE_MAX)
		{
			data->state = L_S9;
			return ;
		}
		(data->buffer)[data->buffer_idx] = *(data->str);
		(data->buffer_idx)++;
		(data->str)++;
	}
	if (!(*(data->str)))
	{
		data->state = L_S9;
		return ;
	}
	(data->str)++; //close '감기
	(data->state) = L_S1;
}
